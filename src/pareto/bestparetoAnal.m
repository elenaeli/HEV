function [ bestPayoffEngPareto, bestPayoffMotPareto ] = bestparetoAnal( paretoStrategies, paretoIndex, ...
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
    
    torqueDeviationPareto = 1 + 99.*(torqueDeviationPareto - min(torqueDeviationPareto))./(max(torqueDeviationPareto) - min(torqueDeviationPareto));
    fuelConsRatePareto = 1 + 99.*(fuelConsRatePareto - min(fuelConsRatePareto))./(max(fuelConsRatePareto) - min(fuelConsRatePareto));
    emissionsPareto = 1 + 99.*(emissionsPareto - min(emissionsPareto))./(max(emissionsPareto) - min(emissionsPareto));
    
    %0.5* ((0+10) + (10-(0))*((2*torqueDeviationPareto - (0+100))/(100-(0))) );
    for r = 1 : size(paretoIndex,1)
        f = analogicalOR(fuelConsRatePareto(r,1), fuelConsumed);
        ft = analogicalOR(f, torqueDeviationPareto(r,1));
        fte(r,1) = analogicalAND(ft, emissionsPareto(r,1));
    end
    
    [~,i] = min(fte);
    bestPayoffEngPareto = paretoStrategies(i,1);
    bestPayoffMotPareto = paretoStrategies(i,2);
    
    % take the first Pareto point if no solution has been chosen
    if bestPayoffEngPareto==0 || bestPayoffMotPareto==0
       bestPayoffEngPareto = paretoStrategies(1,1);
       bestPayoffMotPareto = paretoStrategies(1,2);     
    end   
end