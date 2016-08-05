% read engine files for speed, power and torque
fileSpeed = fopen('data/not needed/engine_speed.txt','r');
filePower = fopen('data/engine_power.txt','r');
fileTorque = fopen('data/not needed/engine_torque.txt','r');

formatSpec = '%f';
EngineSpeedPower.speed = fscanf(fileSpeed, formatSpec);
EngineSpeedPower.power = fscanf(filePower, formatSpec);
EngineSpeedPower.torque = fscanf(fileTorque, formatSpec);

% plot engine torque vs speed curve
figure
plot(EngineSpeedPower.speed, EngineSpeedPower.torque, 'LineWidth', 2);
xlabel('speed (rpm)','FontSize',15);
ylabel('torque (Nm)','FontSize',15);
title(' Engine torque versus speed curve','FontSize',18);

motorSpeedCurve = [0, 1200, 2000, 3000, 4000, 5000, 6000];
motorTorqueCurve = [400 400 225 150 100 80 70];

% plot motor torque vs speed curve
figure
plot(motorSpeedCurve, motorTorqueCurve, 'LineWidth', 2);
xlabel('speed (rpm)','FontSize',15);
ylabel('torque (Nm)','FontSize',15);
title(' Motor torque versus speed curve','FontSize',18);
hold on

