function  [paretoStrategies, paretoIndices, x, y]  = paretoset( payoffEngine, payoffMotor )
    coder.extrinsic('legend');
    coder.extrinsic('int2str');
    
    [k,l] = size(payoffEngine);    
    Eng = payoffEngine;
    Mot = payoffMotor;
    ind = 1;
    x = zeros(1,k*l);
    y = zeros(1,k*l);

    for i=1:k        
        for j=1:l         
            %Eng(i,count) = payoff(i,j);
            %Mot(i,count) = payoff(i,j+1);           
            x(ind) = Eng(i,j);
            y(ind) = Mot(i,j);
            ind = ind+1;          
        end
    end 
   
    paretoIndices = zeros(k,2);
    paretoStrategies = zeros(k,2);
    coder.varsize('paretoIndex');
    coder.varsize('paretoStrategies');
    count = 1;
    
    for i=1:k      
        for j=1:l                
            isNotPareto = 0;
            flag = 0;                        
            for m=1:k  
                for n=1:l                   
                    if Eng(i,j) > Eng(m,n) && Mot(i,j) > Mot(m,n)                    
                        isNotPareto = 1;
                        flag = 1;
                        break;
                    end                      
                end
                if flag == 1
                    break;
                end
            end
            if isNotPareto == 0    
                repeatedRow = ismember(paretoStrategies,[Eng(i,j) Mot(i,j)],'rows');
                if ~any(repeatedRow)    
                    paretoIndices(count,1) = i;
                    paretoIndices(count,2) = j;
                    paretoStrategies(count,1) = Eng(i,j);
                    paretoStrategies(count,2) = Mot(i,j);
                    count = count+1;
                end
            end           
        end
    end
    
    %[pareto,ia,~] = unique(pareto,'rows');   
    %paretoIndex = paretoIndex(ia, :); 
    
    % remove all rows with zeros
    paretoIndices( ~any(paretoIndices,2), : ) = [];
    paretoStrategies( ~any(paretoStrategies,2), : ) = [];
   
end

