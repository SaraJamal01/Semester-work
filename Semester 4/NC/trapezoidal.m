% Clear Screen
clc

% Setting x as dependent variable
syms x;
sum = 0;
disp('Composite Trapezoidal Rule');

% Take input
y = input('Enter an equation to approximate integral: ');
a = input('Enter lower limit of integral: ');
b = input('Enter upper limit of integral: ');
n = input('Enter number of subintervals n: ');

% Calculating h
h=(b-a)/n;

% Evaluating sum of middle ordinates
for i=1:1:n-1
  k=a+i*h;
  j = eval(subs(y,x,k));
  sum=sum+j;
end

% Evaluating first and last ordinates
fa = eval(subs(y,x,a));
fb = eval(subs(y,x,b));

% Trapezoidal formula
integral=h/2*(fa+fb+2*sum);   
fprintf('\n The value of integration is %f',integral);