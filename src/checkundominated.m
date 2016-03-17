function undominated = checkundominated(A, pareto, payoffWholeCoalition)
count = 1;
undominated = [];
flag = 0;
for i = 1 : size(A,1)
    for j = 1 : size(pareto,1)
        % not dominated
        sum12 = A(i,1) + A(i,2);
        [k l] = ind2sub(size(payoffWholeCoalition), i);
        valCoal = payoffWholeCoalition(k,l);
        if A(i,1) > pareto(j,1) && A(i,2) > pareto(j,2) && sum12 >= valCoal            
            flag = 1 
            break;
        end
        if flag == 1
            break;
        end        
    end 
    if flag == 0
        undominated(count,:) = A(i,:);
        count = count + 1;
    end    
    flag = 0;
end

