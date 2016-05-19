fileSpeed = fopen('data/engine_speed.txt','r');
filePower = fopen('data/engine_power.txt','r');
fileTorque = fopen('data/engine_torque.txt','r');

formatSpec = '%f';
EngineSpeedPower.speed = fscanf(fileSpeed, formatSpec);
EngineSpeedPower.power = fscanf(filePower, formatSpec);
EngineSpeedPower.torque = fscanf(fileTorque, formatSpec);
