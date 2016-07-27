fileSpeed = fopen('data/not needed/engine_speed.txt','r');
filePower = fopen('data/engine_power.txt','r');
fileTorque = fopen('data/not needed/engine_torque.txt','r');

formatSpec = '%f';
EngineSpeedPower.speed = fscanf(fileSpeed, formatSpec);
EngineSpeedPower.power = fscanf(filePower, formatSpec);
EngineSpeedPower.torque = fscanf(fileTorque, formatSpec);

figure
plot(EngineSpeedPower.speed, EngineSpeedPower.torque, 'LineWidth', 2);
xlabel('speed (rpm)');
ylabel('torque (Nm)');
title(' Engine torque versus speed curve');

motorSpeedCurve = [0, 1200, 2000, 3000, 4000, 5000, 6000];
motorTorqueCurve = [400 400 225 150 100 80 70];

figure
plot(motorSpeedCurve, motorTorqueCurve, 'LineWidth', 2);
xlabel('speed (rpm)');
ylabel('torque (Nm)');
title(' Motor torque versus speed curve');
hold on

