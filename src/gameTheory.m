function [engineTorque, motorTorque] = gameTheory(torque)

addpath(genpath('src\fuel and emissions'));
fuel
exhaustEmis
torque = 189;
engineSpeedRadPerS = 500;
engineSpeedRadRPM = engineSpeedRadPerS*9.5492;
SOC_deviation = 0.05;
maxEngineTorque = 136;
maxMotorTorque = 400;
maxRPM = 6000;
M = 60;
N = 60;
payoffMotor = zeros(M+1,N+1);
payoffEngine = zeros(M+1,N+1);
percentage = 0:(1/M):1;
maxMotorTorqueStrategy = min([torque maxMotorTorque]);
maxEngineTorqueStrategy = min([torque maxEngineTorque]);

strategyEng = percentage .* maxEngineTorqueStrategy;
strategyMot = percentage .* maxMotorTorqueStrategy;
%strategyMot = fliplr(strategyMot);
tmpTorque = repmat(strategyEng',1,M+1);

tmpS = abs(FuelConsTable.speed - engineSpeedRadRPM);
[~, idxS ] = min(tmpS);

for i = 1:M+1
    for j = 1:N+1
        totalTorque(i,j) = tmpTorque(i,j) + strategyMot(j);
    end
end

%T = P * 9.549 / n
engineMaxPower = 57000;
motorMaxPower = 50000;

motorSpeed = [0, 1200, 2000, 3000, 4000, 5000, 6000];
motorTorque = [400, 400, 280, 222, 179, 143, 119];

engineSpeed = [0, 420, 900, 1380, 1860, 2340, 2820, 3300, 3780, 4260, 4740, 5220, 5700, 6000];
engineTorque = [109, 117, 125, 131, 134, 136, 136, 133, 129, 123, 114, 104, 91, 83];
wFuel = 60;
wPower = 0.5;
wDrDem = 1;
wSOC = 21;
wNOX = 28;
wCO = 56;
wHC = 45;
for i = 1:M+1
    for j = 1:N+1
        tmpT = abs(FuelConsTable.torque - strategyEng(j));
        [~, idxT] = min(tmpT);      
        fuelConsumedGPS = FuelConsTable.lookupTableFuel(idxT, idxS);
        powerKW = FuelConsTable.lookupTablePower(idxT,idxS);  
        HCEmissions = GasEmisTable.lookupTableHC(idxT, idxS);
        COEmissions = GasEmisTable.lookupTableCO(idxT, idxS);
        NOXEmissions = GasEmisTable.lookupTableNOX(idxT, idxS);
        payoffEngine(i,j) = wFuel*fuelConsumedGPS + wDrDem*abs(torque - totalTorque(i,j)) + wSOC*SOC_deviation + wHC*HCEmissions + wCO*COEmissions + wNOX*NOXEmissions;
        payoffMotor(i,j) = wPower*powerKW + wDrDem*abs(torque - totalTorque(i,j)) + wSOC*SOC_deviation + wHC*HCEmissions + wCO*COEmissions + wNOX*NOXEmissions;
    end
end

payoffBoth = reshape([payoffMotor;payoffEngine],size(payoffMotor,1),[]);
payoff = zeros(M+1, N+1);
payoff = mat2cell(payoffBoth, ones(1,M+1), ones(1,M+1).*2);
[pareto, paretoString] = paretoSet(payoff);
pareto
paretoString

motorTorque = strategyMot(pareto(1));
engineTorque = strategyEng(pareto(2));
end