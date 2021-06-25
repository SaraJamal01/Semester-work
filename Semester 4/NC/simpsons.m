% Clear Screen
clc

% Setting x as dependent variable
syms x;
oddSum=0;
evenSum=0;
disp('Composite Simpson''s 1/3rd rule' );

% Take input
y = input('Enter an equation to approximate integral: ');
a = input('Enter lower limit of integral: ');
b = input('Enter upper limit of integral: ');
n = input('Enter number of subintervals (even): ');
if rem(n,2)==1 
   n = input('\nInvalid value of n!\n Enter an even number: ');
end

% Calculating h
h=(b-a)/n;

% Evaluating sum of middle ordinates

for i=1:1:n-1
   k=a+i*h;
   j = eval(subs(y,x,k));
    if rem(i,2)==1
       oddSum=oddSum+j;   % Evaluating sum of odd ordinates
     else
       evenSum=evenSum+j; % Evaluating sum of even ordinates
    end
end

% Evaluating first and last ordinates
fa = eval(subs(y,x,a));
fb = eval(subs(y,x,b));

% Simpson's 1/3rd formula
integral=h/3*(fa+fb+(4*oddSum)+(2*evenSum));
fprintf('\n The value of integration is %f',integral);