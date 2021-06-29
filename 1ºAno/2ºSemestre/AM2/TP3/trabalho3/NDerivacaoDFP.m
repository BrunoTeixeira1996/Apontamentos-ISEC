% NDerivacaoDFP Derivação Numérica - fórmula das diferenças progressivas 
% Formúla das Diferenças progressivas
% f'(xi)=(f(x(i+1))-f(x(i))/h
% INPUT:  f - função
%         [a, b] - intervalo de derivação
%         h - passo da discretização
%         y - imagens x vs y
% OUTPUT: [x, y] - malha de pontos
%         dydx - derivada de f 
%


function [x,y,dydx]=NDerivacaoDFP(f,a,b,h,y)
x=a:h:b;
n=length(x);
if nargin==4
    y=f(x);
end
dydx=zeros(1,n);
for i=1:n-1
    dydx(i)=(y(i+1)-y(i))/h;
end
dydx(n)=(y(n)-y(n-1))/h;