function [engineTorque,motorTorque] = gameTh(requiredTorque, FuelConsTable, GasEmisTable)
%#codegen
    coder.extrinsic('genpath'); 
    coder.extrinsic('addpath');
    coder.extrinsic('mat2cell');
    if requiredTorque == 0
        motorTorque = 0;
        engineTorque = 0;
    else     
        motorTorque = 0;
        engineTorque = 0;
        addpath(genpath('C:\Users\Elena\Documents\MATLAB\HEV\src\fuel and emissions'));       
        requiredTorque = 19;
        engineSpeedRadPerS = 500;
        engineSpeedRadRPM = engineSpeedRadPerS*9.5492;
        SOC_deviation = 0.05;
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

        %T = P * 9.549 / n
        engineMaxPower = 57000;
        motorMaxPower = 50000;

        motorSpeed = [0, 1200, 2000, 3000, 4000, 5000, 6000];
        motorTorqueRef = [400, 400, 280, 222, 179, 143, 119];

        engineSpeed = [0, 420, 900, 1380, 1860, 2340, 2820, 3300, 3780, 4260, 4740, 5220, 5700, 6000];
        engineTorqueRef = [109, 117, 125, 131, 134, 136, 136, 133, 129, 123, 114, 104, 91, 83];
        wFuel = 10;
        wPower = 0.1;
        wDrDem = 0.25;
        wSOC = 8;
        wNOX = 10;
        wCO = 10;
        wHC = 10;
        %fuelConsumedGPS = zeros(1,1);
        %powerKW = zeros(1,1);
        %HCEmissions = zeros(1,1);
        %COEmissions = zeros(1,1);
        %NOXEmissions = zeros(1,1);
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
                payoffEngine(i,j) = wFuel*fuelConsumedGPS + wDrDem*abs(requiredTorque - totalTorque(i,j)) + wSOC*SOC_deviation + wHC*HCEmissions + wCO*COEmissions + wNOX*NOXEmissions;
                payoffMotor(i,j) = wPower*powerKW + wDrDem*abs(requiredTorque - totalTorque(i,j)) + wSOC*SOC_deviation + wHC*HCEmissions + wCO*COEmissions + wNOX*NOXEmissions;
                if i == 10 && j == 6
                    fu = wFuel*fuelConsumedGPS
                    po = wPower*powerKW                    
                    differenceTorque = abs(requiredTorque - totalTorque(i,j))
                    payoffEngine(i,j)
                    payoffMotor(i,j)
                end
            end
        end

        payoffBoth = reshape([payoffMotor;payoffEngine],size(payoffMotor,1),[]);
        p = zeros(M+1, (N+1)*2);
        %payoff = mat2cell(payoffBoth, ones(1,M+1), ones(1,M+1).*2);
        p = payoffBoth;
        pareto = [];
        tic
        pareto = paretoSet(p)
        toc
        motorTorque = strategyMot(pareto(:,2))
        engineTorque = strategyEng(pareto(:,1))
    end
end