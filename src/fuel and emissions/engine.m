fileSpeed = fopen('data/engine_speed.txt','r');
filePower = fopen('data/engine_power.txt','r');
formatSpec = '%f';
EngineSpeedPower.speed = fscanf(fileSpeed, formatSpec);
EngineSpeedPower.power = fscanf(filePower, formatSpec);
