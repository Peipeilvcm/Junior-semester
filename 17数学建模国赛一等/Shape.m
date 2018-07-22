%画出形状
M=xlsread('A题附件.xls',1,'A1:IV256');
for i=1:256
    for j=1:256
        if M(i,j) > 0
            plot(j,i,'k.')
            hold on;
        end
    end
end
plot(0,256);
hold on;
plot(256,256);
hold on;
plot(256,0);