%根据接收信息矩阵生成几何形状
%theta=29.5:180+28.5;%改进模型旋转角度每次增加1度
theta=xlsread('角度.xls',1,'A1:A180');
M=xlsread('A题附件.xls',2,'A1:FX512');%导入的接收信息矩阵
d=34/123*2.56;%探测器间隔，放大2.56倍
N = 512;%X射线数量
Axis=256;%中心轴
%因为对应到excel中纵坐标是行，横坐标是列，所以旋转中心的x与y换了位置
xAxis=(256-235)*34/123*2.56;%旋转中心的纵坐标
yAxis=(223-256)*34/123*2.56;%旋转中心的横坐标，均放大2.56倍
Mf = fft(M,N);
%生成滤波器
for i=0:N/2+1
    filter(i+1)=2*i/N;
end
for i=N/2+2:N
    filter(i)=filter(N+2-i);
end
%接收矩阵与滤波器卷积
for i = 1:180
    Mt(:,i) = Mf(:,i).*filter';
end  
%逆傅里叶变换
Mb = ifft(Mt); 
ans = zeros(256);%生成反投影矩阵
%进行180次扫描
for i = 1:180
    rad = theta(i)*pi/180;  
    for x = (-256/2+1+xAxis):256/2+xAxis
        for y = (-256/2+1-yAxis):256/2-yAxis
            %扫描256*256矩阵上的每个单元
            t = round(y*cos(rad)-x*sin(rad));%得到旋转后的纵坐标
            if round(t/d+Axis) > 0 && round(t/d+Axis) <= 512
                %用纵坐标得到当前是第几条射线，即坐标除以间隔再加上中心值256，
                %可得到对应在滤波矩阵上的相对位置就是累加值
                ans(round(x+256/2-xAxis),round(y+256/2+yAxis))=ans(round(x+256/2-xAxis),round(y+256/2+yAxis))+Mb(round(t/d+Axis),i);
            else
                ans(round(x+256/2-xAxis),round(y+256/2+yAxis))=0;
            end
        end
    end
end
ans = ans/180;%最后除以180次扫描
for i=1:256
    for j=1:256
        if ans(i,j)<0.1
            ans(i,j)=0;
        end
    end
end
imshow(ans)%生成灰度图像
xlswrite('ans',ans);
%imagesc(ans)%生成彩色图像