function [paretoFront, paretoIndices] = paretoEfficiency(payoff)
   
    M = size(payoff,1);
    N = size(payoff,2);
    ind = 0;
    paretoFront = zeros(M,N);
    paretoIndices = false(M,1);
    payoffDifference = zeros(M,N);

    % for every row 
    for i = 1:M
       indTmp = 0;
       payoffCurrentRow = payoff(i,:);
       % for every row different from the current
       for m = 1:M
           if (m ~= i)
               indTmp = indTmp+1;
               % difference between current row payoff and the payoff in
               % row m
               payoffDifference(indTmp, :) = payoffCurrentRow - payoff(m,:);
           end
       end   
       % if all of the rows contain only negative values
       if( any(payoffDifference(1:indTmp,:) < 0, 2))
          ind = ind + 1;
          % keep row as a solution
          paretoFront(ind,:) = payoffCurrentRow;
          paretoIndices(i) = true;
       end
       % zero the difference before using the variable again
       payoffDifference = zeros(M,N);
    end    
    % remove any rows containing only zeros
    paretoFront( ~any(paretoFront,2), : ) = [];
end

