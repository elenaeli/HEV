% function to interpolate between x and y coordinates of 
    function interpolate(j,x,y,X)
       if j == 1
           Y = interp1(x, y, X);
           plot(X,Y,'r');
       elseif j == 2
           Y = interp1(y, x, X);
           plot(Y,X,'r');
       end
    end

