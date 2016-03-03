function [ nash ] = nashSolution( payoffEngine, payoffMotor, requiredTorque )

    [k l] = size(payoffEngine);
    Eng = payoffEngine;
    Mot = payoffMotor;
    conflictPoint = [Eng(k,l) Mot(k,l)]
    nash = [];
    qNumRows = k*k+2;
    qNumCols = l*l+2;
    Q = zeros(qNumRows, qNumCols);
    Q(qNumRows-1, qNumCols) = 1;
    Q(qNumRows, qNumCols-1) = 1;    
    c = zeros(qNumRows,1)';
    c(1,qNumRows-1) = -conflictPoint(1);
    c(1,qNumRows) = -conflictPoint(2);
    c;
    Q;
    H = zeros(3,qNumCols);
    H(1,1:qNumCols-2) = reshape(Eng,1,k*k);
    H(2,1:qNumCols-2) = reshape(Mot,1,l*l);
    H(1,qNumCols-1) = -1;
    H(2,qNumCols) = -1;
    H(3,1:qNumCols-2) = 1;
    H(3,qNumCols-1:qNumCols) = 0;
    r = [0 0 1]';
    
    lb = zeros(qNumRows,1)';
    lb(1,qNumRows-1) = conflictPoint(1);
    lb(1,qNumRows) = conflictPoint(2);
    ub = Inf([qNumRows,1]);
    A = []; 
    b = [];
    [x obj] = quadprog(-Q,-c,A,b,H,r,lb,ub);
    
end

