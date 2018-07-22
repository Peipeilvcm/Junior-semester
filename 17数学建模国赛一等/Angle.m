%拟合180个旋转角度
M=xlsread('compare.xlsx',1,'C1:C180');
cnt=1;
ans=[];%生成旋转角度
x0=(223-256)*34/123;%旋转中心
y0=(256-235)*34/123;%旋转中心
theta=0;
tmp=28;%起始角度
mina=tmp;
while(cnt <= 180)%180次旋转
    mind=inf;
    for i=0.5:0.5:2
        theta=(i+tmp)/180*pi;
        d1=0;
        d2=0;
        syms x
        syms y
        S1=tan(1/2*pi+theta)*x+y0-tan(1/2*pi+theta)*x0-y;%中心轴线直线方程
        S2=(x^2/225)+(y^2/1600)-1;
        S3=(x-45)^2+y^2-16;
        [x,y]=solve(S1,S2);
        if imag(x)==0%判断直线与椭圆是否相交
            if imag(y)==0
                d1=sqrt((x(1)-x(2))^2+(y(1)-y(2))^2);
            else
                d1=0;
            end
        else
            d1=0;
        end
        [x,y]=solve(S1,S3);
        if imag(x)==0%判断直线与圆是否相交
            if imag(y)==0
                d2=sqrt((x(1)-x(2))^2+(y(1)-y(2))^2);
            else
                d2=0;
            end
        else
            d2=0;
        end
        d=1.766*(d1+d2)+0.3429;
        if abs(d-M(cnt,:))<mind%寻找最接近接受信息的角度
            mind=abs(d-M(cnt,:));
            mina=tmp+i;
            ans(cnt)=mina;
            disp(mina);
        end
    end
    tmp=ans(cnt);
    cnt=cnt+1;
end
xlswrite('角度',ans);