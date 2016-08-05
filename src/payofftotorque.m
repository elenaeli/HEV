% Transform payoff to torque from the strategy space
function [ engineTorque, motorTorque ] = payofftotorque(payoffEngine, payoffMotor, ...
    payoffBoth, strategyEng, strategyMot)
    coder.extrinsic('ismembertol');
    coder.extrinsic('ind2sub');           
    i = 0;
    j = 0;
    m = size(strategyEng,2);
    n = size(strategyMot,2);

    [~, ind] = ismembertol([payoffEngine, payoffMotor],payoffBoth,0.0001,'ByRows',true);
    [i, j] = ind2sub([m n], ind);
    engineTorque = strategyEng(i);
    motorTorque = strategyMot(j);
end

