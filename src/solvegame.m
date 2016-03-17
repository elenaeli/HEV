%function [engineTorque,motorTorque] = solvegame(requiredTorque, FuelConsTable, GasEmisTable)
        requiredTorque = 146;
        
        close all
        engineSpeedRadPerS = 200;
        engineSpeedRadRPM = engineSpeedRadPerS*9.5492;
        SOC_deviation = 0.12;
        maxEngineTorque = 136;
        maxMotorTorque = 400;
        maxRPM = 6000;
        M = 15;
        N = 15;
        payoffMotor = zeros(M,N);
        payoffEngine = zeros(M,N);
        percentage = 0:(1/(M-1)):1;
        maxEngineTorqueStrategy = min([requiredTorque maxEngineTorque]);
        maxMotorTorqueStrategy = min([requiredTorque maxMotorTorque]);

        strategyEng = percentage .* maxEngineTorqueStrategy;
        strategyMot = percentage .* maxMotorTorqueStrategy;
        tmpTorque = repmat(strategyEng',1,M);

        totalTorque = zeros(M, N);
        for i = 1:M
            for j = 1:N
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
        wSOC = 40;
        wNOX = 50;
        wCO = 30;
        wHC = 30;
       
        for i = 1:M
            for j = 1:N
                tmpT = abs(FuelConsTable.torque - strategyEng(j));
                idxT = 0;
                [~, idxT] = min(tmpT);      
                fuelConsumedGPS = FuelConsTable.lookupTableFuel(idxT, idxS);
                powerKW = FuelConsTable.lookupTablePower(idxT, idxS) ;
                HCEmissions = GasEmisTable.lookupTableHC(idxT, idxS);
                COEmissions = GasEmisTable.lookupTableCO(idxT, idxS);
                NOXEmissions = GasEmisTable.lookupTableNOX(idxT, idxS);   
                torqueDeviation(i,j) = requiredTorque - totalTorque(i,j);
                payoffEngine(i,j) = wFuel*fuelConsumedGPS + wPower*powerKW + wDrDem*abs(torqueDeviation(i,j)) + wHC*HCEmissions + wCO*COEmissions + wNOX*NOXEmissions + wSOC*SOC_deviation;
                payoffMotor(i,j) = 0.6*wFuel*fuelConsumedGPS + wDrDem*abs(torqueDeviation(i,j)) + + wHC*HCEmissions + wCO*COEmissions + wNOX*NOXEmissions + wSOC*SOC_deviation;                
                if i == 1 && j == 1
                    fu = wFuel*fuelConsumedGPS
                    po = wPower*powerKW
                    HC = wHC*HCEmissions
                    CO = wCO*COEmissions
                    NOX = wNOX*NOXEmissions
                    torqueDeviation(i,j)                 
                end                
            end
        end
        %payoffMotor = payoffEngine';
        payoffBoth = reshape([payoffEngine;payoffMotor],size(payoffMotor,1),[]);         
        
        tic
        [paretoStrategies, paretoIndex, x, y] = paretoset(payoffEngine, payoffMotor);                
        toc
        payoffE = reshape(payoffEngine,(M)*(N),1);
        payoffM = reshape(payoffMotor,(M)*(N),1);        
        payoffB = horzcat(payoffE, payoffM);
        
        front = paretofront(payoffB);
        in = find(front);  
        figure
        plot(x,y,'ob');
        hold on
        plot(payoffB(in,1), payoffB(in,2), 'or');
                
        engineTorquePareto = strategyEng(paretoIndex(:,1));
        motorTorquePareto = strategyMot(paretoIndex(:,2));
     
        %[sol, fval] = nashSolution(payoffEngine, payoffMotor, requiredTorque, paretoPayoffEng, paretoPayoffMot)
        stringRequiredTorque = int2str(requiredTorque);   
   
        figure
        p1 = plot(x,y,'ob');
        title(['Game payoffs, required torque = ', stringRequiredTorque, 'Nm'] );
        hold on
        payoffEngPareto = zeros(1,size(paretoIndex,1));
        payoffMotPareto = zeros(1,size(paretoIndex,1));
        torqueDeviationPareto = zeros(1,size(paretoIndex,1));
        for r = 1 : size(paretoIndex,1)
            payoffEngPareto(1,r) = paretoStrategies(r,1);
            payoffMotPareto(1,r) = paretoStrategies(r,2);
            torqueDeviationPareto(1,r) = torqueDeviation(paretoIndex(r,1), paretoIndex(r,2));
        end
        
        payoffEngPareto
        payoffMotPareto
        
        bestTorqDevPareto = min(abs(torqueDeviationPareto));
        Idxs = find(abs(torqueDeviationPareto)==bestTorqDevPareto);       
        if size(Idxs,2) > 1
            [bestTorqDevPareto, indM] = max(torqueDeviationPareto(1,Idxs));
            bestPayoffEngPareto = paretoStrategies(indM,1); 
            bestPayoffMotPareto = paretoStrategies(indM,2);        
        else
            bestPayoffEngPareto = paretoStrategies(1,1);
            bestPayoffMotPareto = paretoStrategies(1,2);
        end    
        bestPayoffEngPareto
        bestPayoffMotPareto        

        numStratBoth = M+N;
        tic
        nashEq1 = LemkeHowson(-payoffEngine, -payoffMotor);      
        nashEqQuat = LemkeHowson(-payoffEngine, -payoffMotor, ceil(numStratBoth/4));      
        nashEqHalf = LemkeHowson(-payoffEngine, -payoffMotor, ceil(numStratBoth/2));      
        nashEq3Quat = LemkeHowson(-payoffEngine, -payoffMotor, ceil(3/4*numStratBoth));
        toc
     
        engineTorqueNash = strategyEng(nashEq1{1,1}==1);
        motorTorqueNash = strategyMot(nashEq1{2,1}==1);
        payoffEngNash(1) = payoffEngine(nashEq1{1,1}==1, nashEq1{2,1}==1);      
        payoffMotNash(1) = payoffMotor(nashEq1{1,1}==1, nashEq1{2,1}==1);
        
        payoffEngNash(2) = payoffEngine(nashEqQuat{1,1}==1, nashEqQuat{2,1}==1);       
        payoffMotNash(2) = payoffMotor(nashEqQuat{1,1}==1, nashEqQuat{2,1}==1);
        
        payoffEngNash(3) = payoffEngine(nashEqHalf{1,1}==1, nashEqHalf{2,1}==1);     
        payoffMotNash(3) = payoffMotor(nashEqHalf{1,1}==1, nashEqHalf{2,1}==1);
        
        payoffEngNash(4) = payoffEngine(nashEq3Quat{1,1}==1, nashEq3Quat{2,1}==1);       
        payoffMotNash(4) = payoffMotor(nashEq3Quat{1,1}==1, nashEq3Quat{2,1}==1);
        
        [minPayoffEngNash, indM] = min(payoffEngNash);
        switch indM
            case 1
                nashIndEng = find(nashEq1{1,1}==1);
                nashIndMot = find(nashEq1{2,1}==1);                
            case 2
                nashIndEng = find(nashEqQuat{1,1}==1);
                nashIndMot = find(nashEqQuat{2,1}==1);
            case 3
                nashIndEng = find(nashEqHalf{1,1}==1);
                nashIndMot = find(nashEqHalf{2,1}==1);
            case 4
                nashIndEng = find(nashEq3Quat{1,1}==1);
                nashIndMot = find(nashEq3Quat{2,1}==1);
        end
        c1 = find(nashEqQuat{1,1}==1)
        c2 = find(nashEqQuat{2,1}==1)
        conflictPoint = sub2ind([M N], find(nashEqQuat{1,1}==1), find(nashEqQuat{2,1}==1))

        bestPayoffEngNashLH = payoffEngNash(2);
        bestPayoffMotNashLH = payoffMotNash(2);        

        
        %[A, payoffNPG, iterations, err] = npg([M N], -payoffB);
        %payoffEngNashNPG = -payoffNPG(1)
        %payoffMotNashNPG = -payoffNPG(2)
        
        
        [~, indNP] = nashsolution(payoffB, conflictPoint);
        payoffEngNashSol = payoffB(indNP,1)
        payoffMotNashSol = payoffB(indNP,2)
        
        %[ks, indKS] = kalaismorodinskysolution(payoffB, conflictPoint)
        
        payoffCoalCoef = ones(M,N);
        payoffCoalCoef(M:M-1:end-1) = 0.5;
        payoffEngineCoal = payoffEngine .* payoffCoalCoef;
        payoffMotorCoal = payoffMotor .* payoffCoalCoef;
        payoffWholeCoalition = payoffEngineCoal + payoffMotorCoal;
        
        imputM = [];
        imputE = [];
    
        % get all undominated strategies (pareto optimality)
        undominated = checkundominated(payoffB, paretoStrategies, payoffWholeCoalition);
        % check individual rationality (player receives <= payoff in the
        % colaition than when acting alone)
        for i = 1 : size(paretoIndex,1)             
            if undominated(i,1) <= payoffEngine(M,:)
                imputM(1,i) = sub2ind(size(payoffEngine), paretoIndex(i,1), paretoIndex(i,2));
            end                
            if undominated(i,2) <= payoffMotor(:,N)
                imputE(1,i) = sub2ind(size(payoffMotor), paretoIndex(i,1), paretoIndex(i,2));
            end
        end  
                
        imputations = intersect(imputE, imputM)
        
       
          
        payoffBCore = [];
        payoffBCore(:,1) = payoffB(C,1);
        payoffBCore(:,2) = payoffB(C,2);
        payoffBCore(:,3) = payoffEngine(M,1)+payoffMotor(1,N);
      
        %payoffBCore(:,3) = payoffEngine(M+1,1) + payoffMotor(M+1,1);
        tic
        coreSol = core(payoffBCore);
        ind = find(coreSol) 
        toc
        p4 = plot(bestPayoffEngNashLH, bestPayoffMotNashLH, 'om', ...
            'MarkerFaceColor','m', 'MarkerSize', 17);    
        p5 = plot(payoffEngNashNPG, payoffMotNashNPG, 'o', ...
            'MarkerFaceColor','y', 'MarkerEdgeColor', 'y',...
            'MarkerSize', 14);  
        p3 = plot(bestPayoffEngPareto, bestPayoffMotPareto, 'og', ...
            'MarkerFaceColor', 'g', 'MarkerSize', 11);
        p6 = plot(payoffEngNashSol, payoffMotNashSol,'or', ...
            'MarkerFaceColor',[1,0.6,0] , 'MarkerEdgeColor', [1,0.6,0] ,...
            'MarkerSize', 9);            
        plot(payoffB(C,1), payoffB(C,2), 'oc','MarkerFaceColor','c',...
            'MarkerSize', 7);

        for r = 1 : size(paretoIndex,1)
            linearIndex = sub2ind([M N], paretoIndex(r,2), paretoIndex(r,1));            
            p2 = plot(x(linearIndex), y(linearIndex), 'o', ...
                'MarkerEdgeColor', [0,0.6,0], 'MarkerFaceColor',[0,0.6,0],...
                'MarkerSize',5);   
        end
        legend([p1 p2 p3 p4 p5 p6], 'Payoff', 'Pareto optimum payoff', ...
            'Best Pareto optimum payoff', 'Nash Equilibrium Lemke-Howson',...
            'Nash Equilibrium NPG', 'Nash Solution', 'Location', 'northwest');
        xlabel('Payoff Engine');
        ylabel('Payoff Motor');
        hold off
%end

