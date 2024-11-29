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


% fixedPT
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


% Gauss Elimination
clc;
clear all;
%agunmented matrix
A = [10,8,-3,1,16;2,10,1,-4,9;3,-4,10,1,10;2,2,-3,10,11];
n =4;
for i = 1 : n - 1
    p = i;
    %if all are 0 in column -no sol
    while (p <= n && A(p,i) == 0)
        p = p + 1;
    end
    if p == n+1
        disp('No unique solution');
        break;
    end
    %pivoting
    if p~=i
        temp=A(i,:);
        A(i,:)=A(p,:);
        A(p,:)=temp
    end
    %multiplier find and solving 
    for j = i+1 : n
        m = A(j,i)/A(i,i);
        %making 0
        A(j,:) = A(j,:) - (m*A(i,:));
    end
end
disp(A);
%if last is 0 x4 can be anything
if(A(n,n) == 0)
    disp('No unique solution');
end
%back substitution
for i = n : -1 : 1
    sum = 0;
    for j = i+1 : n
        sum = sum + A(i,j) * x(j);
        %c1*x1+c2x2+c3x3
    end
    %(b-c1*x1+c2x2+c3x3)/c0
    x(i) = (A(i,end) - sum)/A(i,i);
end
disp('The Solution is ');
disp(x);





%Gauss Seidal
clc
clear
a=[4.63,-1.21,3.22;
   -3.07,5.48,2.11;
   1.26,3.11,4.57];
b=[2.22;-3.17;5.11];
x0=[0,0,0];
x=[0,0,0];
n=3;
N=100;
tol=0.001;
%N iteration
for k=1:N
    %for all x
    for i=1:n
        sum1=0;
        sum2=0;
        %using precalculated x(i)
        for j=1:i-1
            sum1=sum1+a(i,j)*x(j)
        end
        %using previous x ie x0
        for j=i+1:n
            sum2=sum2+a(i,j)*x0(j)
        end
        x(i)=(1/a(i,i))*(b(i)-sum1-sum2)
        %stopping
        if norm(x(i)-x0(i))<tol
           break;
        end
        x0(i)=x(i);
    end
end
x
