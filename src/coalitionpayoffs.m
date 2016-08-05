%% Compute coalition payoffs
% according to torque deviation
function [ payoffWholeCoal, coeffCoal, payoffEngineCoal, payoffMotorCoal, payoffWholeCoalBefore ] = coalitionpayoffs( payoffMotor, ...
    payoffEngine, torqDev, percentReqTorque )   
    coeffCoal = ones(size(payoffEngine,1), size(payoffEngine,2));
    
    % the smaller the torque deviation, the smaller we make the payoff of
    % the coalition. Multiplying with coefficients from 0.99 to 1, the best 
    % and smallest torque deviation is multiplied with 0.99 and the worst 
    % with 1
    for i = 1 : size(payoffEngine,1)
        for j = 1 : size(payoffEngine,2)       
            absTorqDev = abs(torqDev(i,j));
            if -percentReqTorque(2) < torqDev(i,j) && torqDev(i,j) < 0    
               coeffCoal(i,j) = 0.991;      
            elseif torqDev(i,j) == 0
                coeffCoal(i,j) = 0.99;
            elseif 0 < torqDev(i,j) && torqDev(i,j) < percentReqTorque(2)
                coeffCoal(i,j) = 0.992;                            
            elseif percentReqTorque(2) < absTorqDev && absTorqDev < percentReqTorque(3)
                coeffCoal(i,j) = 0.993;    
            elseif percentReqTorque(3) < absTorqDev && absTorqDev < percentReqTorque(4)
                coeffCoal(i,j) = 0.994;    
            elseif percentReqTorque(4) < absTorqDev && absTorqDev < percentReqTorque(5)
                coeffCoal(i,j) = 0.995;    
            elseif percentReqTorque(5) < absTorqDev && absTorqDev < percentReqTorque(6)
                coeffCoal(i,j) = 0.996;
            elseif percentReqTorque(6) < absTorqDev && absTorqDev < percentReqTorque(7)
                coeffCoal(i,j) = 0.997;   
            elseif percentReqTorque(7) < absTorqDev && absTorqDev < percentReqTorque(8)
                coeffCoal(i,j) = 0.998;   
            elseif percentReqTorque(8) < absTorqDev && absTorqDev < percentReqTorque(9)
                coeffCoal(i,j) = 0.999;   
            elseif absTorqDev < -percentReqTorque(9) || percentReqTorque(9) < absTorqDev;    
                coeffCoal(i,j) = 1.0;   
            end            
        end
    end   
    payoffWholeCoalBefore = payoffEngine + payoffMotor;
    payoffEngineCoal = payoffEngine .* coeffCoal;
    payoffMotorCoal = payoffMotor .* coeffCoal;
    payoffWholeCoal = payoffEngineCoal + payoffMotorCoal;
end