function [ nashSolution, indNP ] = nashsolution( payoffBoth, c )

    nashProduct = zeros(size(payoffBoth,1),1);
    for u = 1 : size(payoffBoth,1)
        u1 = - payoffBoth(u,1) + payoffBoth(c,1);
        u2 = - payoffBoth(u,2) + payoffBoth(c,2);
a = all(payoffBoth(u,1) <= payoffBoth(c,1));
b = all(payoffBoth(u,2) <= payoffBoth(c,2));
        if a && b
            nashProduct(u) = u1 * u2;
        else
            nashProduct(u) = -Inf;
        end

    end
    [ ~, indNP ] = max(nashProduct);    
    nashSolution = nashProduct(indNP, :);
end

