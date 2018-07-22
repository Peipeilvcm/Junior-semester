%拟合衰变方程
p=xlsread('polyfit',1,'A1:A110');
q=xlsread('polyfit',1,'B1:B110');
G=polyfit(p,q,1);
m=polyval(G,p);
plot(p,q,'r.',p,m,'b')
poly2sym(double(G))