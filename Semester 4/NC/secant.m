% Clear Screen
clc

% Setting x as dependent variable
syms x;
max = 50;
disp('Secant Method');

% Taking input
y = input('Enter an equation to find root: ');
x1 = input('Enter lower limit of root: ');
x2 = input('Enter upper limit of root: ');
e = input('Tolerance level: ');

% Substituting limits in equation
fx1 = eval(subs(y,x,x1));
fx2 = eval(subs(y,x,x2));

% Applying secant method
x3 = (x1*fx2 - x2*fx1)/(fx2 - fx1);  % Secant formula
fx3 = eval(subs(y,x,x3));

fprintf('\n\nx1\t\tx2\t\txn\t\tf(xn)\n');
fprintf('%f\t%f\t%f\t%f\n',x1,x2,x3,fx3);
count = 1; 
while count<max
    x1 = x2;
    fx1 = fx2;
    x2 = x3;
    fx2 = fx3;
    x3 = (x1*fx2 - x2*fx1)/(fx2 - fx1);
    fx3 = eval(subs(y,x,x3));
   
    fprintf('%f\t%f\t%f\t%f\n',x1,x2,x3,fx3);
    count = count + 1;
    if abs((x3-x2)/x2) < e
        fprintf('\nRoot is: %f', x3);
        break;
        
    end   
end

fprintf('\nTook %d iterations\n', count);
