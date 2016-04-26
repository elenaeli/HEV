function  [paretoStrategies, paretoIndices, x, y]  = paretoset( payoffEngine, payoffMotor)
    coder.extrinsic('legend');
    coder.extrinsic('int2str');
    coder.extrinsic('ismembertol');
   
    [k,l] = size(payoffEngine);    
    Eng = payoffEngine;
    Mot = payoffMotor;

    x = reshape(Eng',1,k*l);
    y = reshape(Mot',1,k*l);
    
    paretoIndices = zeros(k,2);
    paretoStrategies = zeros(k,2);
    coder.varsize('paretoIndex');
    coder.varsize('paretoStrategies');
    coder.varsize('paretoIndices');
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
                repeatedRow = ismembertol(paretoStrategies,[Eng(i,j) Mot(i,j)], 0.000001, 'ByRows', true);
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

