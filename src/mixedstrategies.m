function [ X, lin, b] = mixedstrategies( payoff )
    % Solve linear system of equation of the form
    % A*X = B      
     
    [m,n] = size(payoff);   
    %linearSysSize = sum([1:m-1])
    %lin = zeros(m,m);  
    %for i = 1 : m-1           
    %    lin(i,:) = payoff(:,i) - payoff(:,i+1) ;                  
    %end
    
    % add last equation x1 + x2 + ... xm = 1
    lin(m,:) = ones(1,m);
       
    %lin2(1:end-1,:) = -lin(1:end-1,:);
    %lin2(m,:) = ones(1,m);

    %X = linsolve(lin, b)  
   
    %ub = [ones(n,1)];
    %options = optimset('LargeScale','off','Simplex','off');
    %options = optimoptions('linprog','Algorithm','interior-point');
    %options = optimoptions('linprog','Algorithm','simplex');
    %lin2 = licols(lin(1:end-1,:)')';
    %[i, ~] = size(lin2);
    
    f = [zeros(m,1); -1];
    lb = [zeros(m,1) ;-Inf];
    A = payoff;
    A(:,m+1) = ones(m,1);
   
    Aeq = [ones(1,m) 0];
    beq = 1;
    b = zeros(m,1);
   
    X = linprog(f,A,b,Aeq,beq,lb);
    X(end,:) = []
    
    %X = linsolve(lin,b);
    %X = lin\b;   
end

