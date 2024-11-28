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