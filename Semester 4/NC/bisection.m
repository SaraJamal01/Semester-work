% Clear Screen
clc

% Setting x as dependent variable
syms x;
count = 0;
max = 50;
disp('Bisection Method');

% Taking input
y = input('Enter an equation to find root: ');
x1 = input('Enter lower limit of root: ');
x2 = input('Enter upper limit of root: ');
e = input('Tolerance level: ');

% Substituting limits in equation
fx1 = eval(subs(y,x,x1));
fx2 = eval(subs(y,x,x2));

% Checking if root lies within the given limits
if fx1*fx2 > 0 
    disp('Root does not lie within the given limits.');

    % Applying bisection method otherwise
else
    x3 = (x1+x2)/2;   % Bisection formula
    fx3 = eval(subs(y,x,x3));
    fprintf('\n\nx1\t\tx2\t\txn\t\tf(xn)\n');
    
    while abs(fx3)>e
        fprintf('%f\t%f\t%f\t%f\n',x1,x2,x3,fx3);
        if fx1*fx3 < 0  
            x2 = x3;   % Include upper limit if opposite signs 
        else
            x1 = x3;   % Include lower limit if opposite signs
        end
        x3 = (x1+x2)/2;
        fx3 = eval(subs(y,x,x3));
        count = count + 1;
        if count>=max
            break;
        end
    end
    if count>= max
        disp('Can''t find root');
        exit();
    end
    fprintf('\nRoot is: %f', x3);
    fprintf('\nTook %d iterations\n', count);
    
end

