function [ bestPayoffEngPareto, bestPayoffMotPareto ] = bestparetoNew( paretoStrategies, paretoIndex, ...
	torqueDeviation, fuelConsRate, fuelConsumed, emissions)

    torqueDeviationPareto = zeros(size(paretoIndex,1),1);
    fuelConsRatePareto = zeros(size(paretoIndex,1),1);
    emissionsPareto = zeros(size(paretoIndex,1),1);
    final = zeros(size(paretoIndex,1),1);   
    bestPayoffEngPareto = 0;
    bestPayoffMotPareto = 0;

    minTorqueDeviationPareto = min(min(abs(torqueDeviation)))
    minFuelConsRatePareto = min(abs(fuelConsRate))
    minEmissions = min(abs(emissions))
   
    for r = 1 : size(paretoIndex,1)
        abs(torqueDeviation(paretoIndex(r,1), paretoIndex(r,2)))
        fuelConsumed
        abs(fuelConsRate(paretoIndex(r,1),1))
        abs(emissions(paretoIndex(r,1),1))
        % > min torque difference from all payoffs
        if abs(torqueDeviation(paretoIndex(r,1), paretoIndex(r,2))) > minTorqueDeviationPareto
            torqueDeviationPareto(r,1) = 0;
        else
            torqueDeviationPareto(r,1) = 1;
        end
        % > 1 liter
        if fuelConsumed > 1
            fuelConsumedPareto = 0;
        else
            fuelConsumedPareto = 1;
        end
        % > min gps cons rate from all payoffs
        if abs(fuelConsRate(paretoIndex(r,1),1)) > minFuelConsRatePareto
            fuelConsRatePareto(r,1) = 0;
        else
            fuelConsRatePareto(r,1) = 1;
        end
        % > min emissions from all payoffs
        if abs(emissions(paretoIndex(r,1),1)) > minEmissions
            emissionsPareto(r,1) = 0;
        else
            emissionsPareto(r,1) = 1;
        end
        torqueDeviationPareto(r,1)
        fuelConsumedPareto
        fuelConsRatePareto(r,1)       
        emissionsPareto(r,1)
        
        fuel = fuelConsumedPareto & fuelConsRatePareto(r,1);
        torqEmis = torqueDeviationPareto(r,1) || emissionsPareto(r,1);
        final(r,1) = fuel & torqEmis;
        r
    end
    ind = find(final)
    final
    if size(ind,1) == 1
        bestPayoffEngPareto = paretoStrategies(ind,1);
        bestPayoffMotPareto = paretoStrategies(ind,2);
    elseif size(ind,1) > 1        
        bestPayoffEngPareto = paretoStrategies(ind(1),1);
        bestPayoffMotPareto = paretoStrategies(ind(1),2);
    end    
    if bestPayoffEngPareto==0 || bestPayoffEngPareto==0
       bestPayoffEngPareto = paretoStrategies(1,1);
       bestPayoffMotPareto = paretoStrategies(1,2);     
    end
    
   bestPayoffEngPareto
   bestPayoffMotPareto
end
