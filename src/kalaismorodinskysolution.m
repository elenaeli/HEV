function [ ks] = kalaismorodinskysolution( payoffBoth, c, pareto )    
  
    % ideal point m
    m1 = min(payoffBoth(:,1));
    m2 = min(payoffBoth(:,2));    
    plot(m1,m2,'o', 'MarkerSize', 3);
    
    % conflict and ideal point
    cP = [payoffBoth(c,1) payoffBoth(c,2)]
    mP = [m1 m2]
    x = [cP(1) mP(1)];
    y = [cP(2) mP(2)];
   
    % j = 1 for different x and same y
    % j = 2 for different y and same x (for the ideal and conflict points)
    if mP(2) == cP(2)
        j = 1;
    elseif mP(1) == cP(1)
        j = 2;
    elseif mP(1) ~= cP(1) && mP(2) ~= cP(2)       
        j = 1;        
    end
    
    % interpolate the 
    if mP(j) < cP(j) 
        X = linspace(mP(j),cP(j),5);
        interpolate(j, x, y, X);
    elseif mP(j) > cP(j)
        X = linspace(cP(j),mP(j),5);  
        interpolate(j, x, y, X);
    end 
        
    for i = 1: size(pareto,1)       
        xpar(i) = pareto(i,1);
        ypar(i) = pareto(i,2);       
    end
    if size(pareto,1) == 1
        payoffParetoFront = horzcat(xpar, ypar)  
    elseif size(pareto,1) >= 2
        if pareto(1,1) < pareto(2,1)
            Xp12 = linspace(pareto(1,1),pareto(2,1),10);
        else
            Xp12 = linspace(pareto(2,1),pareto(1,1),10);
        end
        Yp12 = interp1(xpar(1:2), ypar(1:2), Xp12);
        plot(Xp12,Yp12,'b');
        
        if size(pareto,1) == 2
            payoffParetoFront = horzcat(Xp12', Yp12');
        elseif size(pareto,1) == 3
            if pareto(2,1) < pareto(3,1)
                Xp23 = linspace(pareto(2,1),pareto(3,1),10);
            else
                Xp23 = linspace(pareto(3,1),pareto(2,1),10);
            end
            Yp23 = interp1(xpar(2:3), ypar(2:3), Xp23);
            plot(Xp23,Yp23,'b');           
            payoffParetoFront = horzcat(vertcat(Xp12',Xp23'), vertcat(Yp12',Yp23'));          
        end          
    end
            
    ks(1,1) = Inf;
    ks(1,2) = Inf;   
    r = zeros(1,size(payoffParetoFront,1));
    l = zeros(1,size(payoffParetoFront,1));  
    
    for u = 1 : size(payoffParetoFront,1)       
        u2c2 = -payoffParetoFront(u,2) + payoffBoth(c,2);
        u1c1 = -payoffParetoFront(u,1) + payoffBoth(c,1);
        m2c2 = -m2 + payoffBoth(c,2);
        m1c1 = -m1 + payoffBoth(c,1);
        l(u) = u2c2 / u1c1;
        r(u) = m2c2 / m1c1;
        
        if u2c2 == 0 || u1c1 == 0
            l(u) = 0;              
        end
        if m2c2 == 0 || m1c1 == 0
            r(u) = 0;    
        end        
    end    
    diff = r - l
    [minDiff, minInd] = min(abs(diff))   
    ks(1,1) = payoffParetoFront(minInd,1);
    ks(1,2) = payoffParetoFront(minInd,2); 
  
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