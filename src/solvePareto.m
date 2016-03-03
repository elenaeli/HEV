%function [engineTorque,motorTorque] = solvePareto(requiredTorque, FuelConsTable, GasEmisTable)
        requiredTorque = 40
        
        engineSpeedRadPerS = 500;
        engineSpeedRadRPM = engineSpeedRadPerS*9.5492;
        SOC_deviation = 0.07;
        maxEngineTorque = 136;
        maxMotorTorque = 400;
        maxRPM = 6000;
        M = 2;
        N = 2;
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

        engineMaxPower = 57000;
        motorMaxPower = 50000;
        motorSpeed = [0, 1200, 2000, 3000, 4000, 5000, 6000];
        motorTorqueRef = [400, 400, 280, 222, 179, 143, 119];
        engineSpeed = [0, 420, 900, 1380, 1860, 2340, 2820, 3300, 3780, 4260, 4740, 5220, 5700, 6000];
        engineTorqueRef = [109, 117, 125, 131, 134, 136, 136, 133, 129, 123, 114, 104, 91, 83];
        
        tmpS = abs(FuelConsTable.speed - engineSpeedRadRPM);
        idxS = 0;
        [~, idxS ] = min(tmpS);

        % weights
        wFuel = 10;
        wPower = 0.1;
        wDrDem = 0.25;
        wSOC = 8;
        wNOX = 20;
        wCO = 20;
        wHC = 20;
       
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
                payoffEngine(i,j) = wFuel*fuelConsumedGPS + wPower*powerKW + wDrDem*abs(requiredTorque - totalTorque(i,j)) + wHC*HCEmissions + wCO*COEmissions + wNOX*NOXEmissions + wSOC*SOC_deviation;
                payoffMotor(i,j) = 0.5*wFuel*fuelConsumedGPS + wDrDem*abs(requiredTorque - totalTorque(i,j)) + wSOC*SOC_deviation ;
                if i == 10 && j == 12
                    fu = wFuel*fuelConsumedGPS
                    po = wPower*powerKW
                    HC = wHC*HCEmissions
                    CO = wCO*COEmissions
                    NOX = wNOX*NOXEmissions
                    differenceTorque = abs(requiredTorque - totalTorque(i,j))
                    payoffEngine(i,j)
                    payoffMotor(i,j)
                end
            end
        end
        %payoffMotor = payoffEngine';
        payoffBoth = reshape([payoffEngine;payoffMotor],size(payoffMotor,1),[]);         
        tic
        paretoStrategies = paretoSet(payoffEngine, payoffMotor, requiredTorque)
        toc
        motorTorque = strategyMot(paretoStrategies(:,2))
        engineTorque = strategyEng(paretoStrategies(:,1))

        nashStrategies = nashSolution(payoffEngine, payoffMotor, requiredTorque)

%end

