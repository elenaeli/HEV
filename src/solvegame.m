%function [engineTorque,motorTorque] = solvegame(requiredTorque, FuelConsTable, GasEmisTable)
        requiredTorque = 81; 
       
        close all
        engineSpeedRadPerS = 200;
        engineSpeedRadRPM = engineSpeedRadPerS*9.5492;
        SOC_deviation = 0.25;
        maxEngineTorque = 136;
        maxMotorTorque = 400;
        maxRPM = 6000;
        m = 15;
        e = 15;
        payoffMotor = zeros(m,e);
        payoffEngine = zeros(m,e);
        percentage = 0:(1/(m-1)):1;
        maxEngineTorqueStrategy = min([requiredTorque maxEngineTorque]);
        maxMotorTorqueStrategy = min([requiredTorque maxMotorTorque]);

        strategyEng = percentage .* maxEngineTorqueStrategy;
        strategyMot = percentage .* maxMotorTorqueStrategy;
        tmpTorque = repmat(strategyEng',1,m);

        totalTorque = zeros(m, e);
        for i = 1:m
            for j = 1:e
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
        wFuel = 3;
        wPower = 0.4;     
        wDrDem = 0.5;
        wSOC = 100;
        wNOX = 65;
        wCO = 25;
        wHC = 45;
       
        for i = 1:m
            for j = 1:e
                tmpT = abs(FuelConsTable.torque - strategyEng(j));
                idxT = 0;
                [~, idxT] = min(tmpT);      
                fuelConsumedGPS = FuelConsTable.lookupTableFuel(idxT, idxS);
                powerKW = FuelConsTable.lookupTablePower(idxT, idxS) ;
                HCEmissions = GasEmisTable.lookupTableHC(idxT, idxS);
                COEmissions = GasEmisTable.lookupTableCO(idxT, idxS);
                NOXEmissions = GasEmisTable.lookupTableNOX(idxT, idxS);   
                torqueDeviation(i,j) = requiredTorque - totalTorque(i,j);
                payoffEngine(i,j) = wFuel*fuelConsumedGPS + wDrDem*abs(torqueDeviation(i,j)) + wHC*HCEmissions + wCO*COEmissions + wNOX*NOXEmissions + wSOC*SOC_deviation;
                payoffMotor(i,j) = 0.5*wFuel*fuelConsumedGPS + wDrDem*abs(torqueDeviation(i,j)) + wHC*HCEmissions + wCO*COEmissions + wNOX*NOXEmissions + wSOC*SOC_deviation;                
                fuel(j,1) = fuelConsumedGPS;
                nox(j,1) = NOXEmissions;
                %if i == 12 && j == 5
                %    fu = wFuel*fuelConsumedGPS
                %    po = wPower*powerKW
                %    HC = wHC*HCEmissions
                %    CO = wCO*COEmissions
                %    NOX = wNOX*NOXEmissions
                %    wDrDem*abs(torqueDeviation(i,j))                
                %end                
            end
        end
        %payoffMotor = payoffEngine';
        %payoffBoth = reshape([payoffEngine;payoffMotor],size(payoffMotor,1),[]);         
        
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
        payoffEngPareto = zeros(1,size(paretoIndex,1));
        payoffMotPareto = zeros(1,size(paretoIndex,1));
        torqueDeviationPareto = zeros(1,size(paretoIndex,1));
        fuelPareto = [];
        noxPareto = [];
        for r = 1 : size(paretoIndex,1)
            payoffEngPareto(1,r) = paretoStrategies(r,1);
            payoffMotPareto(1,r) = paretoStrategies(r,2);
            torqueDeviationPareto(1,r) = torqueDeviation(paretoIndex(r,1), paretoIndex(r,2));
            fuelPareto(1,r) = fuel(paretoIndex(r,1),1);
            noxPareto(1,r) = nox(paretoIndex(r,1),1);
        end
        
        payoffEngPareto
        payoffMotPareto        
        bestTorqDevPareto = min(abs(torqueDeviationPareto))
        
        % check if more than 1 points have same torque deviation
        indT = find(abs(torqueDeviationPareto)==bestTorqDevPareto)       
        if size(indT,2) > 1
            % take the point with minimum fuel consumption
            bestFuelPareto = min(fuelPareto);
            % check if more than 1 points have same fuel consumption
            indF = find(fuelPareto==bestFuelPareto)
            bestPayoffFuelPareto = paretoStrategies(indF,:)
            if size(indF,2) > 1
                % take the point with the minimum engine payoff
                [~,indE] = min(bestPayoffFuelPareto(:,1))
                bestPayoffEngPareto = bestPayoffFuelPareto(indE,1); 
                bestPayoffMotPareto = bestPayoffFuelPareto(indE,2);
            else
                bestPayoffEngPareto = bestPayoffFuelPareto(1,1);   
                bestPayoffMotPareto = bestPayoffFuelPareto(1,2);
            end
        else
            bestPayoffEngPareto = paretoStrategies(indT,1);
            bestPayoffMotPareto = paretoStrategies(indT,2);
        end    
        bestPayoffEngPareto
        bestPayoffMotPareto        

        numStratBoth = m+e;        
        nashEq34 = LemkeHowson(-payoffEngine, -payoffMotor, ceil(3/4*numStratBoth));                     
        payoffEngNash = payoffEngine(nashEq34{1,1}==1, nashEq34{2,1}==1);
        payoffMotNash = payoffMotor(nashEq34{1,1}==1, nashEq34{2,1}==1);
        [~, indM] = min(payoffEngNash);
        
        nashIndEng = find(nashEq34{1,1}==1);
        nashIndMot = find(nashEq34{2,1}==1);
            
        c1 = find(nashEq34{1,1}==1)
        c2 = find(nashEq34{2,1}==1)
        conflictPoint = sub2ind([m e], find(nashEq34{1,1}==1), find(nashEq34{2,1}==1))
        
        %[A, payoffNPG, iterations, err] = npg([m e], -payoffBoth);
        %payoffEngNashNPG = -payoffNPG(1)
        %payoffMotNashNPG = -payoffNPG(2)
        
        [~, indNP] = nashsolution(payoffBoth, conflictPoint);
        payoffEngNashSol = payoffBoth(indNP,1)
        payoffMotNashSol = payoffBoth(indNP,2)
        
        [ks] = kalaismorodinskysolution(payoffBoth, conflictPoint, paretoStrategies)                
        percentReqTorq = linspace(0, requiredTorque, 10);
        
        payoffCoalCoef = ones(m,e);
        payoffCoalCoef(m:m-1:end-1) = 0.5;
         
        [ payoffWholeCoal, coeffCoal, payoffEngineCoal, payoffMotorCoal, payoffWholeCoalBefore ] = ...
            coalitionpayoffs(payoffMotor, payoffEngine, torqueDeviation, percentReqTorq);
        
        indCoal = (coeffCoal == 0.9 | coeffCoal == 0.91);
        indCoalition = +indCoal;
        indCoalition(indCoal == true) = 0.95;
        indCoalition(indCoal == false) = 1;
        payoffWholeCoal1 = payoffWholeCoal .* indCoalition;      
    
        % get all undominated strategies (pareto optimality)
        payoffMotCoalVec = reshape(payoffMotorCoal,(m)*(e),1);
        payoffEngCoalVec = reshape(payoffEngineCoal,(m)*(e),1);
        
        [undomImp, undomImpInd] = checkimputation(payoffBoth, ...
            paretoStrategies, payoffMotCoalVec, payoffEngCoalVec, payoffWholeCoal);        
        imputM = zeros(1,size(undomImpInd,2));
        imputE = zeros(1,size(undomImpInd,2));
        for i = 1 : size(undomImpInd,2)             
            if undomImp(i,1) <= payoffEngine(m,:)
                imputM(1,i) = undomImpInd(i);
            end                
            if undomImp(i,2) <= payoffMotor(:,e)
                imputE(1,i) = undomImpInd(i);
            end
        end
        impLinInd = [];                
        imput = undomImpInd
        [impLinInd(:,1), impLinInd(:,2)] = ind2sub(size(payoffEngine), imput);
          
        payoffImput = zeros(size(imput,2),3);
        for i = 1 : size(imput,2)
            payoffImput(i,1) = payoffBoth(imput(i),1);
            payoffImput(i,2) = payoffBoth(imput(i),2);       
            [r, c] = ind2sub(size(payoffWholeCoal), imput(i));
            payoffImput(i,3) = payoffWholeCoal(r,c);
        end
        
        tic
        coreSol = core(payoffImput);
        indCore = find(coreSol) 
        toc
        
        [ shEngine, shMotor ] = shapleyvalue( payoffWholeCoal1, payoffMotor, ...
            payoffEngine, impLinInd)
        
       

        %p5 = plot(payoffEngNashNPG, payoffMotNashNPG, 'o', ...
        %    'MarkerFaceColor','y', 'MarkerEdgeColor', 'y',...
        %    'MarkerSize', 11);
        p4 = plot(payoffEngNash, payoffMotNash, 'om', ...
            'MarkerFaceColor', 'm', 'MarkerSize', 11);    
        %p41 = plot(bestPayoffEngNashLH(2), bestPayoffMotNashLH(2), 'or', ...
        %    'MarkerFaceColor', 'r', 'MarkerSize', 6);      
        %p42 = plot(bestPayoffEngNashLH(3), bestPayoffMotNashLH(3), 'oc', ...
        %    'MarkerFaceColor', 'c', 'MarkerSize', 6);     
        %p3 = plot(bestPayoffEngPareto, bestPayoffMotPareto, 'og', ...
        %    'MarkerFaceColor', 'g', 'MarkerSize', 12);       
        p6 = plot(payoffEngNashSol, payoffMotNashSol,'or', ...
            'MarkerFaceColor',[1,0.6,0] , 'MarkerEdgeColor', [1,0.6,0] ,...
            'MarkerSize', 9);
        pink = [254 164 191] ./ 255;
        purple = [118 31 133] ./ 255;
        p7 = plot(payoffBoth(imput(indCore),1), payoffBoth(imput(indCore),2), 'o', ...
            'MarkerFaceColor',pink, 'MarkerEdgeColor',pink,...
            'MarkerSize', 7);
        p8 = plot(ks(1,1), ks(1,2), 'o', 'MarkerFaceColor', purple, ...
            'MarkerEdgeColor', purple, 'MarkerSize', 6);
        for r = 1 : size(paretoIndex,1)
            linearIndex = sub2ind([m e], paretoIndex(r,2), paretoIndex(r,1));            
            p2 = plot(x(linearIndex), y(linearIndex), 'o', ...
                'MarkerEdgeColor', [0,0.5,0], 'MarkerFaceColor',[0,0.5,0],...
                'MarkerSize',5);
        end
        legend([p1 p2 p4 p6 p7 p8], 'Payoff', 'Pareto optimal payoff', ...
        'Nash Equilibrium Lemke-Howson', 'Nash Solution', 'Core', 'Kalai-Smorodinsky', 'Location', 'northwest');
        % 'Nash Solution', 'Nash Equilibrium Lemke-Howson (conflict point)'); 
        % 'Nash Equilibrium Lemke-Howson k0=8', ...
        %     'Nash Equilibrium Lemke-Howson k0=15' , ... 
        %     'Nash Equilibrium NPG',          
       
        xlabel('Payoff Engine');
        ylabel('Payoff Motor');
        hold off
%end