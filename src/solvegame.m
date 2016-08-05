    requiredTorque = 280;         
    SOC = 75;
    fuelConsumed = 0.97;
    prevEngTorqueArOut = zeros(100,1);
    prevMotTorqueArOut = zeros(100,1);        
    requiredTorqueR = 0;
    requiredTorqueR = roundn(requiredTorque,0);       
    
    if requiredTorqueR > 0 && requiredTorqueR < 83          
    	engineTorque = 0;
        motorTorque = requiredTorqueR;
    elseif requiredTorqueR < 0          
        engineTorque = 0;
        motorTorque = requiredTorqueR;
    elseif requiredTorqueR == 0          
        engineTorque = 0;
        motorTorque = 0;
    else  
        close all   
        motorSpeedCurve = [0, 1200, 2000, 3000, 4000, 5000, 6000];
        motorTorqueCurve = [400 399 225 150 100 80 70];

        SOC_deviation = abs(70 - SOC);       
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
        wSOC = 1;
        wNOX = 65;
        wCO = 25;
        wHC = 45;
        motorSpeedRef = zeros(1,e);
        powerMotorKW = zeros(1,e);
        torqueDeviation = zeros(m,e);
        fuelConsRate = zeros(e,1);       
        emissions = zeros(e,1);
        power = zeros(e,1);
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
                torqueDeviation(i,j) = requiredTorqueR - totalTorque(i,j);             
                payoffEngine(i,j) = wFuel*fuelConsumedGPS + wDrDem*abs(torqueDeviation(i,j)) + ...
                    wHC*HCEmissions + wCO*COEmissions + wNOX*NOXEmissions + ...
                    wTank*fuelConsumed;
                payoffMotor(i,j) = wDrDem*abs(torqueDeviation(i,j)) + wPower*powerMotorKW(j) + ...
                    wSOC*SOC_deviation;
                fuelConsRate(j,1) = fuelConsumedGPS; 
                emissions(j,1) = HCEmissions + COEmissions + NOXEmissions;
                power(j,1) = powerMotorKW(j);                             
            end
        end
        [engineTorque, motorTorque] = solveG(payoffEngine, payoffMotor, ...
        	strategyEng, strategyMot, requiredTorqueR, torqueDeviation,...
            fuelConsRate, fuelConsumed, emissions, power, m, e);       
    end
        
     
