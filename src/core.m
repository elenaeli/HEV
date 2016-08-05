%% Core
% Find the core of a game. Input is a matrix of size 3x49.
% The first column is the payoff of coalition with player 1,
% second column is payoff of coalition with player 2 only 
% last column is payoff of the grand coalition of both players
% coalition

function coreS = core(A)
    coreS = zeros(size(A,1),1);
    for i = 1:size(A,1)
        v1 = A(i,1);
        v2 = A(i,2);
        v12 = A(i,3);
        % if individually and group rational, then it is in the core
        if v1 + v2 >= v12 && v1 >= v1 && v2 >= v2
            coreS(i) = 1;
        end
    end
end
