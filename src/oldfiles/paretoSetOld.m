%function [ parM, parE ] = paretoSet( payoff )
[k,l] = size(payoff);
M = zeros(k,l); 
E = zeros(k,l);

ind = 1;
x = zeros(1,k);
y = zeros(1,k);

for i=1:k
    for j=1:l
        M(i,j) = payoff{i,j}(1);
        E(i,j) = payoff{i,j}(2);
        x(ind) = M(i,j);
        y(ind) = E(i,j);
        ind=ind+1;
    end
end

% connect last point to first in the graph
x = [x x(1)];
y = [y y(1)];

tmpM = M;
tmpE = E;

Mrow=[]; Mcol=[];
Erow=[]; Ecol=[];

for i = 1 : max([k l])    
    [Mrow, Mcol] = find(tmpM == min(min(tmpM)))
    if ~isscalar(Mrow) && ~isscalar(Mcol)
        for m = 1 : max([size(Mrow) size(Mrow)])
            find(tmpE < tmpE(Mrow(m),Mcol(m)))
            indELess = find(tmpE < tmpE(Mrow(m),Mcol(m)))
        end      
    else
        indELess = find(tmpE < tmpE(Mrow,Mcol));
    end

    if isempty(indELess)       
        tmpM(Mrow,Mcol) = min(min(tmpM));           
    end  

    [Erow, Ecol] = find(tmpE == min(min(tmpE)))
    if ~isscalar(Erow) && ~isscalar(Ecol)
        for m = 1 : max([size(Erow) size(Ecol)])
            indMLess = find(tmpM < tmpM(Erow(m),Ecol(m)));
        end    
    else        
        indMLess = find(tmpM < tmpM(Erow,Ecol));
    end

    if isempty(indMLess)         
        tmpE(Erow,Ecol) = min(min(tmpE));         
    end  

    if (~isempty(indMLess) && ~isempty(indELess))       
        break; 
    end
end

plot(x,y,'-o')
title('Game payoffs')

if (~isscalar(Erow) && ~isscalar(Ecol)) || (~isscalar(Mrow) && ~isscalar(Mcol))
    for i = 1: max([size(Mrow) size(Mcol)])
        text(M(Mrow(i), Mcol(i)), E(Mrow(i), Mcol(i)), 'Motor Pareto optimum')  
        text(E(Mrow(i), Mcol(i)), M(Mrow(i), Mcol(i)), 'Engine Pareto optimum') 
        
    end
    for j = 1: max([size(Erow) size(Ecol)])
        text(M(Erow(i), Ecol(i)), E(Erow(i), Ecol(i)), 'Engine Pareto optimum') 
    end
end



parM = strcat('(M',int2str(Mrow),',E',int2str(Mcol),')')
parE = strcat('(M',int2str(Erow),',E',int2str(Ecol),')')
%end

