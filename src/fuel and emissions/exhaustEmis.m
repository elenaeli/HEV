function GasEmisTable = exhaustEmissions()
fileSpeed = fopen('data/speed_rpm.txt','r');
fileTorque = fopen('data/torque_nm.txt','r');

fileHC = fopen('data/hc_gps.txt','r');
fileCO = fopen('data/co_gps.txt','r');
fileNOX = fopen('data/nox_gps.txt','r');
formatSpec = '%f';
coder.extrinsic('fscanf')
coder.extrinsic('fit')
coder.extrinsic('float')

GasEmis = struct('speed_rpm',[], 'torque_Nm',[], 'hc_gps',[], 'co_gps',[], 'nox_gps',[]);
GasEmisTable = struct ('speed', [], 'torque', [], 'hc', [], 'nox', [], 'co', [], 'lookupTableHC', zeros(10,10), 'lookupTableCO', zeros(10,10), 'lookupTableNOX', zeros(10,10));
GasEmis.speed_rpm = fscanf(fileSpeed,formatSpec);
GasEmis.torque_Nm = fscanf(fileTorque,formatSpec);
GasEmis.hc_gps = fscanf(fileHC,formatSpec);
GasEmis.co_gps = fscanf(fileCO,formatSpec);
GasEmis.nox_gps = fscanf(fileNOX,formatSpec);

num_points_gas = 10;
GasEmisTable.speed = linspace(float(min(GasEmis.speed_rpm)), max(GasEmis.speed_rpm), num_points_gas);
GasEmisTable.torque = linspace(float(min(GasEmis.torque_Nm)), max(GasEmis.torque_Nm), num_points_gas);
GasEmisTable.hc = linspace(float(min(GasEmis.hc_gps)), max(GasEmis.hc_gps), num_points_gas);
GasEmisTable.nox = linspace(float(min(GasEmis.nox_gps)), max(GasEmis.nox_gps), num_points_gas);
GasEmisTable.co = linspace(float(min(GasEmis.co_gps)), max(GasEmis.co_gps), num_points_gas);

[speedMeshgridGas, torqueMeshgridGas] = meshgrid(GasEmisTable.speed, GasEmisTable.torque);
gasFitHC = fit([GasEmisTable.speed(:), GasEmisTable.torque(:)], GasEmisTable.hc(:), 'poly22');
GasEmisTable.lookupTableHC = feval(gasFitHC,speedMeshgridGas,torqueMeshgridGas);

gasFitCO = fit([GasEmisTable.speed(:), GasEmisTable.torque(:)], GasEmisTable.co(:), 'poly22');
GasEmisTable.lookupTableCO = feval(gasFitCO,speedMeshgridGas,torqueMeshgridGas);

gasFitNOX = fit([GasEmisTable.speed(:), GasEmisTable.torque(:)], GasEmisTable.nox(:), 'poly22');
GasEmisTable.lookupTableNOX = feval(gasFitNOX,speedMeshgridGas,torqueMeshgridGas);
close all

figure
plot3(GasEmis.speed_rpm, GasEmis.torque_Nm, GasEmis.hc_gps,'o','MarkerFaceColor','blue','MarkerEdgeColor','white');
grid on
box on
xlabel('Engine Speed (rpm)','FontSize',11)
ylabel('Engine Torque (Nm)','FontSize',11)
zlabel('HC Emissions (g/s)','FontSize',11)
title('Hydrogen Carbon Emissions','FontSize',13,'FontWeight','Bold')
set(gca,'XLim',[1200 4100]);
set(gca,'YLim',[20 110]);
set(gca,'ZLim',[0 0.06]);

figure
plot3(GasEmis.speed_rpm, GasEmis.torque_Nm, GasEmis.co_gps,'o','MarkerFaceColor','blue','MarkerEdgeColor','white');
grid on
box on
xlabel('Engine Speed (rpm)','FontSize',11)
ylabel('Engine Torque (Nm)','FontSize',11)
zlabel('CO Emissions (g/s)','FontSize',11)
title('Carbon Oxide Emissions','FontSize',13,'FontWeight','Bold')
set(gca,'XLim',[1200 4100]);
set(gca,'YLim',[20 110]);
set(gca,'ZLim',[0 0.22]);

figure
plot3(GasEmis.speed_rpm, GasEmis.torque_Nm, GasEmis.nox_gps,'o','MarkerFaceColor','blue','MarkerEdgeColor','white');
grid on
box on
xlabel('Engine Speed (rpm)','FontSize',11)
ylabel('Engine Torque (Nm)','FontSize',11)
zlabel('NOX Emissions (g/s)','FontSize',11)
title('Nitrogen Oxide Emissions','FontSize',13,'FontWeight','Bold')
set(gca,'XLim',[1200 4100]);
set(gca,'YLim',[20 110]);
set(gca,'ZLim',[0 0.16]);
end

