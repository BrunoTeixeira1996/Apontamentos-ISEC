% Formula das Diferenças regressivas em 3 pontos
% f'(xi)=(f(x(i-2))-4*f(x(i-1)+3*f(x(i)))/(2*h)
% INPUT:  f - fun玢o
%         [a, b] - intervalo de deriva玢o
%         h - passo da discretiza玢o
%         y - imagens x vs y
% OUTPUT: [x, y] - malha de pontos
%         dydx - derivada de f 
%
%Alunos:
%Ana Sofia Janeiro 2019132578
%Bruno Teixeira 2019100036
%Rafael Ribeiro 2019131989
%Gonçalo Correia 2019150122

function [x,y,dydx]=DI_DFRegressivas_3(f,a,b,h,y)
x=a:h:b;
n=length(x);
if nargin==4
    y=f(x);
end
dydx=zeros(1,n);
dydx(1)=( (-3)*y(1) + 4*y(2) - y(3) )/(2*h);
dydx(2)=( (-3)*y(2) + 4*y(3) - y(4) )/(2*h);
for i=3:n
	dydx(i)=( y(i-2) - 4*y(i-1) + 3*y(i) )/(2*h);
end