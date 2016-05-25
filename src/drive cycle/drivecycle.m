ftp75M = dlmread('data/ftp75_s_mph_reduced.txt','\t');
ftp75 = struct('seconds', ftp75M(:,1), 'kph', ftp75M(:,2));

% mph to kph
ftp75.kph = ftp75.kph.* 1.60934;
ftp75.time = 0.5* ((0+10) + (10-(0))*((2*ftp75.seconds - (1+1857))/(1857-(1))) ); 

nedcM = dlmread('data/nedc_s_kph.txt','\t');
nedc = struct('seconds', nedcM(:,1), 'kph', nedcM(:,2));
nedc.time = 0.5* ((0+10) + (10-(0))*((2*nedc.seconds - (0+1184))/(1184-(0))) ); 

accel = dlmread('data/accel.txt','\t');
accel = struct('seconds', accel(:,1), 'kph', accel(:,2));
accel.time = 0.5* ((0+10) + (10-(0))*((2*accel.seconds - (1+21))/(21-(1))) ); 

figure
title('FTP75 drive cycle');
xlabel('time (s)','FontSize',11)
ylabel('speed (km/h)','FontSize',11)
plot(ftp75.seconds, ftp75.kph)

figure
title('NEDC drive cycle');
xlabel('time (s)','FontSize',11)
ylabel('speed (km/h)','FontSize',11)
plot(nedc.seconds, nedc.kph)
