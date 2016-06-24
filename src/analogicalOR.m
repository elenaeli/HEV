function [ z ] = analogicalOR( x,y )
    a = 1.02889;
    b = 0.3574;
    
    z = x * exp(-(a*y*y + b*y*x)/(y*y + x*x)) + y * exp(-(a*x*x + b*x*y)/(x*x + y*x));
end

