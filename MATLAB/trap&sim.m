clc;
clear all;
f = @(x) (exp(-x*x)*cos(x));
a = input('Enter the lower limit: ');
b = input('Enter the upper limit: ');
n = input('Enter number of intervals: ');
h = ((b-a)/n);
sum = 0;
for i = 1:n-1
    sum = sum + 2* f(a+i*h);
end
trap = (h/2)*(f(a)+f(b)+sum);
disp(trap);

sum1 = 0;
for i = 1:n-1
   if rem(i,2)==0
       sum1=sum1+2*f(a+i*h)
   else
       sum1=sum1+4*f(a+i*h)
end
simpson = (h/3)*(f(a)+sum1+f(b));
disp(simpson);c