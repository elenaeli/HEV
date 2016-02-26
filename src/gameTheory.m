%function [engineTorque, motorTorque] = gameTheory(torque)
torque = 300;
maxEngineTorque = 142;
maxMotorTorque = 400;
engineSpeedRadPerS = 164;
engineSpeedRadRPM = engineSpeedRadPerS*9.5492;
SOC_deviation = 0.05;
M = 10;
N = 10;
payoff = zeros(M+1,N+1);
percentage = 0:0.1:1;
maxMotorTorqueStrategy = min([torque maxMotorTorque]);
maxEngineTorqueStrategy = min([torque maxEngineTorque]);

strategyEng = percentage .* maxEngineTorqueStrategy;
strategyMot = percentage .* maxMotorTorqueStrategy;
strategyMot = fliplr(strategyMot);
tmpTorque = repmat(strategyMot',1,M+1);

tmpS = abs(FuelConsTable.speed - engineSpeedRadRPM);
[idxS idxS] = min(tmpS);
lookupSpeed = FuelConsTable.speed(idxS)
wFuel = 5;
wDrDem = 1;
wSOC = 2;
for i = 1:M+1
    for j = 1:N+1
        totalTorque(i,j) = tmpTorque(i,j) + strategyEng(j);
    end
end

T = P * 9.549 / n
engineMaxPower = 73 000;
motorMaxPower = 50 000;
maxRPM = 6000;
rpmMotor = [0,1200,2000,3000,4000,5000,6000]*pi/30;
torqueMotor = [400,400,280,222,179,143,119];

for i = 1:M+1
    for j = 1:N+1
        tmpT = abs(FuelConsTable.torque - strategyEng(j));
        [idxT idxT] = min(tmpT);
        lookupTorque = FuelConsTable.torque(idxT)
        fuelConsumedGPS = FuelConsTable.lookupTable(idxT, idxS);
        payoff(i,j) = wFuel*fuelConsumedGPS + wDrDem*abs(torque - totalTorque(i,j)) + wSOC*SOC_deviation;
    end
end

[paretoFrontMot, paretoIndicesMot] = paretoEfficiency(payoff);
payoff1 = payoff';
[paretoFrontEng, paretoIndicesEng] = paretoEfficiency(payoff1);

%engineTorque = torque;
%motorTorque = torque;