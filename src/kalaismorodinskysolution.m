function [ ks, indKS ] = kalaismorodinskysolution( payoffBoth, c )    
    c
    m1 = min(payoffBoth(:,1))
    m2 = min(payoffBoth(:,2))
    
    %plot(m1,m2,'xr');
    
    ks(1,1) = Inf;
    ks(1,2) = Inf;
    indKS = 0;
    r = zeros(1,size(payoffBoth,1));
    l = zeros(1,size(payoffBoth,1));
   % cP = [payoffBoth(c,1) payoffBoth(c,2)];
    %mP = [m1 m2];
    %x = [cP(1) mP(1)];
    %y = [cP(2) mP(2)];
    %if mP(1) < cP(1)
    %    X = mP(1):cP(1);   
    %else
    %    X = cP(1):mP(1);   
    %end
    %Y = interp1(x, y, X);
    %plot(X,Y,'r');
    
    for u = 1 : size(payoffBoth,1)       
        u2c2 = -payoffBoth(u,2) + payoffBoth(c,2);
        u1c1 = -payoffBoth(u,1) + payoffBoth(c,1);
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
        if u == 86
            u2c2
            u1c1
            m2c2
            m1c1          
        end
        %if abs(r(u)-l(u)) < eps(0.05)
        %    ks(1,1) = payoffBoth(u,1);
        %    ks(1,2) = payoffBoth(u,2);
         %   indKS = u;            
        %elseif abs(r1-l1) < eps(0.05)
        %    ks(1,1) = payoffBoth(u,1);
        %    ks(1,2) = payoffBoth(u,2);
        %    indKS = u; 
        %end
    end
    r
    l
    
    diff = r - l
    [minDiff, minInd] = min(abs(diff))
    ks(1,1) = payoffBoth(minInd,1);
    ks(1,2) = payoffBoth(minInd,2);
    
end

