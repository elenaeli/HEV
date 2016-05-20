%function [engineTorque,motorTorque] = solvegame(requiredTorque, fuelConsumed, ...
%    SOC, FuelConsTable, GasEmisTable)
    requiredTorque = 85.46;        
    SOC = 100;
    fuelConsumed =8 ;
            
    requiredTorque = roundn(requiredTorque,0);     
        
    if previousReqTorque == requiredTorque
        engineTorque = previousEngTorque
        motorTorque = previousMotTorque
    else
        if requiredTorque > 0 && requiredTorque < 70 
        	requiredTorque = 70;
            engineTorque = 0
            motorTorque = 70
        elseif requiredTorque == 0          
            engineTorque = 0
            motorTorque = 0
        else
            close all    

            %engineMaxPower = 57000;
            %motorMaxPower = 50000;

            motorSpeedCurve = [0, 1200, 2000, 3000, 4000, 5000, 6000];
            motorTorqueCurve = [400 399 225 150 100 80 70];       
            engineSpeedCurve = [0, 420, 900, 1380, 1860, 2340, 2820, 3300, 3780, 4260, 4740, 5220, 5700, 6000];
            engineTorqueCurve = [109, 117, 125, 131, 134, 136, 136, 133, 129, 123, 114, 104, 91, 83];      

            SOC_deviation = abs(70 - SOC)/100;       
            maxEngineTorque = 136;
            maxMotorTorque = 400;
            minMotorTorque = -400;  
            minMotorTorqueRef = 0;
            minEngineTorqueRef = 83;
            minEngineTorque = 83;
            m = 7;
            e = 7;
            payoffMotor = zeros(m,e);
            payoffEngine = zeros(m,e);
            percentage = 0:(1/(m-1)):1;
           
            if requiredTorque < 0
                maxMotorTorqueStrategy = 0;
                maxEngineTorqueStrategy = 0;
                minEngineTorqueStrategy = max(minEngineTorque, requiredTorque); 
                minMotorTorqueStrategy = max(minMotorTorque, requiredTorque);  
                strategyMot = linspace(minMotorTorqueStrategy, maxMotorTorqueStrategy, m);
                strategyEng = linspace(minEngineTorqueStrategy, maxEngineTorqueStrategy,e);
            else
                minEngineTorqueStrategy = 0;
                minMotorTorqueStrategy = 0;
                maxEngineTorqueStrategy = min([requiredTorque maxEngineTorque]);
                maxMotorTorqueStrategy = min([requiredTorque maxMotorTorque]);    
                if minMotorTorqueRef > maxMotorTorqueStrategy
                    strategyMot = zeros(1,m);
                else
                    strategyMot = linspace(minMotorTorqueRef, maxMotorTorqueStrategy, m);
                end
                if minEngineTorqueRef > maxEngineTorqueStrategy
                    strategyEng = zeros(1,e);
                else
                    strategyEng = linspace(minEngineTorqueRef, maxEngineTorqueStrategy,e);
                end
            end   
        
            tmpTorque = repmat(strategyEng',1,m);
            totalTorque = zeros(m, e);
            for i = 1:m
                for j = 1:e
                    totalTorque(i,j) = tmpTorque(i,j) + strategyMot(j);
                end
            end      

            % weights     
            wFuel = 3;
            wPower = 0.5;  
            wTank = 0.5;
            wDrDem = 0.5;
            wSOC = 100;
            wNOX = 65;
            wCO = 25;
            wHC = 45;

            for i = 1:m
                for j = 1:e
                    tmpT = abs(FuelConsTable.torque - strategyEng(j));
                    idxT = 0;                    
                    % Power(W) = Torque (N.m) x Speed (RPM) / 9.5488
                    % divide by 1000 for kW               
                    motorSpeedRef(j) = interp1(motorTorqueCurve, motorSpeedCurve, abs(strategyMot(j)),'linear','extrap');
                    powerMotorKW(j) = abs(strategyMot(j)) * motorSpeedRef(j) / 9.5488 / 1000;       
                    tmpS = abs(FuelConsTable.speed - motorSpeedRef(j));
                    idxS = 0;
                    [~, idxS] = min(tmpS);
                    [~, idxT] = min(tmpT);    

                    fuelConsumedGPS = FuelConsTable.lookupTableFuel(idxT, idxS);
                    HCEmissions = GasEmisTable.lookupTableHC(idxT, idxS);
                    COEmissions = GasEmisTable.lookupTableCO(idxT, idxS);
                    NOXEmissions = GasEmisTable.lookupTableNOX(idxT, idxS);   
                    torqueDeviation(i,j) = requiredTorque - totalTorque(i,j);             

                    payoffEngine(i,j) = wFuel*fuelConsumedGPS + wDrDem*abs(torqueDeviation(i,j)) + ...
                        wHC*HCEmissions + wCO*COEmissions + wNOX*NOXEmissions + ...
                        wTank*fuelConsumed;
                    payoffMotor(i,j) = wDrDem*abs(torqueDeviation(i,j)) + wPower*powerMotorKW(j) + ...
                        wSOC*SOC_deviation;

                    fuel(j,1) = fuelConsumedGPS;
                    nox(j,1) = NOXEmissions;
                    power(j,1) = powerMotorKW(j);                                
                end
            end

            %figure
            %[A,b] = prtp(payoffBoth)     
            %payoffEngPareto
            %payoffMotPareto
            %plot(A(:,1), A(:,2), 'ob', 'MarkerSize',6);
            %hold on
            %B = paretofront(payoffBoth);
            %indP = find(B);

            tic
            [paretoStrategies, paretoIndex, x, y] = paretoset(payoffEngine, payoffMotor);                
            toc
            payoffE = reshape(payoffEngine,(m)*(e),1);
            payoffM = reshape(payoffMotor,(m)*(e),1);        
            payoffBoth = horzcat(payoffE, payoffM);   

            engineTorquePareto = strategyEng(paretoIndex(:,1));
            motorTorquePareto = strategyMot(paretoIndex(:,2));     
            stringRequiredTorque = int2str(requiredTorque);   

            figure
            p1 = plot(x,y,'ob');
            title(['Game payoffs, required torque = ', stringRequiredTorque, 'Nm'] );
            hold on
            [ bestPayoffEngPareto, bestPayoffMotPareto ] = bestpareto( paretoStrategies, paretoIndex, ...
            torqueDeviation, fuel, nox, power )
            bestPayoffEngPareto
            bestPayoffMotPareto        

            numStratBoth = m+e;  
            %[nashEq1Pl1, nashEq1Pl2] = LemkeHowson(-payoffEngine, -payoffMotor);  
            %[nashEq14Pl1, nashEq14Pl2] = LemkeHowson(-payoffEngine, -payoffMotor, ceil(1/4*numStratBoth));  
            %[nashEq12Pl1, nashEq12Pl2] = LemkeHowson(-payoffEngine, -payoffMotor, ceil(1/2*numStratBoth));          
            [nashEqPl1, nashEqPl2]  = LemkeHowson(-payoffEngine, -payoffMotor, ceil(1/2*numStratBoth));                     
            payoffEngNash = payoffEngine(nashEqPl1==1, nashEqPl2==1);
            payoffMotNash = payoffMotor(nashEqPl1==1, nashEqPl2==1);
            %bestPayoffEngNashLH(1) = payoffEngine(nashEq1Pl1==1, nashEq1Pl2==1);
            %bestPayoffEngNashLH(2) = payoffEngine(nashEq12Pl1==1, nashEq12Pl2==1);
            %bestPayoffEngNashLH(3) = payoffEngine(nashEq34Pl1==1, nashEq34Pl2==1);
            %%bestPayoffMotNashLH(1) = payoffMotor(nashEq1Pl1==1, nashEq1Pl2==1);
            %bestPayoffMotNashLH(2) = payoffMotor(nashEq12Pl1==1, nashEq12Pl2==1);
            %bestPayoffMotNashLH(3) = payoffMotor(nashEq34Pl1==1, nashEq34Pl2==1);
            [~, indM] = min(payoffEngNash);

            nashIndEng = find(nashEqPl1==1);
            nashIndMot = find(nashEqPl2==1);

            conflictPoint = sub2ind([m e], nashIndEng, nashIndMot)

            [A, payoffNPG, iterations, err] = npg([m e], -payoffBoth);
            payoffEngNashNPG = -payoffNPG(1)
            payoffMotNashNPG = -payoffNPG(2)

            [~, indNP] = nashsolution(payoffBoth, conflictPoint);
            payoffEngNashSol = payoffBoth(indNP,1)
            payoffMotNashSol = payoffBoth(indNP,2)        
            paretoStrInd = horzcat(paretoStrategies, paretoIndex); 

            [ks, linePareto] = kalaismorodinskysolution(payoffBoth, conflictPoint, paretoStrategies, paretoStrInd);
            percentReqTorq = linspace(0, requiredTorque, 10);
            if ~isempty(linePareto)
                if linePareto(2,1) - linePareto(1,1) ~=0 && linePareto(1,2) - linePareto(2,2) ~= 0
                    probKsMixed(1) = (ks(1,1) - linePareto(1,1)) / (linePareto(2,1) - linePareto(1,1));
                    probKsMixed(2) = (ks(1,2) - min(linePareto(:,2))) / (linePareto(1,2) - linePareto(2,2));
                elseif linePareto(2,1) - linePareto(1,1) ==0
                    probKsMixed(2) = (ks(1,2) - min(linePareto(:,2))) / (linePareto(1,2) - linePareto(2,2));
                    probKsMixed(1) = 1 - probKsMixed(2);
                elseif linePareto(1,2) - linePareto(2,2) == 0
                    probKsMixed(1) = (ks(1,1) - linePareto(1,1)) / (linePareto(2,1) - linePareto(1,1));
                    probKsMixed(2) = 1 - probKsMixed(1);
                end
                probKsMixed
                %probKsMixed(1) = ks(1,1) / linePareto(2,1);
                %probKsMixed(2) = ks(1,2) / linePareto(1,2);
                ksMixed(1) = linePareto(1,1) + probKsMixed(1)*(linePareto(2,1) - linePareto(1,1));
                ksMixed(2) = min(linePareto(:,2)) + probKsMixed(2)*abs(linePareto(1,2) - linePareto(2,2));
                %ksMixed(1) = probKsMixed(1)*linePareto(2,1);
                %ksMixed(2) = probKsMixed(2)*linePareto(1,2);
                probKsMixed
                ksMixed
                mixedEngineTorque = min(strategyEng(linePareto(1,3)),strategyEng(linePareto(2,3))) + ...
                    probKsMixed(1)*abs(strategyEng(linePareto(1,3))-strategyEng(linePareto(2,3)))
                mixedMotorTorque = min(strategyMot(linePareto(1,4)),strategyMot(linePareto(2,4))) + ...
                    probKsMixed(1)*abs(strategyMot(linePareto(1,4))-strategyMot(linePareto(2,4)))       
            end

            %sum(probKsMixed)
            payoffCoalCoef = ones(m,e);
            payoffCoalCoef(m:m-1:end-1) = 0.5;

            [ payoffWholeCoal, coeffCoal, payoffEngineCoal, payoffMotorCoal, payoffWholeCoalBefore ] = ...
                coalitionpayoffs(payoffMotor, payoffEngine, torqueDeviation, percentReqTorq);

            indCoal = (coeffCoal == 0.99 | coeffCoal == 0.991);
            indCoalition = +indCoal;
            indCoalition(indCoal == true) = 0.98;
            indCoalition(indCoal == false) = 1;
            payoffWholeCoal1 = payoffWholeCoal .* indCoalition;

            payoffMotCoalVec = reshape(payoffMotorCoal,(m)*(e),1);
            payoffEngCoalVec = reshape(payoffEngineCoal,(m)*(e),1);

            % get all undominated strategies (pareto optimality)
            [undomImp, undomImpInd] = checkimputation(payoffBoth, ...
                paretoStrategies, payoffMotCoalVec, payoffEngCoalVec, payoffWholeCoal);        
            imputM = zeros(1,size(undomImpInd,2));
            imputE = zeros(1,size(undomImpInd,2));
            for i = 1 : size(undomImpInd,2)             
                if all(undomImp(i,1) <= payoffEngine(m,:))
                    imputM(1,i) = undomImpInd(i);
                end                
                if all(undomImp(i,2) <= payoffMotor(:,e))
                    imputE(1,i) = undomImpInd(i);
                end
            end

            imput = undomImpInd;
            imput(imput==0) = [];

            payoffImput = zeros(size(imput,1),3);
            for i = 1 : size(imput,1)
                payoffImput(i,1) = payoffBoth(imput(i),1);
                payoffImput(i,2) = payoffBoth(imput(i),2);       
                [r, c] = ind2sub(size(payoffWholeCoal), imput(i));
                payoffImput(i,3) = payoffWholeCoal(r,c);
            end

            tic
            coreSol = core(payoffImput);
            indCore = find(coreSol);
            toc        

            [Xengine, X2, A1, b1, v1] = mixedstrategies(payoffEngine,1);
            [Xmotor, X1, A2, b2, v2] = mixedstrategies(payoffMotor,2);

            if  ~isempty(A1) && ~isempty(A2) && ~isempty(b1) && ~isempty(b2)
                mixedStrEng = find(abs(Xengine-0)>0.001);
                mixedStrMot = find(abs(Xmotor-0)>0.001);           
                payoffProbMixedStrEng = zeros(size(mixedStrEng,1),2);
                payoffProbMixedStrMot = zeros(size(mixedStrMot,1),2);
                payoffStrEng = 0;
                for i = 1 : size(mixedStrEng,1)        
                    payoffProbMixedStrEng(i,1) = payoffEngine(mixedStrEng(i));
                    payoffProbMixedStrEng(i,2) = Xengine(mixedStrEng(i));
                    payoffStrEng = payoffStrEng + payoffEngine(mixedStrEng(i))*Xengine(mixedStrEng(i));
                end

                payoffStrMot = 0;
                for j = 1 : size(mixedStrMot,1)
                    payoffProbMixedStrMot(j,1) = payoffMotor(mixedStrMot(j));
                    payoffProbMixedStrMot(j,2) = Xmotor(mixedStrMot(j));    
                    payoffStrMot = payoffStrMot + payoffMotor(mixedStrMot(j))*Xmotor(mixedStrMot(j));
                end         
            else
                pureStrEng = find(Xengine);
                pureStrMot = find(X2);    
                payoffStrEng = payoffEngine(pureStrEng, pureStrMot);
                payoffStrMot = payoffMotor(pureStrEng, pureStrMot);           
            end
            m1 = min(payoffBoth(:,1));
            m2 = min(payoffBoth(:,2));        

            v12 = min(min(payoffWholeCoalBefore));
            [ shEngine, shMotor ] = shapleyvalue(v12, v1, v2)    
            if ~ismembertol([shEngine, shMotor],payoffBoth,0.001,'ByRows',true)            
                IDX = knnsearch(payoffBoth,[shEngine shMotor],'K', 2);
                [idr1, idc1] = ind2sub(size(payoffEngine), IDX(1));        
                [idr2, idc2] = ind2sub(size(payoffEngine), IDX(2));
                nearestSh1 = [idr1 idc1];
                nearestSh2 = [idr2 idc2];
                payoffNearestSh1 = [payoffEngine(idr1,idc1) payoffMotor(idr1,idc1)]
                payoffNearestSh2 = [payoffEngine(idr2,idc2) payoffMotor(idr2,idc2)]
                if payoffNearestSh1(1) ~= payoffNearestSh2(1)
                    j = 1;
                    shapley = shEngine;
                else
                    j = 2;
                    shapley = shMotor;
                end
                if payoffNearestSh2(j) < shapley &&  ...
                    shapley < payoffNearestSh1(j)
                    probNearSh2 = (shapley - payoffNearestSh2(j)) / ...
                        (payoffNearestSh1(j) - payoffNearestSh2(j));
                    probNearSh1 = 1 - probNearSh2;
                elseif payoffNearestSh1(j) < shapley && ...                    
                    shapley < payoffNearestSh2(j)
                    probNearSh1 = (shapley - payoffNearestSh1(j)) / ...
                        (payoffNearestSh2(j) - payoffNearestSh1(j));
                    probNearSh2 = 1 - probNearSh1;
                elseif shapley < payoffNearestSh1(j) &&  ...
                    shapley < payoffNearestSh2(j)            
                    if payoffNearestSh1(j) < payoffNearestSh2(j)
                        probNearSh1 = shapley / payoffNearestSh1(j);
                        probNearSh2 = 0;
                    elseif payoffNearestSh2(j) < payoffNearestSh1(j)
                        probNearSh2 = shapley / payoffNearestSh2(j);
                        probNearSh1 = 0;
                    end
                end
                probNearSh1
                probNearSh2
                shapleyEngineTorque = probNearSh1*strategyEng(idr1) + probNearSh2*strategyEng(idr2);
                shapleyMotorTorque = probNearSh1*strategyMot(idc1) + probNearSh2*strategyMot(idc2);
            else
                 [~, ind] = ismembertol([shEngine, shMotor],payoffBoth,0.001,'ByRows',true);        
                 [idr1, idc1] = ind2sub(size(payoffEngine), ind);   
                 shapleyEngineTorque = strategyEng(idr1);
                 shapleyMotorTorque = strategyMot(idc1);
            end

            shapleyEngineTorque
            shapleyMotorTorque
            lightpurple = [163 154 255] ./ 255;        
            p10 = plot(payoffStrEng, payoffStrMot, 'o',...
                'MarkerFaceColor', lightpurple, 'MarkerEdgeColor', lightpurple, ...
                'MarkerSize', 14);

            limegreen = [194 242 1] ./ 255;
            p3 = plot(bestPayoffEngPareto, bestPayoffMotPareto, 'og', ...
                'MarkerFaceColor', 'g', 'MarkerSize', 13);    
            %p5 = plot(payoffEngNashNPG, payoffMotNashNPG, 'o', ...
            %    'MarkerFaceColor','m', 'MarkerEdgeColor', 'm',...
            %    'MarkerSize', 13);    
            p4 = plot(payoffEngNash, payoffMotNash, 'oy', ...
                'MarkerFaceColor', 'y', 'MarkerSize', 11);     
            %p41 = plot(bestPayoffEngNashLH(1), bestPayoffMotNashLH(1), 'oc', ...
            %    'MarkerFaceColor', 'c', 'MarkerSize', 9);      
            %p42 = plot(bestPayoffEngNashLH(2), bestPayoffMotNashLH(2), 'o', ...
            %    'MarkerFaceColor', 'r', 'MarkerEdgeColor','r','MarkerSize', 7);     
            %p43 = plot(bestPayoffEngNashLH(3), bestPayoffMotNashLH(3), 'o', ...
            %    'MarkerFaceColor', limegreen,'MarkerEdgeColor', limegreen, 'MarkerSize', 5);         
            %p6 = plot(payoffEngNashSol, payoffMotNashSol,'or', ...
            %    'MarkerFaceColor',[1,0.6,0] , 'MarkerEdgeColor', [1,0.6,0] ,...
            %    'MarkerSize', 9);

            purple = [118 31 133] ./ 255;        
            p7 = plot(ks(1,1), ks(1,2), 'o', 'MarkerFaceColor', purple, ...
                'MarkerEdgeColor', purple, 'MarkerSize', 10);
            pink = [254 164 191] ./ 255;       
            p8 = plot(payoffBoth(imput(indCore),1), payoffBoth(imput(indCore),2), 'o', ...
                'MarkerFaceColor',pink, 'MarkerEdgeColor',pink,...
                'MarkerSize', 8);      

            p9 = plot(shEngine, shMotor, 'o', 'MarkerFaceColor', limegreen, ...
                'MarkerEdgeColor', limegreen, 'MarkerSize', 7);

            for r = 1 : size(paretoIndex,1)
                linearIndex = sub2ind([m e], paretoIndex(r,2), paretoIndex(r,1));           
                p2 = plot(x(linearIndex), y(linearIndex), 'o', ...
                    'MarkerEdgeColor', [0,0.5,0], 'MarkerFaceColor',[0,0.5,0],...
                    'MarkerSize',6);
            end

            darkred = [185 16 20] ./ 255;
            %pi = plot(m1, m2, 'o', 'MarkerSize', 4, 'MarkerFaceColor',darkred ,...
            %'MarkerEdgeColor', darkred);

            legend([p1 p2 p3 p4 p7 p8 p9 p10], 'Payoff', ...         
            'Pareto optimal payoff', ...  
            'Best Pareto payoff', ... 
            'Nash Equilibrium Lemke-Howson (conflict point)', ... 
            'Kalai-Smorodinsky Solution', ...
            'Core', ...        
            'Shapley value', ...
            'Mixed Strategies', ...
            'Location', 'northwest');       

            %'Ideal point', ...       
            %'Nash Equilibrium Lemke-Howson k0=1', ...
            %'Nash Equilibrium Lemke-Howson k0=8', ...     
            %'Nash Equilibrium Lemke-Howson k0=15' , ... 
            %'Nash Equilibrium Lemke-Howson k0=23' , ...          
            %'Nash Equilibrium NPG', ...       

            xlabel('Payoff Engine');
            ylabel('Payoff Motor');
            hold off

            [ engineTorque, motorTorque ] = payofftotorque(bestPayoffEngPareto, ...
                bestPayoffMotPareto, payoffBoth, strategyEng, strategyMot)
            previousReqTorque = requiredTorque;
            previousEngTorque = engineTorque;
            previousMotTorque = motorTorque;
       
        end
    end
%end