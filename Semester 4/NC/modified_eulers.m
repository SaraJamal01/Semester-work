% Clear Screen
clc

% Setting x and y as variable
syms x;
syms y;
disp('Euler''s Method' );

% Take input
f = input('Enter an initial-value problem (dy/dx): ');
a = input('Enter lower limit of x: ');
b = input('Enter upper limit of x: ');
fprintf('Enter initial value of y(%d)',a);
y0 = input(': ');
h = input('Enter step size h: ');

fprintf('\n x        y ');

% Applying Modified Euler's Method
while a <= b
    fprintf('\n%f  %f ',a,y0); 
    j = eval(subs(f,{x,y},{a,y0}));  % Substituting x and y in function
    k = y0+(h*j);   % Modified Euler's formula
    c=a+h;
    u = eval(subs(f,{x,y},{a,y0}));
    v = eval(subs(f,{x,y},{c,k}));
    y1 = y0 + h/2*(u + v);
    a=c;
    y0=y1;  
end
