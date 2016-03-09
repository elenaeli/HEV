%function [engineTorque,motorTorque] = solvePareto(requiredTorque, FuelConsTable, GasEmisTable)
        requiredTorque = 385;
        
        engineSpeedRadPerS = 200;
        engineSpeedRadRPM = engineSpeedRadPerS*9.5492;
        SOC_deviation = 0.12;
        maxEngineTorque = 136;
        maxMotorTorque = 400;
        maxRPM = 6000;
        M = 14;
        N = 14;
        payoffMotor = zeros(M+1,N+1);
        payoffEngine = zeros(M+1,N+1);
        percentage = 0:(1/M):1;
        maxMotorTorqueStrategy = min([requiredTorque maxMotorTorque]);
        maxEngineTorqueStrategy = min([requiredTorque maxEngineTorque]);

        strategyEng = percentage .* maxEngineTorqueStrategy;
        strategyMot = percentage .* maxMotorTorqueStrategy;
        %strategyMot = fliplr(strategyMot);
        tmpTorque = repmat(strategyEng',1,M+1);

        totalTorque = zeros(M+1, N+1);
        for i = 1:M+1
            for j = 1:N+1
                totalTorque(i,j) = tmpTorque(i,j) + strategyMot(j);
            end
        end

        %engineMaxPower = 57000;
        %motorMaxPower = 50000;
        %motorSpeed = [0, 1200, 2000, 3000, 4000, 5000, 6000];
        %motorTorqueRef = [400, 400, 280, 222, 179, 143, 119];
        %engineSpeed = [0, 420, 900, 1380, 1860, 2340, 2820, 3300, 3780, 4260, 4740, 5220, 5700, 6000];
        %engineTorqueRef = [109, 117, 125, 131, 134, 136, 136, 133, 129, 123, 114, 104, 91, 83];
        
        tmpS = abs(FuelConsTable.speed - engineSpeedRadRPM);
        idxS = 0;
        [~, idxS ] = min(tmpS);

        % weights
        wFuel = 1;
        wPower = 0.4;
        wDrDem = 0.8;
        wSOC = 40;
        wNOX = 50;
        wCO = 30;
        wHC = 30;
       
        for i = 1:M+1
            for j = 1:N+1
                tmpT = abs(FuelConsTable.torque - strategyEng(j));
                idxT = 0;
                [~, idxT] = min(tmpT);      
                fuelConsumedGPS = FuelConsTable.lookupTableFuel(idxT, idxS);
                powerKW = FuelConsTable.lookupTablePower(idxT, idxS) ;
                HCEmissions = GasEmisTable.lookupTableHC(idxT, idxS);
                COEmissions = GasEmisTable.lookupTableCO(idxT, idxS);
                NOXEmissions = GasEmisTable.lookupTableNOX(idxT, idxS);               
                payoffEngine(i,j) = wFuel*fuelConsumedGPS + wPower*powerKW + wDrDem*abs(requiredTorque - totalTorque(i,j)) + wHC*HCEmissions + wCO*COEmissions + wNOX*NOXEmissions;
                payoffMotor(i,j) = 0.6*wFuel*fuelConsumedGPS + wDrDem*abs(requiredTorque - totalTorque(i,j)) + wSOC*SOC_deviation;                
                if i == 1 && j == 1
                    fu = wFuel*fuelConsumedGPS
                    po = wPower*powerKW
                    HC = wHC*HCEmissions
                    CO = wCO*COEmissions
                    NOX = wNOX*NOXEmissions
                    differenceTorque = abs(requiredTorque - totalTorque(i,j))
                    %payoffEngine(i,j)
                    %payoffMotor(i,j)
                end                
            end
        end
        %payoffMotor = payoffEngine';
        payoffBoth = reshape([payoffEngine;payoffMotor],size(payoffMotor,1),[]);         
        tic
        [paretoStrategies, paretoIndex, x, y] = paretoSet(payoffEngine, payoffMotor, requiredTorque);
        paretoStrategies
        paretoIndex
        toc
        motorTorquePareto = strategyMot(paretoStrategies(:,2));
        engineTorquePareto = strategyEng(paretoStrategies(:,1));
     
        %[sol, fval] = nashSolution(payoffEngine, payoffMotor, requiredTorque, paretoPayoffEng, paretoPayoffMot)
        stringRequiredTorque = int2str(requiredTorque);   
   
        p1 = plot(x,y,'ob');
        title(['Game payoffs, required torque = ', stringRequiredTorque, 'Nm'] );
        hold on
        payoffEngPareto = [];
        payoffMotPareto = [];
        for r = 1 : size(paretoStrategies,1)
            payoffEngPareto(1,r) = payoffEngine(paretoIndex(r,1), paretoIndex(r,2));
            payoffMotPareto(1,r) = payoffMotor(paretoIndex(r,1), paretoIndex(r,2));
            %text(M(paretoIndex(i,1), paretoIndex(i,2))+2, E(paretoIndex(i,1), paretoIndex(i,2)), 'Pareto optimum')  
            linearIndex = sub2ind([M+1 N+1], paretoIndex(r,2), paretoIndex(r,1));
            x(linearIndex)
            y(linearIndex)
            p2 = plot(x(linearIndex), y(linearIndex), 'og', 'MarkerFaceColor','g');   
            xlabel('Payoff Engine');
            ylabel('Payoff Motor');
            paretoStrategies(r,:) = [paretoIndex(r,1), paretoIndex(r,2)];       
        end       
        %p3 = plot(sol(size(sol,1)-1),sol(size(sol,1)),'og','MarkerFaceColor','g'); 
        payoffEngPareto
        payoffMotPareto
        
        nashEq = LemkeHowson(-payoffEngine, -payoffMotor, 12);      
        indE = find(nashEq{1,1});
        indM = find(nashEq{2,1});
        engineTorqueNash = strategyEng(indE);
        motorTorqueNash = strategyMot(indM);
        payoffEngNash = payoffEngine(indE, indM)       
        payoffMotNash = payoffMotor(indE, indM)
        
        payoffE = reshape(payoffEngine,15*15,1);
        payoffM = reshape(payoffMotor,15*15,1);        
        payoffB = horzcat(payoffE, payoffM);
        [A,payoffNPG,iterations,err] = npg([M+1 N+1],-payoffB);
        payoffEngNashNPG = -payoffNPG(1)
        payoffMotNashNPG = -payoffNPG(2)
        
        p4 = plot(payoffEngNash, payoffMotNash, 'om', 'MarkerFaceColor','m');   
        p5 = plot(payoffEngNashNPG, payoffMotNashNPG, 'oc', 'MarkerFaceColor','c');   

        legend([p1 p2 p4 p5], 'payoff', 'Pareto optimum payoff', 'Nash Equilibrium Lemke Howson', 'Nash Equilibrium NPG', 'Location','northwest');
        
        hold off
%end

