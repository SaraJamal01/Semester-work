% Clear Screen
clc

% Setting x as dependent variable
syms x;
count = 0;
disp('Regular Falsi Method');

% Taking input
y = input('Enter an equation to find root: ');
x1 = input('Enter lower limit of root: ');
x2 = input('Enter upper limit of root: ');
e = input('Tolerance level: ');

% Substituting limits in equation
fx1 = eval(subs(y,x,x1));
fx2 = eval(subs(y,x,x2));

fprintf('\n\nx1\t\tx2\t\txn\t\tf(xn)\n');

% Checking if root lies within the given limits
if fx1*fx2 > 0 
    disp('Root does not lie within the given limits.');

% Applying regular falsi method otherwise
else
    x3 = (x1*fx2 - x2*fx1)/(fx2 - fx1);  % Regular falsi formula
    fx3 = eval(subs(y,x,x3));
  while abs(fx3)>e
    fprintf('%f\t%f\t%f\t%f\n',x1,x2,x3,fx3);
    if fx1*fx3< 0
            x2 =x3;
            fx2 = eval(subs(y,x,x2));
    else
            x1 =x3;
            fx1 = eval(subs(y,x,x1));
    end
   
    x3 = (x1*fx2 - x2*fx1)/(fx2 - fx1);
    fx3 = eval(subs(y,x,x3));
    count = count + 1;
  end
end
fprintf('\nRoot is: %f', x3);
fprintf('\nTook %d iterations\n', count);
