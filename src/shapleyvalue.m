function [ shEngine, shMotor ] = shapleyvalue( payoffWholeCoal1, payoffMotorCoal, ...
    payoffEngineCoal, impLinInd)

    % 1/2 * (v12 - v2)
    shEngine = 1/2 * (payoffWholeCoal1(impLinInd(1,1),impLinInd(1,2)) - payoffMotorCoal(impLinInd(1,1),impLinInd(1,2))) + ...
        1/2 * payoffEngineCoal(impLinInd(1,1),impLinInd(1,2));
    % 1/2 * (v12 - v1)
    shMotor = 1/2 * (payoffWholeCoal1(impLinInd(1,1),impLinInd(1,2)) - payoffEngineCoal(impLinInd(1,1),impLinInd(1,2))) + ...
        1/2 * payoffMotorCoal(impLinInd(1,1),impLinInd(1,2));    

end

