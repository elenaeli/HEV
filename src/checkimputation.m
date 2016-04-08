function [imput, imputIndex] = checkimputation(payoff, pareto,...
    payoffMotCoal, payoffEngCoal, payoffWholeCoal)
    count = 1;
    m = size(payoff,1);
    imput = zeros(m,2);
    imputIndex = zeros(m,1);

    flag = 0;
    for i = 1 : size(payoff,1)
        for j = 1 : size(pareto,1)     
            sum12 = payoff(i,1) + payoff(i,2);
            [k l] = ind2sub(size(payoffWholeCoal), i);
            valCoal = payoffWholeCoal(k,l);
            % check if any pareto optimal point dominates this point and
            % check individual rationality (player receives <= payoff in the
            % colaition than when acting alone)
            if pareto(j,1) < payoff(i,1) && pareto(j,2) < payoff(i,2) ...
               && sum12 >= valCoal && ...            
                payoff(i,1) >= payoffEngCoal(i,1) && payoff(i,2) >= payoffMotCoal(i,1)             
                flag = 1;
                break;           
            end       
            if flag == 1
                break;
            end        
        end 
        if flag == 0            
            imput(count,1) = payoff(i,1);    
            imput(count,2) = payoff(i,2);
            imputIndex(count) = i;     
            count = count + 1;
        end
        flag = 0;
    end
end

