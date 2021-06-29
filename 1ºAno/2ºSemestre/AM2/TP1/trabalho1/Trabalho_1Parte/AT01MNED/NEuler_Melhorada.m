%Alunos:
%Ana Sofia Janeiro 2019132578
%Bruno Teixeira 2019100036
%Rafael Ribeiro 2019131989
%Gonçalo Correia 2019150122



function y = NEuler_Melhorada(f,a,b,n,y0)

h = (b-a)/n;
t = a:h:b;
y = zeros(n+1,1);
y(1) = y0;
z(1) = y0;

for i = 1:n
    z(i+1) = y(i)+h*f(t(i),y(i));
    y(i+1,1) = y(i)+(h/2)*(f(t(i),y(i))+f(t(i+1),z(i+1)));
end