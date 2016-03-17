function undominated = checkDominated(A, pareto)
count = 1;
undominated = [];
for i = 1 : size(A,1)
    for j = 1 : size(pareto,1)
        % not dominated
        if A(i,1) <= pareto(j,1) && A(i,2) <= pareto(j,2)
            undominated(count,:) = A(i,:);
            count = count + 1;     
        end
    end   
end

