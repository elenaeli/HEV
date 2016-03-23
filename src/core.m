function coreS = core(A)
coreS = zeros(size(A,1),1);

for i = 1:size(A,1)
    v1 = A(i,1);
    v2 = A(i,2);
    v12 = A(i,3);
    if v1 + v2 >= v12 && v1 >= v1 && v2 >= v2
        coreS(i) = 1;
    end
end
end
