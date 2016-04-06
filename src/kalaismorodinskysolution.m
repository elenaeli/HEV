function [ ks] = kalaismorodinskysolution( payoffBoth, conflictPoint, pareto )    
    % A function to find the Kalai Smorodinsky bargaining solution. It
    % is the intersection of the line between the ideal point where both 
    % players get minimum payoffs and the conflict point (the same as in 
    % Nash Solution. The conflict point is taken to be the Nash 
    % Equilibrium) with the Pareto Front.
    
    % ideal point m (often not feasible)
    m1 = min(payoffBoth(:,1));
    m2 = min(payoffBoth(:,2));    
    darkred = [185 16 20] ./ 255;
    %plot(m1, m2, 'o', 'MarkerSize', 3, 'MarkerFaceColor',darkred ,...
    %    'MarkerEdgeColor', darkred);
   
    % conflict and ideal point
    cP = [payoffBoth(conflictPoint,1) payoffBoth(conflictPoint,2)]
    mP = [m1 m2]
    xCM = [cP(1) mP(1)];
    yCM = [cP(2) mP(2)];
   
    % j = 1 for different x and same y
    % j = 2 for different y and same x (for the ideal and conflict points)
    if mP(2) == cP(2)
        j = 1;
    elseif mP(1) == cP(1)
        j = 2;
    elseif mP(1) ~= cP(1) && mP(2) ~= cP(2)       
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
        
    % get x and y coordinates of all pareto points
    for i = 1: size(pareto,1)       
        xPar(i) = pareto(i,1);
        yPar(i) = pareto(i,2);       
    end
    
    % according to the number of pareto points
    if size(pareto,1) == 1
        payoffParetoFront = horzcat(xPar, yPar)  
    elseif size(pareto,1) >= 2
        % interpolate from smaller to bigger x coordinate (1st to 2nd
        % pareto point)
        if pareto(1,1) < pareto(2,1)
            xP12 = linspace(pareto(1,1),pareto(2,1),30);
        else
            xP12 = linspace(pareto(2,1),pareto(1,1),30);
        end
        yP12 = interp1(xPar(1:2), yPar(1:2), xP12);
        plot(xP12,yP12,'b');
        
        if size(pareto,1) == 2
            payoffParetoFront = horzcat(xP12', yP12');
        elseif size(pareto,1) == 3
            % interpolate from smaller to bigger x coordinate (2nd to 3rd
            % pareto point)
            if pareto(2,1) < pareto(3,1)
                xP23 = linspace(pareto(2,1),pareto(3,1),10);
            else
                xP23 = linspace(pareto(3,1),pareto(2,1),10);
            end
            yP23 = interp1(xPar(2:3), yPar(2:3), xP23);
            plot(xP23, yP23,'b');           
            payoffParetoFront = horzcat(vertcat(xP12',xP23'), vertcat(yP12',yP23'));          
        end          
    end
            
    ks(1,1) = Inf;
    ks(1,2) = Inf;   
    r = zeros(1,size(payoffParetoFront,1));
    l = zeros(1,size(payoffParetoFront,1));  
    
    for u = 1 : size(payoffParetoFront,1)       
        u2c2 = -payoffParetoFront(u,2) + payoffBoth(conflictPoint,2);
        u1c1 = -payoffParetoFront(u,1) + payoffBoth(conflictPoint,1);
        m2c2 = -m2 + payoffBoth(conflictPoint,2);
        m1c1 = -m1 + payoffBoth(conflictPoint,1);
        % left and right side of the KS equation definition
        l(u) = u2c2 / u1c1;
        r(u) = m2c2 / m1c1;
        
        % if either the numerator or denominator is 0, make the whole side
        % 0 to avoid NaN if denominator is 0.
        if u2c2 == 0 || u1c1 == 0
            l(u) = 0;              
        end
        if m2c2 == 0 || m1c1 == 0
            r(u) = 0;    
        end        
    end    
    diff = r - l
    % take the minimum absolute difference to be the KS solution
    [minDiff, minInd] = min(abs(diff))   
    ks(1,1) = payoffParetoFront(minInd,1);
    ks(1,2) = payoffParetoFront(minInd,2); 
  
    % function to interpolate between x and y coordinates of 
    function interpolate(j,x,y,X)
       if j == 1
           Y = interp1(x, y, X);
           plot(X,Y,'r');
       elseif j == 2
           Y = interp1(y, x, X);
           plot(Y,X,'r');
       end
    end

end