function [ payoffWholeCoal, coeffCoal, payoffEngineCoal, payoffMotorCoal, payoffWholeCoalBefore ] = coalitionpayoffs( payoffMotor, ...
    payoffEngine, torqDev, percentReqTorque )   
    coeffCoal = ones(size(payoffEngine,1), size(payoffEngine,2));
    
    for i = 1 : size(payoffEngine,1)
        for j = 1 : size(payoffEngine,2)       
                absTorqDev = abs(torqDev(i,j));
                if -percentReqTorque(2) < torqDev(i,j) && torqDev(i,j) < 0    
                    coeffCoal(i,j) = 0.91;      
                elseif torqDev(i,j) == 0
                    coeffCoal(i,j) = 0.9;
                elseif 0 < torqDev(i,j) && torqDev(i,j) < percentReqTorque(2)
                    coeffCoal(i,j) = 0.92;                            
                elseif percentReqTorque(2) < absTorqDev && absTorqDev < percentReqTorque(3)
                    coeffCoal(i,j) = 0.93;    
                elseif percentReqTorque(3) < absTorqDev && absTorqDev < percentReqTorque(4)
                    coeffCoal(i,j) = 0.94;    
                elseif percentReqTorque(4) < absTorqDev && absTorqDev < percentReqTorque(5)
                    coeffCoal(i,j) = 0.95;    
                elseif percentReqTorque(5) < absTorqDev && absTorqDev < percentReqTorque(6)
                    coeffCoal(i,j) = 0.96;
                elseif percentReqTorque(6) < absTorqDev && absTorqDev < percentReqTorque(7)
                    coeffCoal(i,j) = 0.97;   
                elseif percentReqTorque(7) < absTorqDev && absTorqDev < percentReqTorque(8)
                    coeffCoal(i,j) = 0.98;   
                elseif percentReqTorque(8) < absTorqDev && absTorqDev < percentReqTorque(9)
                    coeffCoal(i,j) = 0.99;   
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

