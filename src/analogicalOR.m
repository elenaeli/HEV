% Analogical OR as in Badreddin, E (1995). `Analogical gates: a fuzzy 
% operator approach for locomotion control of a non-holonomic mobile robot'. 
% In: Fuzzy Systems, 1995. International Joint Conference of the Fourth IEEE 
% International Conference on Fuzzy Systems and The Second International 
% Fuzzy Engineering Symposium., Proceedings of 1995 IEEE Int. Vol. 2. IEEE,
% pp. 875882. 
function [ z ] = analogicalOR( x,y )
    a = 1.02889;
    b = 0.3574;    
    z = x * exp(-(a*y*y + b*y*x)/(y*y + x*x)) + y * exp(-(a*x*x + b*x*y)/(x*x + y*y));
end

