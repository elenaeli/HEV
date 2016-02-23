payoff = [9.66, 8.5, 10.26, 6.39;
    7.98, 12.32, 11.51, 10.9;
    8.14, 9.47, 9.34, 10.12;
    6.74, 8.64, 5.21, 8.44];

payoff1 = [10, 8;
    7, 12;
    8, 10;
    6, 9;
    9, 7];

x = -5+10*rand(100,1);
F1 = x.^2;
F2 = (x-2).^2;

% Test my solution
[~, ind] = paretoEfficiency([F1,F2]);
inverseInd = ~ismember(ind, 1:numel(x));

figure(1)
hold on
scatter(F1,F2,10,'red');
scatter(F1(ind),F2(ind),50,'blue');
scatter(F1(inverseInd),F2(inverseInd),50,'green');
hold off
legend('all solutions','dominating solutions','non-dominating solutions')
title('Pareto optimal solutions (my code)');

% Compare it with other solution 
ind1 = paretofront([F1,F2]);
inverseInd1 = ~ismember(ind1,1:numel(x));

figure(2)
hold on
scatter(F1,F2,10,'red');
scatter(F1(ind1),F2(ind1),50,'blue');
scatter(F1(inverseInd1),F2(inverseInd1),50,'green');
hold off
legend('all solutions','dominating solutions','non dominating solutions')
title('Pareto optimal solutions (other code)');

% figure
% hold on;
% plot(payoff(:,1),payoff(:,2));
% plot(payoff(b(1),1),payoff(b(2),2) , 'r');
% hold off
% grid on
% xlabel('x');
% ylabel('y');
% title('Pareto Front');
