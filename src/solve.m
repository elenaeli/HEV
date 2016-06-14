function [engineTorque,motorTorque] = solve(payoffEngine, payoffMotor, ...
     strategyEng, strategyMot, requiredTorqueR, torqueDeviation, fuelConsRate, fuelConsumed, emissions, power, m, e);
    try        
    %    paretoStrategies = [];
    %    paretoIndex = [];
    %    engineTorque = 0;
    %    motorTorque = 0;
        
    %   [paretoStrategies, paretoIndex, ~, ~] = paretoset(payoffEngine, payoffMotor);    

        payoffE = reshape(payoffEngine,(m)*(e),1);
        payoffM = reshape(payoffMotor,(m)*(e),1);        
        payoffBoth = horzcat(payoffE, payoffM);
               
    %    stringRequiredTorque = int2str(requiredTorqueR);

    %    [ bestPayoffEngPareto, bestPayoffMotPareto ] = bestpareto( paretoStrategies, paretoIndex, ...
    %        torqueDeviation, fuelConsRate, power );
    %   [ bestPayoffEngPareto, bestPayoffMotPareto ] = bestparetoNew( paretoStrategies, paretoIndex, ...
    %       torqueDeviation, fuelConsRate, fuelConsumed, emissions)
    %       figure
    %       p1 = plot(x,y,'ob');
    %       title(['Game payoffs, required torque = ', stringRequiredTorque, 'Nm'] );
    %       hold on
    %         
             numStratBoth = m+e;  
            
             [nashEqPl1, nashEqPl2] = LemkeHowson(-payoffEngine, -payoffMotor, ceil(1/2*numStratBoth));                     
             payoffEngNash = payoffEngine(nashEqPl1==1, nashEqPl2==1);
             payoffMotNash = payoffMotor(nashEqPl1==1, nashEqPl2==1);       
             
    %         %[~, indM] = min(payoffEngNash);        
    %               
    %         conflictPoint = sub2ind([m e], find(nashEqPl1==1), find(nashEqPl2==1));
    %         
    %         [~, indNP] = nashsolution(payoffBoth, conflictPoint);
    %         payoffEngNashSol = payoffBoth(indNP,1);
    %         payoffMotNashSol = payoffBoth(indNP,2);
    %         paretoStrInd = horzcat(paretoStrategies, paretoIndex);        
    % 
    %         [ks, linePareto] = kalaismorodinskysolution(payoffBoth, conflictPoint, paretoStrategies, paretoStrInd);
    %         percentReqTorq = linspace(0, requiredTorqueR, 10);
    %         probKsMixed = zeros(1,2);
    %         ksMixed = zeros(1,2);
    %         if ~isempty(linePareto)
                  % if x and y of the two Pareto points are different
    %             if linePareto(2,1) - linePareto(1,1) ~=0 && linePareto(1,2) - linePareto(2,2) ~= 0
    %                 probKsMixed(1) = (ks(1,1) - linePareto(1,1)) / (linePareto(2,1) - linePareto(1,1));
    %                 probKsMixed(2) = (ks(1,2) - min(linePareto(:,2))) / (linePareto(1,2) - linePareto(2,2));
                  % if x are the same
    %             elseif linePareto(2,1) - linePareto(1,1) == 0
    %                 probKsMixed(2) = (ks(1,2) - min(linePareto(:,2))) / (linePareto(1,2) - linePareto(2,2));
    %                 probKsMixed(1) = 1 - probKsMixed(2);
                  % if y are the same
    %             elseif linePareto(1,2) - linePareto(2,2) == 0
    %                  probKsMixed(1) = (ks(1,1) - linePareto(1,1)) / (linePareto(2,1) - linePareto(1,1));
    %                  probKsMixed(2) = 1 - probKsMixed(1);
    %             end             
    %             ksMixed(1) = linePareto(1,1) + probKsMixed(1)*(linePareto(2,1) - linePareto(1,1));
    %             ksMixed(2) = min(linePareto(:,2)) + probKsMixed(2)*abs(linePareto(1,2) - linePareto(2,2));
    %                         
    %             mixedEngineTorque = min(strategyEng(linePareto(1,3)),strategyEng(linePareto(2,3))) + ...
    %                 probKsMixed(1)*abs(strategyEng(linePareto(1,3))-strategyEng(linePareto(2,3)));
    %             mixedMotorTorque = min(strategyMot(linePareto(1,4)),strategyMot(linePareto(2,4))) + ...
    %                 probKsMixed(1)*abs(strategyMot(linePareto(1,4))-strategyMot(linePareto(2,4)));
    %         end
    %         
    %         %payoffCoalCoef = ones(m,e);
    %         %payoffCoalCoef(m:m-1:end-1) = 0.5;
    %         
    %         [ payoffWholeCoal, coeffCoal, payoffEngineCoal, payoffMotorCoal, payoffWholeCoalBefore ] = ...
    %             coalitionpayoffs(payoffMotor, payoffEngine, torqueDeviation, percentReqTorq);
    %         
    %         indCoal = (coeffCoal == 0.99 | coeffCoal == 0.991);
    %         indCoalition = +indCoal;
    %         indCoalition(indCoal == true) = 0.98;
    %         indCoalition(indCoal == false) = 1;
    %         %payoffWholeCoal1 = payoffWholeCoal .* indCoalition;      
    %     
    %         payoffMotCoalVec = reshape(payoffMotorCoal,(m)*(e),1);
    %         payoffEngCoalVec = reshape(payoffEngineCoal,(m)*(e),1);
    %         
    %         % get all undominated strategies (pareto optimality)
    %         [undomImp, undomImpInd] = checkimputation(payoffBoth, ...
    %             paretoStrategies, payoffMotCoalVec, payoffEngCoalVec, payoffWholeCoal);        
    %         imputM = zeros(1,size(undomImpInd,2));
    %         imputE = zeros(1,size(undomImpInd,2));
    %         for i = 1 : size(undomImpInd,2)             
    %             if all(undomImp(i,1) <= payoffEngine(m,:))
    %                 imputM(1,i) = undomImpInd(i);
    %             end                
    %             if all(undomImp(i,2) <= payoffMotor(:,e))
    %                 imputE(1,i) = undomImpInd(i);
    %             end
    %         end
    %         coder.varsize('imput');  
    %         imput = undomImpInd;
    %         imput(imput==0) = [];
    %         
    %         payoffImput = zeros(size(imput,1),3);
    %         for i = 1 : size(imput,1)
    %             payoffImput(i,1) = payoffBoth(imput(i),1);
    %             payoffImput(i,2) = payoffBoth(imput(i),2);       
    %             [r, c] = ind2sub(size(payoffWholeCoal), imput(i));
    %             payoffImput(i,3) = payoffWholeCoal(r,c);
    %         end
    %                
    %         coreSol = core(payoffImput);
    %         indCore = find(coreSol);
    %         Xengine = zeros(m,1);
    %         Xmotor = zeros(m,1);
    %         [Xengine, X2, A1, b1, v1] = mixedstrategies(payoffEngine,1);
    %         [Xmotor, X1, A2, b2, v2] = mixedstrategies(payoffMotor,2);
    %         coder.varsize('payoffStrEng');
    %         coder.varsize('payoffStrMot');        
    %        
    %         if  ~isempty(A1) && ~isempty(A2) && ~isempty(b1) && ~isempty(b2)
    %             mixedStrEng = find(abs(Xengine-0)>0.001);
    %             mixedStrMot = find(abs(Xmotor-0)>0.001);         
    %             payoffProbMixedStrEng = zeros(size(mixedStrEng,1),2);
    %             payoffProbMixedStrMot = zeros(size(mixedStrMot,1),2);
    %             payoffStrEng = 0;
    %             for i = 1 : size(mixedStrEng,1)        
    %                 payoffProbMixedStrEng(i,1) = payoffEngine(mixedStrEng(i));
    %                 payoffProbMixedStrEng(i,2) = Xengine(mixedStrEng(i));
    %                 payoffStrEng = payoffStrEng + payoffEngine(mixedStrEng(i))*Xengine(mixedStrEng(i));
    %             end
    % 
    %             payoffStrMot = 0;
    %             for j = 1 : size(mixedStrMot,1)
    %                 payoffProbMixedStrMot(j,1) = payoffMotor(mixedStrMot(j));
    %                 payoffProbMixedStrMot(j,2) = Xmotor(mixedStrMot(j));    
    %                 payoffStrMot = payoffStrMot + payoffMotor(mixedStrMot(j))*Xmotor(mixedStrMot(j));
    %             end         
    %         else
    %             pureStrEng = find(Xengine);
    %             pureStrMot = find(X2);    
    %             payoffStrEng = payoffEngine(pureStrEng, pureStrMot);
    %             payoffStrMot = payoffMotor(pureStrEng, pureStrMot);           
    %         end
    %         m1 = min(payoffBoth(:,1));
    %         m2 = min(payoffBoth(:,2));
    % 
    %         v12 = min(min(payoffWholeCoalBefore));
    %         [ shEngine, shMotor ] = shapleyvalue(v12, v1, v2);
    %         if ~ismembertol([shEngine, shMotor],payoffBoth,0.001,'ByRows',true)           
    %             IDX = zeros(1,2);
    %             IDX = knnsearch(payoffBoth,[shEngine shMotor],'K', 2);
    %             [idr1, idc1] = ind2sub(size(payoffEngine), IDX(1));        
    %             [idr2, idc2] = ind2sub(size(payoffEngine), IDX(2));
    %             nearestSh1 = [idr1 idc1];
    %             nearestSh2 = [idr2 idc2];
    %             payoffNearestSh1 = [payoffEngine(idr1,idc1) payoffMotor(idr1,idc1)];
    %             payoffNearestSh2 = [payoffEngine(idr2,idc2) payoffMotor(idr2,idc2)];
    %             probNearSh1 = 0;
    %             probNearSh2 = 0;
    %             if payoffNearestSh1(1) ~= payoffNearestSh2(1)
    %                 j = 1;
    %                 shapley = shEngine;
    %             else
    %                 j = 2;
    %                 shapley = shMotor;
    %             end
    %             if payoffNearestSh2(j) < shapley &&  ...
    %                 shapley < payoffNearestSh1(j)
    %                 probNearSh2 = (shapley - payoffNearestSh2(j)) / ...
    %                     (payoffNearestSh1(j) - payoffNearestSh2(j));
    %                 probNearSh1 = 1 - probNearSh2;
    %             elseif payoffNearestSh1(j) < shapley && ...                    
    %                 shapley < payoffNearestSh2(j)
    %                 probNearSh1 = (shapley - payoffNearestSh1(j)) / ...
    %                     (payoffNearestSh2(j) - payoffNearestSh1(j));
    %                 probNearSh2 = 1 - probNearSh1;
    %             elseif shapley < payoffNearestSh1(j) &&  ...
    %                 shapley < payoffNearestSh2(j)            
    %                 if payoffNearestSh1(j) < payoffNearestSh2(j)
    %                     probNearSh1 = shapley / payoffNearestSh1(j);
    %                     probNearSh2 = 0;
    %                 elseif payoffNearestSh2(j) < payoffNearestSh1(j)
    %                     probNearSh2 = shapley / payoffNearestSh2(j);
    %                     probNearSh1 = 0;
    %                 end
    %             end
    %             probNearSh1;
    %             probNearSh2;
    %             shapleyEngineTorque = probNearSh1*strategyEng(idr1) + probNearSh2*strategyEng(idr2);
    %             shapleyMotorTorque = probNearSh1*strategyMot(idc1) + probNearSh2*strategyMot(idc2);          
    %         else
    %              [~, ind] = ismembertol([shEngine, shMotor],payoffBoth,0.001,'ByRows',true); 
    %              idr1 = 0;
    %              idc1 = 0;
    %              [idr1, idc1] = ind2sub(size(payoffEngine), ind);             
    %              shapleyEngineTorque = strategyEng(idr1);
    %              shapleyMotorTorque = strategyMot(idc1);    
    %         end

           
            %lightpurple = [163 154 255] ./ 255;        
            %p10 = plot(payoffStrEng, payoffStrMot, 'o',...
            %    'MarkerFaceColor', lightpurple, 'MarkerEdgeColor', lightpurple, ...
            %    'MarkerSize', 13);

            %limegreen = [194 242 1] ./ 255;
            %p3 = plot(bestPayoffEngPareto, bestPayoffMotPareto, 'og', ...
            %    'MarkerFaceColor', 'g', 'MarkerSize', 12);    
            %p5 = plot(payoffEngNashNPG, payoffMotNashNPG, 'o', ...
            %    'MarkerFaceColor','m', 'MarkerEdgeColor', 'm',...
            %    'MarkerSize', 13);    
            %p4 = plot(payoffEngNash, payoffMotNash, 'oy', ...
            %    'MarkerFaceColor', 'y', 'MarkerSize', 10);     
            %p41 = plot(bestPayoffEngNashLH(1), bestPayoffMotNashLH(1), 'oc', ...
            %    'MarkerFaceColor', 'c', 'MarkerSize', 9);      
            %p42 = plot(bestPayoffEngNashLH(2), bestPayoffMotNashLH(2), 'o', ...
            %    'MarkerFaceColor', 'r', 'MarkerEdgeColor','r','MarkerSize', 7);     
            %p43 = plot(bestPayoffEngNashLH(3), bestPayoffMotNashLH(3), 'o', ...
            %    'MarkerFaceColor', limegreen,'MarkerEdgeColor', limegreen, 'MarkerSize', 5);         
            %p6 = plot(payoffEngNashSol, payoffMotNashSol,'or', ...
            %    'MarkerFaceColor',[1,0.6,0] , 'MarkerEdgeColor', [1,0.6,0] ,...
            %    'MarkerSize', 9);

            %purple = [118 31 133] ./ 255;        
            %p7 = plot(ks(1,1), ks(1,2), 'o', 'MarkerFaceColor', purple, ...
            %    'MarkerEdgeColor', purple, 'MarkerSize', 9);
            %pink = [254 164 191] ./ 255;       
            %p8 = plot(payoffBoth(imput(indCore),1), payoffBoth(imput(indCore),2), 'o', ...
            %    'MarkerFaceColor',pink, 'MarkerEdgeColor',pink,...
            %    'MarkerSize', 8);      

            %p9 = plot(shEngine, shMotor, 'o', 'MarkerFaceColor', limegreen, ...
            %    'MarkerEdgeColor', limegreen, 'MarkerSize', 7);
            %p2 = p9;

            %for r = 1 : size(paretoIndex,1)
            %    linearIndex = sub2ind([m e], paretoIndex(r,2), paretoIndex(r,1));           
            %    p2 = plot(x(linearIndex), y(linearIndex), 'o', ...
            %        'MarkerEdgeColor', [0,0.5,0], 'MarkerFaceColor',[0,0.5,0],...
            %        'MarkerSize',6);
            %end

            %darkred = [185 16 20] ./ 255;
            %pi = plot(m1, m2, 'o', 'MarkerSize', 4, 'MarkerFaceColor',darkred ,...
            %'MarkerEdgeColor', darkred);


            %legend([p1 p2 p3], 'Payoff', ...         
            %'Pareto optimal payoff', ...  
            %'Best Pareto payoff', ... 
            %'Location', 'northwest');       
            %'Nash Equilibrium Lemke-Howson (conflict point)', ... 
            %'Kalai-Smorodinsky Solution', ...
            %'Core', ...        
            %'Shapley value', ...
            %'Mixed Strategies', ...
          

            %'Ideal point', ...       
            %'Nash Equilibrium Lemke-Howson k0=1', ...
            %'Nash Equilibrium Lemke-Howson k0=8', ...     
            %'Nash Equilibrium Lemke-Howson k0=15' , ... 
            %'Nash Equilibrium Lemke-Howson k0=23' , ...          
            %'Nash Equilibrium NPG', ...       

            %xlabel('Payoff Engine');
            %ylabel('Payoff Motor');
            %hold off
       
            [ engineTorque, motorTorque ] = payofftotorque(payoffEngNash, ...
                payoffMotNash, payoffBoth, strategyEng, strategyMot);
       
            %end
    catch
    	motorTorque = requiredTorqueR;
        engineTorque = 0;
    end           
end

