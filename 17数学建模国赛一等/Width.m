%求出109条射线分别穿过椭圆的长度
op=[];
x=0:34/123:15
for i=size(x,2):109
    syms y
    z=x(i-size(x,2)+1);
    S1=(z^2/225)+(y^2/1600)-1;
    y=solve(S1);
    op(i)=abs(2*y(1));
end
for i=1:size(x,2)-1
    op(i)=op(110-i);
end
xlswrite('width',op);

