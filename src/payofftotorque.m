function [ engineTorque, motorTorque ] = payofftotorque(bestPayoffEngPareto, bestPayoffMotPareto, ...
    payoffBoth, strategyEng, strategyMot)
    coder.extrinsic('ismembertol');
    coder.extrinsic('ind2sub');
   
    i = 0;
    j = 0;
    m = size(strategyEng,2);
    n = size(strategyMot,2);

    [~, ind] = ismembertol([bestPayoffEngPareto, bestPayoffMotPareto],payoffBoth,0.0001,'ByRows',true);
    [i, j] = ind2sub([m n], ind);
    
    engineTorque = strategyEng(i);
    motorTorque = strategyMot(j);

end

