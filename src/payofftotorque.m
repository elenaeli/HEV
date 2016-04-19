function [ engineTorque, motorTorque ] = payofftotorque(bestPayoffEngPareto, bestPayoffMotPareto, ...
    payoffBoth, strategyEng, strategyMot)
    coder.extrinsic('ismembertol');
    coder.extrinsic('ind2sub');
   
    i = 0;
    j = 0;
    [~, ind] = ismembertol([bestPayoffEngPareto, bestPayoffMotPareto],payoffBoth,0.0001,'ByRows',true);
    [i, j] = ind2sub([15 15], ind);
    
    engineTorque = strategyEng(i);
    motorTorque = strategyMot(j);

end

