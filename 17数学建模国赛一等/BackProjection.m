%���ݽ�����Ϣ�������ɼ�����״
%theta=29.5:180+28.5;%�Ľ�ģ����ת�Ƕ�ÿ������1��
theta=xlsread('�Ƕ�.xls',1,'A1:A180');
M=xlsread('A�⸽��.xls',2,'A1:FX512');%����Ľ�����Ϣ����
d=34/123*2.56;%̽����������Ŵ�2.56��
N = 512;%X��������
Axis=256;%������
%��Ϊ��Ӧ��excel�����������У����������У�������ת���ĵ�x��y����λ��
xAxis=(256-235)*34/123*2.56;%��ת���ĵ�������
yAxis=(223-256)*34/123*2.56;%��ת���ĵĺ����꣬���Ŵ�2.56��
Mf = fft(M,N);
%�����˲���
for i=0:N/2+1
    filter(i+1)=2*i/N;
end
for i=N/2+2:N
    filter(i)=filter(N+2-i);
end
%���վ������˲������
for i = 1:180
    Mt(:,i) = Mf(:,i).*filter';
end  
%�渵��Ҷ�任
Mb = ifft(Mt); 
ans = zeros(256);%���ɷ�ͶӰ����
%����180��ɨ��
for i = 1:180
    rad = theta(i)*pi/180;  
    for x = (-256/2+1+xAxis):256/2+xAxis
        for y = (-256/2+1-yAxis):256/2-yAxis
            %ɨ��256*256�����ϵ�ÿ����Ԫ
            t = round(y*cos(rad)-x*sin(rad));%�õ���ת���������
            if round(t/d+Axis) > 0 && round(t/d+Axis) <= 512
                %��������õ���ǰ�ǵڼ������ߣ���������Լ���ټ�������ֵ256��
                %�ɵõ���Ӧ���˲������ϵ����λ�þ����ۼ�ֵ
                ans(round(x+256/2-xAxis),round(y+256/2+yAxis))=ans(round(x+256/2-xAxis),round(y+256/2+yAxis))+Mb(round(t/d+Axis),i);
            else
                ans(round(x+256/2-xAxis),round(y+256/2+yAxis))=0;
            end
        end
    end
end
ans = ans/180;%������180��ɨ��
for i=1:256
    for j=1:256
        if ans(i,j)<0.1
            ans(i,j)=0;
        end
    end
end
imshow(ans)%���ɻҶ�ͼ��
xlswrite('ans',ans);
%imagesc(ans)%���ɲ�ɫͼ��