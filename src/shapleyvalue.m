%% Shapley Value
% compute by the formula, n - number of all players,
% i player arrives at position k
% v(K) - value of coalition K
% v(K-{i}) - value of coalition K without player i

function [ shEngine, shMotor ] = shapleyvalue( v12, v1, v2)
% ((k-1)!*(n-k)! / n!) (value(K) - value(K-{i}))    
    % 1/2 * (v12 - v2) + 1/2 * v1
    shEngine = 1/2 * (v12 - v2) + 1/2 * v1; 
    % 1/2 * (v12 - v1) + 1/2 * v2
    shMotor = 1/2 * (v12 - v1) + 1/2 * v2;    
end