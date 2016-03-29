function [ payoffWholeCoal, coeffCoal, payoffEngineCoal, payoffMotorCoal, payoffWholeCoalBefore ] = coalitionpayoffs( payoffMotor, ...
    payoffEngine, torqDev, percentReqTorque )   
    coeffCoal = ones(size(payoffEngine,1), size(payoffEngine,2));
    
    for i = 1 : size(payoffEngine,1)
        for j = 1 : size(payoffEngine,2)       
                absTorqDev = abs(torqDev(i,j));
                if -percentReqTorque(2) < torqDev(i,j) && torqDev(i,j) < 0    
                    coeffCoal(i,j) = 0.5;      
                elseif torqDev(i,j) == 0
                    coeffCoal(i,j) = 0.4;
                elseif 0 < torqDev(i,j) && torqDev(i,j) < percentReqTorque(2)
                    coeffCoal(i,j) = 0.6;                            
                elseif percentReqTorque(2) < absTorqDev && absTorqDev < percentReqTorque(3)
                    coeffCoal(i,j) = 0.65;    
                elseif percentReqTorque(3) < absTorqDev && absTorqDev < percentReqTorque(4)
                    coeffCoal(i,j) = 0.7;    
                elseif percentReqTorque(4) < absTorqDev && absTorqDev < percentReqTorque(5)
                    coeffCoal(i,j) = 0.75;    
                elseif percentReqTorque(5) < absTorqDev && absTorqDev < percentReqTorque(6)
                    coeffCoal(i,j) = 0.8;
                elseif percentReqTorque(6) < absTorqDev && absTorqDev < percentReqTorque(7)
                    coeffCoal(i,j) = 0.85;   
                elseif percentReqTorque(7) < absTorqDev && absTorqDev < percentReqTorque(8)
                    coeffCoal(i,j) = 0.9;   
                elseif percentReqTorque(8) < absTorqDev && absTorqDev < percentReqTorque(9)
                    coeffCoal(i,j) = 0.95;   
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

