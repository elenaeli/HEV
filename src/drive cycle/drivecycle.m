% Prepare FTP75 data

ftp75M = dlmread('data/ftp75_s_mph_reduced.txt','\t');

%split into 5 phases, always begin at 0s, 1.60934 is to transform mph to km/h
ftp75 = struct('seconds', ftp75M(:,1), 'kph', ftp75M(:,2)* 1.60934);
ftp75_1 = struct('seconds', ftp75M(1:32,1), 'kph', ftp75M(1:32,2)* 1.60934);
ftp75_2 = struct('seconds', ftp75M(32:62,1)-340, 'kph', ftp75M(32:62,2)* 1.60934);
ftp75_3 = struct('seconds', ftp75M(62:90,1)-680, 'kph', ftp75M(62:90,2)* 1.60934);
ftp75_4 = struct('seconds', ftp75M(90:128,1)-1030, 'kph', ftp75M(90:128,2)* 1.60934);
ftp75_5 = struct('seconds', ftp75M(128:end,1)-1500, 'kph', ftp75M(128:end,2)* 1.60934);

% NEDC drive cycle
nedcM = dlmread('data/nedc_s_kph.txt','\t');
nedc = struct('seconds', nedcM(:,1), 'kph', nedcM(:,2));

% plots
figure
plot(ftp75.seconds, ftp75.kph, 'LineWidth', 2);
title('FTP75 drive cycle');
xlabel('time (s)','FontSize',11)
ylabel('speed (km/h)','FontSize',11)

figure
plot(nedc.seconds, nedc.kph);
title('NEDC drive cycle');
xlabel('time (s)','FontSize',11)
ylabel('speed (km/h)','FontSize',11)

