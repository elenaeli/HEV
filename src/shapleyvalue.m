function [ shEngine, shMotor ] = shapleyvalue( payoffWholeCoal1, payoffMotorCoal, ...
    payoffEngineCoal, impLinInd)

for i = 1 : size(impLinInd,1)
    % ((k-1)!*(n-k)! / n!) (value(k) - value(k-{i}))   
    
    % 1/2 * (v12 - v2) + 1/2 * v1
    shEngine(i) = 1/2 * (payoffWholeCoal1(impLinInd(i,1),impLinInd(i,2)) - ...
        payoffMotorCoal(impLinInd(i,1),impLinInd(i,2))) + ...
        1/2 * payoffEngineCoal(impLinInd(i,1),impLinInd(i,2));
    % 1/2 * (v12 - v1) + 1/2 * v2
    shMotor(i) = 1/2 * (payoffWholeCoal1(impLinInd(i,1),impLinInd(i,2)) - ...
        payoffEngineCoal(impLinInd(i,1),impLinInd(i,2))) + ...
        1/2 * payoffMotorCoal(impLinInd(i,1),impLinInd(i,2));    

end

