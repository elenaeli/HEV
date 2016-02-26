function [ parA, parB ] = pareto( payoff )
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
    [Mrow, Mcol] = find(tmpM == min(min(tmpM)));
    indELess = find(tmpE < tmpE(Mrow,Mcol));

    if isempty(indELess)       
        tmpM(Mrow,Mcol) = min(min(tmpM));           
    end  

    [Erow,Ecol] = find(tmpE == min(min(tmpE)));
    indMLess = find(tmpM < tmpM(Erow,Ecol));

    if isempty(indMLess)         
        tmpE(Erow,Ecol) = min(min(tmpE));         
    end  

    if (~isempty(indMLess) && ~isempty(indELess))       
        break; 
    end
end

plot(x,y,'-o')
title('Game payoffs')
text(M(Mrow, Mcol), E(Mrow, Mcol), 'Pareto optimum')  
text(E(Mrow, Mcol), M(Mrow, Mcol), 'Pareto optimum')  

parA = strcat('(M',int2str(Mrow),',E',int2str(Mcol),')');
parB = strcat('(M',int2str(Erow),',E',int2str(Ecol),')');
end

