% Clear Screen
clc

% Setting x as dependent variable
syms x;
sum = 0;
disp('Composite Midpoint rule' );

% Take input
y = input('Enter an equation to approximate integral: ');
a = input('Enter lower limit of integral: ');
b = input('Enter upper limit of integral: ');
n = input('Enter number of subintervals: ');

% Calculating h
h=(b-a)/n;

for i=0:1:n-1
   k0=a+i*h;
   k1=a+((i+1)*h);
   k=(k0+k1)/2;       % Calculating midpoints
   j = eval(subs(y,x,k));
   sum = sum + j;
end

% Midpoint formula
integral=h*sum;
fprintf('\n The value of integration is %f',integral);