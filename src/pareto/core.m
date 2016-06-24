function [ bestPayoffEngPareto, bestPayoffMotPareto ] = bestparetoAnal( paretoStrategies, paretoIndex, ...
	torqueDeviation, fuelConsRate, fuelConsumed, emissions)  
    
    torqueDeviationPareto = zeros(size(paretoIndex,1),1);
    fuelConsRatePareto = zeros(size(paretoIndex,1),1);
    emissionsPareto = zeros(size(paretoIndex,1),1);
    
    for r = 1 : size(paretoIndex,1)
        torqueDeviationPareto(r,1) = abs(torqueDeviation(paretoIndex(r,1), paretoIndex(r,2)));
        fuelConsRatePareto(r,1) = abs(fuelConsRate(paretoIndex(r,1),1));
        emissionsPareto(r,1) = abs(emissions(paretoIndex(r,1),1));
        
    end
    torqueDeviationPareto = 0.5* ((0+10) + (10-(0))*((2*torqueDeviationPareto - (0+100))/(100-(0))) );
    fuelConsRatePareto = 0.5* ((0+10) + (10-(0))*((2*fuelConsRatePareto - (0+100))/(100-(0))) );
    emissionsPareto = 0.5* ((0+10) + (10-(0))*((2*emissionsPareto - (0+100))/(100-(0))) );
end

