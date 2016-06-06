function [ bestPayoffEngPareto, bestPayoffMotPareto ] = bestparetoNew( paretoStrategies, paretoIndex, ...
	torqueDeviation, fuelConsRate, fuelConsumed, emissions)  
    for r = 1 : size(paretoIndex,1)
        torqueDeviationPareto(1,r) = torqueDeviation(paretoIndex(r,1), paretoIndex(r,2));
        fuel = fuelConsumed & fuelConsRate(1,r);
        torqEmis = torqueDeviationPareto(1,r)  || emissions(1,r);
        final = fuel & torqEmis
    end
    
end
