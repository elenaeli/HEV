function [X1, X2, A, b, v] = mixedstrategies( payoff, playerNum )     
    [m,n] = size(payoff);   
    coder.extrinsic('linprog');
    coder.varsize('A');
    coder.varsize('b'); 
    coder.varsize('X1');
    coder.varsize('X2');
   
    v = Inf;
    % There is a saddle point in pure strategies

    if min(max(payoff))==max(min(payoff,[],2))
        maxP = max(payoff);
        for i=1:m
            for j=1:n
                if isequal(maxP(j),payoff(i,j))      
                    if isequal(payoff(i,j),min(payoff(i,:)))
                        min(payoff(i,:));
                        r = i;
                        s = j;
                        v = payoff(r,s);
                    end
                end
            end
        end
        X1 = zeros(m,1);
        X2 = zeros(m,1);
        A = [];
        b = [];
        if playerNum == 1
            X1(r) = 1.0;
            X2(s) = 1.0;
        elseif playerNum == 2
            X2(r) = 1.0;
            X1(s) = 1.0;
        end       
        
    % There is no saddle point in pure strategies, so extend to mixed
    % strategies by solving linear system of equations Ax = b by linear
    % programming
    else
        % add last equation x1 + x2 + ... xm = 1, probabilities must sum up
        % to 1
        %lin = zeros(m,n);
        %lin(m,:) = ones(1,m)       
    
        f = [zeros(m,1); -1];
        lb = [zeros(m,1) ;-Inf];
        A = [payoff ones(m,1)];
        b = zeros(m,1);     

        Aeq = [ones(1,m) 0];
        beq = 1;

        X1 = zeros(m+1,1);
        options = optimset('Display', 'off');
        X1 = linprog(f,A,b,Aeq,beq,lb,[],[],options);       
        v = abs(X1(end,1));
        X1(end,:) = [];
        X2 = [];
    end
end

