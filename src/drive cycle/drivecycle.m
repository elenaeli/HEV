ftp75M = dlmread('data/ftp75_s_mph_reduced.txt','\t');
ftp75 = struct('seconds', ftp75M(:,1), 'kph', ftp75M(:,2)* 1.60934);
ftp75_1 = struct('seconds', ftp75M(1:32,1), 'kph', ftp75M(1:32,2)* 1.60934);
ftp75_2 = struct('seconds', ftp75M(32:62,1)-340, 'kph', ftp75M(32:62,2)* 1.60934);
ftp75_3 = struct('seconds', ftp75M(62:90,1)-680, 'kph', ftp75M(62:90,2)* 1.60934);
ftp75_4 = struct('seconds', ftp75M(90:123,1), 'kph', ftp75M(90:123,2)* 1.60934);
ftp75_5 = struct('seconds', ftp75M(123:end,1), 'kph', ftp75M(123:end,2)* 1.60934);

% mph to kph
%ftp75.kph = ftp75.kph.* 1.60934;
%ftp75.time = 0.5* ((0+10) + (10-(0))*((2*ftp75.seconds - (1+1857))/(1857-(1))) ); 

nedcM = dlmread('data/nedc_s_kph.txt','\t');
nedc = struct('seconds', nedcM(:,1), 'kph', nedcM(:,2));
%nedc.time = 0.5* ((0+10) + (10-(0))*((2*nedc.seconds - (0+1184))/(1184-(0))) ); 

accel = dlmread('data/accel.txt','\t');
accel = struct('seconds', accel(:,1), 'kph', accel(:,2));
accel.time = 0.5* ((0+10) + (10-(0))*((2*accel.seconds - (1+21))/(21-(1))) ); 

figure
plot(ftp75.seconds, ftp75.kph);
title('FTP75 drive cycle');
xlabel('time (s)','FontSize',11)
ylabel('speed (km/h)','FontSize',11)

figure
plot(nedc.seconds, nedc.kph);
title('NEDC drive cycle');
xlabel('time (s)','FontSize',11)
ylabel('speed (km/h)','FontSize',11)

