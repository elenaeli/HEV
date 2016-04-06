function [ X, lin, b] = mixedstrategies( payoff )
    % Solve linear system of equation of the form
    % A*X = B 
    % where A is of size 14+13+12...+1 + 1  = 105 + 1 for 15 pure strategies
    % A = 
    % a1*x1 b1*x2 c1*x3 ... o1*x15 = 0
    % a2*x1 b2*x2 c2*x3 ... o2*x15 = 0
    % ...
    % a15*x1 b15*x2 c15*x3 ... o15*x15 = 0
    % x1 x2 x3 ... x15 = 0
    %    
    % b = [ 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1]
 
    [m,n] = size(payoff);   
    linearSysSize = sum([1:m-1])
    lin = zeros(linearSysSize+1,m);
    %payoff(m+1,:) = ones(1,m);
    %payoff
    count = 1;
    for i = 1 : m
        for k = i+1 : n   
            if k == m && i == m
                payoff(i,:)
                payoff(k,:)
            end
            lin(count,:) = payoff(:,i) - payoff(:,k) ;
            count = count +1;            
        end
    end
    % add last equation x1 + x2 + ... xm = 1
    lin(linearSysSize + 1,:) = ones(1,m);
    b = zeros(linearSysSize+1,1);
    b(linearSysSize+1) = 1;
    lin
    b
    X = linsolve(lin, b)    
    
    %X_a = linprog(-[1;zeros(m-1,1)],[],[],lin,b)
    %Xb = lin\b

end

