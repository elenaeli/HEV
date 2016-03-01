function [ pareto, paretoString ] = paretoSet( payoff )
    coder.extrinsic('legend');
    coder.extrinsic('int2str');
    coder.extrinsic('strcat');
    
    pareto = [];
    paretoString = [];
    [k,l] = size(payoff);
    M = zeros(k,l); 
    E = zeros(k,l);

    ind = 1;
    x = zeros(1,k);
    y = zeros(1,k);

    for i=1:k
        for j=1:l
            M(i,j) = payoff(i*2,j);
            E(i,j) = payoff(i*2+1,j);
            x(ind) = M(i,j);
            y(ind) = E(i,j);
            ind = ind+1;
        end
    end

    % connect last point to first in the graph
    x = [x x(1)];
    y = [y y(1)];

    count = 1;
    paretoIndex = zeros(1,2);
    pareto = zeros(1,2);
    for i=1:k      
        for j=1:l          
            not = 0;
            flag = 0;
            for m=1:k  
                for n=1:l                
                    if E(i,j) > E(m,n) && M(i,j) > M(m,n)                    
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
                paretoIndex(count,1) = i;
                paretoIndex(count,2) = j;
                pareto(count,1) = M(i,j);
                pareto(count,2) = E(i,j);
                count = count+1;
            end            
        end
    end
    [pareto,ia,~] = unique(pareto,'rows');
    paretoIndex = paretoIndex(ia, :);
    
   
    figure
    plot(x,y,'-o');
    title('Game payoffs');
    hold on
    paretoString = zeros(size(pareto,1),1);
    for i = 1 : size(pareto,1)
        %text(M(paretoIndex(i,1), paretoIndex(i,2))+2, E(paretoIndex(i,1), paretoIndex(i,2)), 'Pareto optimum')  
        linearIndex = sub2ind([k l], paretoIndex(i,2), paretoIndex(i,1));
        plot(x(linearIndex), y(linearIndex), 'or', 'MarkerFaceColor','r');   
        legend('payoff','Pareto optimum payoff', 'Location','northeast');
        xlabel('Payoff Motor');
        ylabel('Payoff Engine');
        pareto(i,:) = [paretoIndex(i,1), paretoIndex(i,2)];
        paretoString(i) = strcat('(M',int2str(paretoIndex(i,1)),',E',int2str(paretoIndex(i,2)),')');
    end
end

