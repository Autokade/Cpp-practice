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