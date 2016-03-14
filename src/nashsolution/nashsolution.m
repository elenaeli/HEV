function [ nashProduct, indN ] = nashsolution( payoffBoth, c )

nashProduct = zeros(size(payoffBoth,1),1);
for i = 1 : size(payoffBoth,1)
    u1 = payoffBoth(i,1) - payoffBoth(c,1);
    u2 = payoffBoth(i,2) - payoffBoth(c,2);
    if payoffBoth(i,1) > payoffBoth(c,1) && payoffBoth(i,2) > payoffBoth(c,2)
        nashProduct(i) = u1 * u2;
    else
        nashProduct(i) = Inf;
    end
    
end
[ ~, indN ] = min(nashProduct);
nashSolution = nashProduct(indN, :);
end

