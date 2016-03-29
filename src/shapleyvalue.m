function [ shEngine, shMotor ] = shapleyvalue( payoffWholeCoal1, payoffMotorCoal, ...
    payoffEngineCoal)

    % 1/2 * (v12 - v2)
    shEngine = 1/2 * (payoffWholeCoal1(3,3) - payoffMotorCoal(3,3)) + ...
        1/2 * payoffEngineCoal(3,3);
    % 1/2 * (v12 - v1)
    shMotor = 1/2 * (payoffWholeCoal1(3,3) - payoffEngineCoal(3,3)) + ...
        1/2 * payoffMotorCoal(3,3);
    
    

end

