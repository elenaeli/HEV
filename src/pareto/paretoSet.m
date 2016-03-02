function  pareto  = paretoSet( payoff )
    coder.extrinsic('legend');
    coder.extrinsic('int2str');
    coder.extrinsic('strcat');
    
    pareto = [];
    [k,l] = size(payoff);
    l = l/2;
    Mot = zeros(k,l); 
    Eng = zeros(k,l);

    ind = 1;
    x = zeros(1,k*l);
    y = zeros(1,k*l);

    for i=1:k
        count = 1;
        for j=1:2:l*2           
            Mot(i,count) = payoff(i,j);
            Eng(i,count) = payoff(i,j+1);           
            x(ind) = Mot(i,count);
            y(ind) = Eng(i,count);
            ind = ind+1;
            count = count +1;
        end
    end
   
    %M( :, ~any(M,1) ) = [];  %columns
    %E( :, ~any(E,1) ) = [];  %columns

    % connect last point to first in the graph
    x = [x x(1)];
    y = [y y(1)];

    count = 1;
    paretoIndex = zeros(k,2);
    pareto = zeros(k,2);
    coder.varsize('paretoIndex');
    coder.varsize('pareto');
    coder.varsize('paretoIndices');

    for i=1:k      
        for j=1:l                
            not = 0;
            flag = 0;                        
            for m=1:k  
                for n=1:l                   
                    if Eng(i,j) > Eng(m,n) && Mot(i,j) > Mot(m,n)                    
                        not = 1;
                        flag = 1;
                        break;
                    end                      
                end
                if flag == 1
                    break;
                end
            end
            if not == 0    
                repeatedRow = ismember(pareto,[Mot(i,j) Eng(i,j)],'rows');
                if ~any(repeatedRow)    
                    paretoIndex(count,1) = i;
                    paretoIndex(count,2) = j;
                    pareto(count,1) = Mot(i,j);
                    pareto(count,2) = Eng(i,j);
                    count = count+1;
                end
            end           
        end
    end
   
    [pareto,ia,~] = unique(pareto,'rows');
    paretoIndex = paretoIndex(ia, :);
    paretoIndex( ~any(paretoIndex,2), : ) = [];
    pareto( ~any(pareto,2), : ) = [];

   
    plot(x,y,'-o');
    title('Game payoffs');
    hold on
    %paretoString = zeros(size(pareto,1),1);
    for r = 1 : size(pareto,1)
        %text(M(paretoIndex(i,1), paretoIndex(i,2))+2, E(paretoIndex(i,1), paretoIndex(i,2)), 'Pareto optimum')  
        linearIndex = sub2ind([k l], paretoIndex(r,2), paretoIndex(r,1));
        plot(x(linearIndex), y(linearIndex), 'or', 'MarkerFaceColor','r');   
        legend('payoff','Pareto optimum payoff', 'Location','northeast');
        xlabel('Payoff Motor');
        ylabel('Payoff Engine');
        pareto(r,:) = [paretoIndex(r,1), paretoIndex(r,2)];
        %paretoString(i) = strcat('(M',int2str(paretoIndex(i,1)),',E',int2str(paretoIndex(i,2)),')');
    end
    hold off
end

