function [ ks, indKS ] = kalaismorodinskysolution( payoffBoth, c )
    
    m1 = min(payoffBoth(:,1))
    m2 = min(payoffBoth(:,2))   
    
    plot(m1,m2,'xr');
    
    ks(1,1) = Inf;
    ks(1,2) = Inf;
    indKS = 0;
    for u = 1 : size(payoffBoth,1)
        u2c2 = -payoffBoth(u,2) + payoffBoth(c,2);
        u1c1 = -payoffBoth(u,1) + payoffBoth(c,1);
        m2c2 = -m2 + payoffBoth(c,2);
        m1c1 = -m1 + payoffBoth(c,1);
        r = u2c2 / u1c1;
        l = m2c2 / m1c1;
        
        if u1c1 == 0 && u2c2 == 0           
            r = 0;              
        end
        if m1c1 == 0 && m2c2 == 0
            l = 0;
        end
        %if u == 43                  
        %end 
        if r == l 
            ks(1,1) = payoffBoth(u,1)
            ks(1,2) = payoffBoth(u,2)
            indKS = u
        end
         
       
    end
end

