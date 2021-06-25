% Clear Screen
clc

% Setting x and y as variable
syms x;
syms y;
disp('Runge-Kutta Method (4th order)' );

% Take input
f = input('Enter an initial-value problem (dy/dx): ');
a = input('Enter lower limit of x: ');
b = input('Enter upper limit of x: ');
fprintf('Enter initial value of y(%d)',a);
y0 = input(': ');
h = input('Enter step size h: ');
N = (b-a)/h;

fprintf('\n x        y ')

% Applying R-K Method
while a<=b 
    fprintf('\n%f  %f ',a,y0);
    k1 = h*eval(subs(f,{x,y},{a,y0}));
    k2 = h*eval(subs(f,{x,y},{a+(h/2),y0+(k1/2)}));
    k3 = h*eval(subs(f,{x,y},{a+(h/2),y0+(k2/2)}));
    k4 = h*eval(subs(f,{x,y},{a+h,y0+k3}));
    w = y0 + (1/6)*(k1+2*k2+2*k3+k4);  % R-K formula
    y0 = w;
    c = a+h;
    a = c;
end
