function [ bestPayoffEngPareto, bestPayoffMotPareto ] = bestpareto( paretoStrategies, paretoIndex, ...
    torqueDeviation, fuel, nox, power )
    payoffEngPareto = zeros(1,size(paretoIndex,1));
    payoffMotPareto = zeros(1,size(paretoIndex,1));
    torqueDeviationPareto = zeros(1,size(paretoIndex,1));
    fuelPareto = zeros(1,size(paretoIndex,1));
    noxPareto = zeros(1,size(paretoIndex,1));
    powerPareto = zeros(1,size(paretoIndex,1));
    for r = 1 : size(paretoIndex,1)
        payoffEngPareto(1,r) = paretoStrategies(r,1);
        payoffMotPareto(1,r) = paretoStrategies(r,2);
        torqueDeviationPareto(1,r) = torqueDeviation(paretoIndex(r,1), paretoIndex(r,2));
        fuelPareto(1,r) = fuel(paretoIndex(r,1),1);
        noxPareto(1,r) = nox(paretoIndex(r,1),1);
        powerPareto(1,r) = power(paretoIndex(r,1),1);
    end        
       
    bestTorqDevPareto = min(abs(torqueDeviationPareto));
       
    % check if more than 1 points have same torque deviation
    indT = find(abs(torqueDeviationPareto)==bestTorqDevPareto);   
    if size(indT,2) > 1
        % take the point with minimum fuel consumption
        bestFuelPareto = min(fuelPareto);
        % check if more than 1 points have same fuel consumption
        indF = find(fuelPareto==bestFuelPareto);
        bestPayoffFuelPareto = paretoStrategies(indF,:);
        if size(indF,2) > 1
            % take the point with the minimum motor power consumed
            [~,indE] = min(powerPareto(indF));
            bestPayoffEngPareto = bestPayoffFuelPareto(indE,1); 
            bestPayoffMotPareto = bestPayoffFuelPareto(indE,2);
        else
            bestPayoffEngPareto = bestPayoffFuelPareto(1,1);   
            bestPayoffMotPareto = bestPayoffFuelPareto(1,2);
        end
    else
        bestPayoffEngPareto = paretoStrategies(indT,1);
        bestPayoffMotPareto = paretoStrategies(indT,2);
    end    
end

