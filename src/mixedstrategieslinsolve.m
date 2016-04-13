function [ X, lin, b] = mixedstrategieslinsolve( payoff, X1 )
    % Solve linear system of equation of the form
    % A*X = B      
     
    [m,n] = size(payoff);      
    lin = zeros(m,m);  
    for i = 1 : m-1           
        lin(i,:) = payoff(:,i) - payoff(:,i+1) ;                  
    end   

    %lin2 = licols(lin(1:end-1,:)')';
    %[i, ~] = size(lin2);
    
    % add last equation x1 + x2 + ... xm = 1
    lin(m,:) = ones(1,m);
    b = [zeros(m-1,1); 1];

    [X,R] = linsolve(lin,b);
    X1a = lin*X1
    %X1a = lin\b;
    X1b = X1.*b 
    %rref([lin b])

end

