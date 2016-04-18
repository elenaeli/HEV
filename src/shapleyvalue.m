function [ shEngine, shMotor ] = shapleyvalue( v12, v1, v2)
% ((k-1)!*(n-k)! / n!) (value(k) - value(k-{i}))    
    % 1/2 * (v12 - v2) + 1/2 * v1
    shEngine = 1/2 * (v12 - v2) + 1/2 * v1; 
    % 1/2 * (v12 - v1) + 1/2 * v2
    shMotor = 1/2 * (v12 - v1) + 1/2 * v2;    
end