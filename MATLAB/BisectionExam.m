clc
clear
h=1

f=@(x) x^2-458;
for x= -100:h:100
    if(f(x)*f(x+h)<0)
        a=x
        b=x+h
    end
end
n=0;
a
b
while(abs(a-b)>10^-2)
    c=(a+b)/2;
    n=n+1;
    if(f(a)*f(c)<0)
        b=c;
    else
        a=c;
    end
end
disp(a)
disp(b)
disp(n)
