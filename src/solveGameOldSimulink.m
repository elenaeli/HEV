function [engineTorque,motorTorque] = solveGame(requiredTorque, SOC, fuelConsumed, FuelConsTable, GasEmisTable)
%#codegen
    if requiredTorque < 10
        motorTorque = requiredTorque;
        engineTorque = 0;
    else        
        engineSpeedRadPerS = 500;
        engineSpeedRadRPM = engineSpeedRadPerS*9.5492;
        targetSOC = 0.6; 
        SOC = SOC/100;
        SOC_deviation = abs(targetSOC - SOC);
        maxEngineTorque = 136;
        maxMotorTorque = 400;
        maxRPM = 6000;
        M = 10;
        N = 10;
        payoffMotor = zeros(M+1,N+1);
        payoffEngine = zeros(M+1,N+1);
        percentage = 0:(1/M):1;
        maxMotorTorqueStrategy = min([requiredTorque maxMotorTorque]);
        maxEngineTorqueStrategy = min([requiredTorque maxEngineTorque]);

        strategyEng = percentage .* maxEngineTorqueStrategy;
        strategyMot = percentage .* maxMotorTorqueStrategy;
        %strategyMot = fliplr(strategyMot);
        tmpTorque = repmat(strategyEng',1,M+1);

        tmpS = abs(FuelConsTable.speed - engineSpeedRadRPM);
        idxS = 0;
        [~, idxS ] = min(tmpS);

        totalTorque = zeros(M+1, N+1);
        for i = 1:M+1
            for j = 1:N+1
                totalTorque(i,j) = tmpTorque(i,j) + strategyMot(j);
            end
        end
        engineMaxPower = 57000;
        motorMaxPower = 50000;
       
        motorSpeed = [0, 1200, 2000, 3000, 4000, 5000, 6000];
        motorTorqueRef = [400, 400, 280, 222, 179, 143, 119];
        engineSpeed = [0, 420, 900, 1380, 1860, 2340, 2820, 3300, 3780, 4260, 4740, 5220, 5700, 6000];
        engineTorqueRef = [109, 117, 125, 131, 134, 136, 136, 133, 129, 123, 114, 104, 91, 83];
        
        % weights 
        wFuel = 10;
        wPower = 0.1;
        wDrDem = 0.25;
        wSOC = 8;
        wNOX = 10;
        wCO = 10;
        wHC = 10;

        for i = 1:M+1
            for j = 1:N+1
                tmpT = abs(FuelConsTable.torque - strategyEng(j));
                idxT = 0;
                [~, idxT] = min(tmpT);      
                fuelConsumedGPS = FuelConsTable.lookupTableFuel(idxT, idxS);
                powerKW = FuelConsTable.lookupTablePower(idxT, idxS);  
                HCEmissions = GasEmisTable.lookupTableHC(idxT, idxS);
                COEmissions = GasEmisTable.lookupTableCO(idxT, idxS);
                NOXEmissions = GasEmisTable.lookupTableNOX(idxT, idxS);
                payoffEngine(i,j) = wFuel*fuelConsumedGPS + wDrDem*abs(requiredTorque - totalTorque(i,j)) + wSOC*SOC_deviation + wHC*HCEmissions + wCO*COEmissions + wNOX*NOXEmissions;
                payoffMotor(i,j) = wPower*powerKW + wDrDem*abs(requiredTorque - totalTorque(i,j)) + wSOC*SOC_deviation + wHC*HCEmissions + wCO*COEmissions + wNOX*NOXEmissions;
            end
        end
        %payoffMotor = payoffEngine';
        %payoffBoth = reshape([payoffMotor;payoffEngine],size(payoffMotor,1),[]);
        pareto = [];
        pareto = paretoset(payoffEngine, payoffMotor, requiredTorque);
        requiredTorque 
        motorTorque = strategyMot(pareto(1,2))
        engineTorque = strategyEng(pareto(1,1))
    end
end