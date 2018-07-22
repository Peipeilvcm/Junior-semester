%计算y轴偏离中心值
M=xlsread('A题附件.xls',2,'A1:FX512');
x=1;
tmp=10000.0000;
for i=1:180
    a=1;
    b=512;
    d=0.0000;
    while(a<b)
        if M(a,i) == 0
            a=a+1;
        elseif M(b,i) == 0
            b=b-1;
        else
            d=d+(M(a,i)-M(b,i))^2;
            a=a+1;
            b=b-1;
        end
    end
    if d<tmp
        tmp=d;
        x=i;
    end
end
disp(tmp);
disp(x);