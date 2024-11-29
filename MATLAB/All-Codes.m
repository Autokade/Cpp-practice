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

%Lagrange
clc;
clear all;
p1 = 1.3;
t = linspace(0 , 2*pi , 8)%0-2pi divied in 8 parts
y = @(x) sin(x).^2 ;
o = y(t)
n = length(t);
for i = 1:n
    l(i) = 1;
    for j = 1:n
        if j ~= i
            l(i) = ((p1 - t(j))/(t(i) - t(j))) * l(i);
            %x-x1/x0-x1
        end
    end
end
sum1 = 0;
for i = 1:n
    %   *yi
    sum1 = sum1 + l(i) * o(i);
end


disp(sum1);


%least square method

clc;
clear all;

sum1 = 0;
sum2 = 0;
sum3 = 0;
sum4 = 0;
x = [-2,-1,0,1,2];
y = [15,1,1,3,19];
n = 5;
%calculating $xi $yi $xiyi %xi^2
for i = 1 : n
    sum1 = sum1 + x(i);
    sum2 = sum2 + y(i);
    sum3 = sum3 + (x(i)*y(i));
    sum4 = sum4 + (x(i)*x(i));
end
syms a
syms b
x=[a,b];
A = [n,sum1;
    sum1,sum4]
B = [sum2;sum3];
x = inv(A)*(B);
disp(x);


%Newton divided difference

clc;
clear all;
f = @(x) exp(x);
x = [1,1.5,2,2.5];
n = 4;
y = [2.7183,4.4817,7.3891,12.1825];
%intialize dd with y in first column
for k=1:n
    dd(k,1)=y(k);
end
for j = 2:n%filling column 2 to last
    for i = j:n
        dd(i,j) = (dd(i,j-1)-dd(i-1,j-1))/(x(i)-x(i-j+1));
        %filling the rows
    end
end
disp(dd);
P=2.25
sum = 0;
for i = 1:n
    prod(i) = 1;
    for j = 1:i-1
        prod(i) = prod(i) * (P- x(j));
        %1  , (x-x0)  , (x-x0)(x-x1).....
    end
    sum = sum + (dd(i,i) * prod(i));
    %a0*   ,a1*   ,a2*.....
end
disp(sum);
disp(f(2.25));
disp(abs(sum - f(2.25)));

%power difference
clc;
clear all;
x0 = [1;1;0;1];
A = [1,1,0,0;1,2,0,1;0,0,3,3;0,1,2,3];
k0 = 0;
e = 0.001;
N = 10000;
t = 0;
while t <= N
    %multiply matrix with base
    y = A * x0;
    %take the max elemnt common
    k = max(abs(y));
    x0 = y / k;
    %stopping condition
    if abs(k0 - k) < e
        break;
    end
    k0 = k;
    t = t + 1;
end
disp('No of iteration required is: ');
disp(t);
disp('Eigen value is: ');
disp(k);
disp('Eigen vector is: ');
disp(x0);

%trap and simpson
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
disp(simpson);