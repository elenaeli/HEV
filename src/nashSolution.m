function [ sol, fval ] = nashSolution( payoffEngine, payoffMotor, requiredTorque, eng, mot )
    [k, l] = size(payoffEngine);
    Eng = payoffEngine;
    Mot = payoffMotor;
    conflictPoint = [eng mot]   
    hNumRows = k*k+2;
    hNumCols = l*l+2;
    H = zeros(hNumRows, hNumRows);
    H(hNumRows-1, hNumRows) = 0.5;
    H(hNumRows, hNumRows-1) = 0.5;    
    f = zeros(hNumRows,1)';
    f(1,hNumRows-1) = -conflictPoint(1);
    f(1,hNumRows) = -conflictPoint(2);
    H
    f
    Aeq = zeros(3,hNumRows);
    Aeq(1,1:hNumRows-2) = reshape(Eng',k*k,1);
    Aeq(2,1:hNumRows-2) = reshape(Mot',l*l,1);
    Aeq(1,hNumRows-1) = -1;
    Aeq(2,hNumRows) = -1;
    Aeq(3,1:hNumRows) = 1;
    Aeq(3,hNumRows-1:hNumRows) = 0;
    Aeq
    beq = [0 0 1]'
    
    lb = zeros(hNumRows,1)';   
    lb(1,hNumRows-1) = conflictPoint(1);
    lb(1,hNumRows) = conflictPoint(2);    
    ub = Inf(hNumRows,1)';
    
    lb
    ub
    options = optimoptions('quadprog','Algorithm','interior-point-convex','Display','off');
    [sol, fval, exitflag] = quadprog(-H,-f,[],[],Aeq,beq,lb,ub,[],options)

end

