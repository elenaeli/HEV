%% Kalai-Smorodinsky
% It is the intersection of the line between the ideal point where both 
% players get minimum payoffs and the conflict point (the same as in 
% Nash Solution. The conflict point is taken to be the Nash 
% Equilibrium) with the Pareto Front.
function [ ks, linePareto] = kalaismorodinskysolution( payoffBoth, conflictPoint, pareto, paretoStrInd )    
    coder.extrinsic('ismembertol');
    
    % ideal point m (often not feasible)
    m1 = min(payoffBoth(:,1));
    m2 = min(payoffBoth(:,2));    
     
    % conflict and ideal point
    cP = [payoffBoth(conflictPoint,1) payoffBoth(conflictPoint,2)];
    mP = [m1 m2];
    xCM = [cP(1) mP(1)];
    yCM = [cP(2) mP(2)];
   
    % j = 1 for different x and same y
    % j = 2 for different y and same x (for the ideal and conflict points)
    if mP(2) == cP(2)
        j = 1;
    elseif mP(1) == cP(1)
        j = 2;
    else
        j = 1;        
    end
   
    % interpolate to get points between ideal and conflict point
    if mP(j) < cP(j) 
        X = linspace(mP(j), cP(j), 5);
        interpolate(j, xCM, yCM, X);
    elseif mP(j) > cP(j)
        X = linspace(cP(j), mP(j), 5);  
        interpolate(j, xCM, yCM, X);
    end
   
    % if there are repeating X points 
    if size(unique(pareto(:,1)),1) < size(pareto(:,1),1)
        % sort pareto points according to second column (Y vaules)   
        xy = 2;
        paretoStrInd = sortrows(paretoStrInd,2);
        pareto = paretoStrInd(:,1:2);
    else
        % sort pareto points according to first column (X vaules)   
        xy = 1;
        paretoStrInd = sortrows(paretoStrInd,1);
        pareto = paretoStrInd(:,1:2);
    end
    
    xPar = zeros(1,size(pareto,1));
    yPar = zeros(1,size(pareto,1));
    % get x and y coordinates of all pareto points
    for i = 1: size(pareto,1)       
        xPar(i) = pareto(i,1);
        yPar(i) = pareto(i,2);       
    end
    coder.varsize('payoffParetoFront', [500,5]);    
    % according to the number of pareto points
    if size(pareto,1) == 1
        payoffParetoFront = horzcat(xPar, yPar);
    else
        % interpolate from smaller to bigger x coordinate (1st to 2nd
        % Pareto point)  
        if xy == 2        
            yP12 = linspace(pareto(1,2),pareto(2,2),100);
            xP12 = interp1(yPar(1:2), xPar(1:2), yP12); 
        else
            xP12 = linspace(pareto(1,1),pareto(2,1),100); 
            yP12 = interp1(xPar(1:2), yPar(1:2), xP12);     
        end     
        payoffParetoFront = horzcat(xP12', yP12');
        if size(pareto,1) >= 3
            % interpolate from smaller to bigger x/y coordinate (2nd to 3rd
            % Pareto point)      
            if xy == 2
                yP23 = linspace(pareto(2,2),pareto(3,2),100);           
                xP23 = interp1(yPar(2:3), xPar(2:3), yP23);
            else
                xP23 = linspace(pareto(2,1),pareto(3,1),100);           
                yP23 = interp1(xPar(2:3), yPar(2:3), xP23);
            end           
            payoffParetoFront = horzcat(vertcat(xP12',xP23'), vertcat(yP12',yP23'));
            if size(pareto,1) >= 4        
                % interpolate from smaller to bigger x/y coordinate (3rd
                % to 4th Pareto point)   
                if xy == 2
                    yP34 = linspace(pareto(3,2),pareto(4,2),100);               
                    xP34 = interp1(yPar(3:4), xPar(3:4), yP34);
                else                   
                    xP34 = linspace(pareto(3,1),pareto(4,1),100);               
                    yP34 = interp1(xPar(3:4), yPar(3:4), xP34);
                end
                payoffParetoFront = horzcat(vertcat(xP12',xP23',xP34'), vertcat(yP12',yP23',yP34'));
                if size(pareto,1) >= 5   
                    % interpolate from smaller to bigger x/y coordinate
                    % (4th to 5th Pareto point)   
                    if xy == 2
                        yP45 = linspace(pareto(4,2),pareto(5,2),100);                                   
                        xP45 = interp1(yPar(4:5), xPar(4:5), yP45);                   
                    else
                        xP45 = linspace(pareto(4,j),pareto(5,j),100);                                   
                        yP45 = interp1(xPar(4:5), yPar(4:5), xP45);
                    end
                    payoffParetoFront = horzcat(vertcat(xP12',xP23',xP34',xP45'), vertcat(yP12',yP23',yP34',yP45'));
                end
            end         
        end
    end
            
    ks = zeros(1,2);   
    r = zeros(1,size(payoffParetoFront,1));
    l = zeros(1,size(payoffParetoFront,1));  
    
    for u = 1 : size(payoffParetoFront,1)       
        % as in the KS equation
        u2c2 = -payoffParetoFront(u,2) + payoffBoth(conflictPoint,2);
        u1c1 = -payoffParetoFront(u,1) + payoffBoth(conflictPoint,1);
        m2c2 = -m2 + payoffBoth(conflictPoint,2);
        m1c1 = -m1 + payoffBoth(conflictPoint,1);
        % left and right side of the KS equation definition
        l(u) = u2c2 / u1c1;
        r(u) = m2c2 / m1c1;
        
        % if either the numerator or denominator is 0, make the whole side
        % 0 to avoid NaN if denominator is 0.
        if all(u2c2 == 0) || all(u1c1 == 0)
            l(u) = 0;              
        end
        if all(m2c2 == 0) || all( m1c1 == 0)
            r(u) = 0;
        end        
    end    
    diff = r - l;
    % take the minimum absolute difference to be the KS solution
    [~, minInd] = min(abs(diff));    
    ks(1,1) = payoffParetoFront(minInd,1);
    ks(1,2) = payoffParetoFront(minInd,2); 
    
    if ismembertol(ks ,payoffBoth,0.0001,'ByRows',true);
        linePareto = [];
    else
        linePareto = zeros(2,4);
        % if only one Pareto point, then the Pareto frontier line is the
        % point itself
        if size(paretoStrInd,1) == 1
             linePareto = paretoStrInd;
        % if more than one Pareto points, save the points as the Pareto 
        % frontier 
        else
            for i = 1: size(paretoStrInd,1)-1
                if ks(1,1) >= paretoStrInd(i,1) && ks(1,1) <= paretoStrInd(i+1,1)
                    linePareto(1,:) = paretoStrInd(i,:);
                    linePareto(2,:) = paretoStrInd(i+1,:);
                end
            end
        end
    end
end