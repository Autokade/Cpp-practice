clc
clear all
f = @(x) x^3-4*x^2-10;
g = @(x) x-((x^3+4*x^2-10)/(3*x^2+8*x));
d = @(x) ((6*x+8)*(x^3+4*x^2-10))/(3*x^2+8*x)^2;
e = 0.0001;
i = 1;
N = 10000;
a = 1;
b = 2;
x0=0
if(abs(d(x0)) < 1)
    disp('Fixed point exist');
else
    disp('Fixed point may or may exist');
end
while(i <= N)
    x1 = g(x0);
    if abs(x1-x0) < e
        x1;
        break;   
    end
    x0 = x1;
    i = i + 1;
end
disp('Root is');
disp(x1);