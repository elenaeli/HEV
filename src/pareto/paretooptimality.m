%% Pareto Optimality
% Choose best Pareto efficient point from the set of all points using
% Analogical gates.

function [ bestPayoffEngPareto, bestPayoffMotPareto ] = paretooptimality( paretoStrategies, paretoIndex, ...
	torqueDeviation, fuelConsRate, fuelConsumed, emissions)  

    torqueDeviationPareto = zeros(size(paretoIndex,1),1);
    fuelConsRatePareto = zeros(size(paretoIndex,1),1);
    emissionsPareto = zeros(size(paretoIndex,1),1);
    fte = zeros(size(paretoIndex,1),1);   
    
    bestPayoffEngPareto = 0;
    bestPayoffMotPareto = 0;
    
    for r = 1 : size(paretoIndex,1)
        torqueDeviationPareto(r,1) = abs(torqueDeviation(paretoIndex(r,1), paretoIndex(r,2)));
        fuelConsRatePareto(r,1) = abs(fuelConsRate(paretoIndex(r,1),1));
        emissionsPareto(r,1) = abs(emissions(paretoIndex(r,1),1));        
    end
    % make torque deviation, fuel and emissions within the range 0-100
    torqueDeviationPareto = 1 + 99.*(torqueDeviationPareto - min(torqueDeviationPareto))./(max(torqueDeviationPareto) - min(torqueDeviationPareto));
    fuelConsRatePareto = 1 + 99.*(fuelConsRatePareto - min(fuelConsRatePareto))./(max(fuelConsRatePareto) - min(fuelConsRatePareto));
    emissionsPareto = 1 + 99.*(emissionsPareto - min(emissionsPareto))./(max(emissionsPareto) - min(emissionsPareto));

    % functions for analogical AND and OR
    for r = 1 : size(paretoIndex,1)
        % combine fuel consumption rate and fuel consumed 
        f = analogicalOR(fuelConsRatePareto(r,1), fuelConsumed);
        % combine the output with torque deviation
        ft = analogicalOR(f, torqueDeviationPareto(r,1));
        % combine the output with emissions
        fte(r,1) = analogicalAND(ft, emissionsPareto(r,1));
    end
    
    % take the Pareto efficient outcome with minimum output
    [~,i] = min(fte);
    bestPayoffEngPareto = paretoStrategies(i,1);
    bestPayoffMotPareto = paretoStrategies(i,2);
    
    % take the first Pareto point if no solution has been chosen
    if bestPayoffEngPareto==0 || bestPayoffMotPareto==0
       bestPayoffEngPareto = paretoStrategies(1,1);
       bestPayoffMotPareto = paretoStrategies(1,2);     
    end   
end