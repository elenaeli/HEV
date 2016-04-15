function [ ks, linePareto] = kalaismorodinskysolution( payoffBoth, conflictPoint, pareto, paretoStrInd )    
    % A function to find the Kalai Smorodinsky bargaining solution. It
    % is the intersection of the line between the ideal point where both 
    % players get minimum payoffs and the conflict point (the same as in 
    % Nash Solution. The conflict point is taken to be the Nash 
    % Equilibrium) with the Pareto Front.
    
    % ideal point m (often not feasible)
    m1 = min(payoffBoth(:,1));
    m2 = min(payoffBoth(:,2));    
    %darkred = [185 16 20] ./ 255;
    %plot(m1, m2, 'o', 'MarkerSize', 3, 'MarkerFaceColor',darkred ,...
    %    'MarkerEdgeColor', darkred);
   
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
    % sort pareto points according to first column (X vaules)   
    paretoStrInd = sortrows(paretoStrInd,1);
    pareto = paretoStrInd(:,1:2);
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
        xP12 = linspace(pareto(1,1),pareto(2,1),100);       
        yP12 = interp1(xPar(1:2), yPar(1:2), xP12);
        plot(xP12,yP12,'b');      
        payoffParetoFront = horzcat(xP12', yP12');
        if size(pareto,1) >= 3
            % interpolate from smaller to bigger x coordinate (2nd to 3rd
            % pareto point)         
            xP23 = linspace(pareto(2,1),pareto(3,1),100);           
            yP23 = interp1(xPar(2:3), yPar(2:3), xP23);
            plot(xP23, yP23,'b');           
            payoffParetoFront = horzcat(vertcat(xP12',xP23'), vertcat(yP12',yP23'));
            if size(pareto,1) >= 4             
                xP34 = linspace(pareto(3,1),pareto(4,1),100);               
                yP34 = interp1(xPar(3:4), yPar(3:4), xP34);
                plot(xP34, yP34,'b');     
                payoffParetoFront = horzcat(vertcat(xP12',xP23',xP34'), vertcat(yP12',yP23',yP34'));
                if size(pareto,1) == 5            
                    xP45 = linspace(pareto(4,1),pareto(5,1),100);                                   
                    yP45 = interp1(xPar(4:5), yPar(4:5), xP45);
                    plot(xP45, yP45,'b');
                    payoffParetoFront = horzcat(vertcat(xP12',xP23',xP34',xP45'), vertcat(yP12',yP23',yP34',yP45'));
                end
            end         
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
    diff = r - l;
    % take the minimum absolute difference to be the KS solution
    [minDiff, minInd] = min(abs(diff));
    ks(1,1) = payoffParetoFront(minInd,1);
    ks(1,2) = payoffParetoFront(minInd,2); 
    
    linePareto = zeros(2,4);
    if size(paretoStrInd,1) == 1
         linePareto = paretoStrInd;
    else
        for i = 1: size(paretoStrInd,1)-1
            if ks(1,1) >= paretoStrInd(i,1) && ks(1,1) <= paretoStrInd(i+1,1)
                linePareto(1,:) = paretoStrInd(i,:);
                linePareto(2,:) = paretoStrInd(i+1,:);
            end
        end
    end    
        
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