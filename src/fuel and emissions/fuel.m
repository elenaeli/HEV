% Read fuel consumption data for Toyota Prius from 1999
fileSpeed = fopen('data/speed_rpm.txt','r');
fileTorque = fopen('data/torque_nm.txt','r');
fileFuel = fopen('data/fuel_gps.txt','r');
filePower = fopen('data/power_kw.txt','r');

formatSpec = '%f';

FuelCons = struct('speed_rpm',[], 'torque_Nm',[], 'fuel_gps',[]);

FuelCons.speed_rpm = fscanf(fileSpeed,formatSpec);
FuelCons.torque_Nm = fscanf(fileTorque,formatSpec);
FuelCons.power_kw = fscanf(filePower,formatSpec);
fuel_galps = fscanf(fileFuel,formatSpec);

gasoline_grams_per_m3 = 719.7 * 1000;    % density 719.7 kg/m3 * 1000 grams
gallons_per_m3 = 264.172;

FuelCons.fuel_gps = (fuel_galps / gallons_per_m3) * gasoline_grams_per_m3;

num_points_fuel = 10;
FuelConsTable.speed = linspace(min(FuelCons.speed_rpm), max(FuelCons.speed_rpm), num_points_fuel);
FuelConsTable.torque = linspace(min(FuelCons.torque_Nm), max(FuelCons.torque_Nm), num_points_fuel);
FuelConsTable.fuel = linspace(min(FuelCons.fuel_gps), max(FuelCons.fuel_gps), num_points_fuel);
FuelConsTable.power = linspace(min(FuelCons.power_kw), max(FuelCons.power_kw), num_points_fuel);

[speedMeshgridFuel, torqueMeshgridFuel] = meshgrid(FuelConsTable.speed, FuelConsTable.torque);
x = horzcat(FuelConsTable.speed(:), FuelConsTable.torque(:));

fuelFit = fit([FuelConsTable.speed(:), FuelConsTable.torque(:)], FuelConsTable.fuel(:), 'poly22', 'Normalize', 'on');
powerFit = fit([FuelConsTable.speed(:), FuelConsTable.torque(:)], FuelConsTable.power(:), 'poly23', 'Normalize', 'on');
FuelConsTable.lookupTableFuel = fuelFit(speedMeshgridFuel,torqueMeshgridFuel);
FuelConsTable.lookupTablePower = powerFit(speedMeshgridFuel,torqueMeshgridFuel);


figure
plot3(FuelCons.speed_rpm, FuelCons.torque_Nm, FuelCons.fuel_gps,'o','MarkerFaceColor','blue','MarkerEdgeColor','white');
grid on
box on
xlabel('Engine Speed (rpm)','FontSize',11)
ylabel('Engine Torque (Nm)','FontSize',11)
zlabel('Fuel Rate (g/s)','FontSize',11)
title('Fuel Consumption','FontSize',13,'FontWeight','Bold')
set(gca,'XLim',[1200 4100]);
set(gca,'YLim',[20 110]);
set(gca,'ZLim',[0 2.85]);

figure
plot3(FuelCons.speed_rpm, FuelCons.torque_Nm, FuelCons.power_kw,'o','MarkerFaceColor','blue','MarkerEdgeColor','white');
grid on
box on
xlabel('Engine Speed (rpm)','FontSize',11)
ylabel('Engine Torque (Nm)','FontSize',11)
zlabel('Power (kW)','FontSize',11)
title('Power Consumption','FontSize',13,'FontWeight','Bold')
set(gca,'XLim',[1200 4100]);
set(gca,'YLim',[20 110]);
set(gca,'ZLim',[0 45]);

