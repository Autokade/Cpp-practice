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
