%DI_RTrapezios Calculo Integração Numérica através da Regra dos Trapézios
%   t = DI_RTrapezios(f,a,b,n)
%   t = h*(f(a)+f(b)+t)/2;
%
%INPUT:
%   f - função real de variável real x
%   [a, b] - extremos do intervalo da variável independente x
%   n - número de subintervalos ou iterações da regra
%OUTPUT: 
%   t - Resultado da área do Integral
%   t = h*(f(a)+f(b)+t)/2 , i=2,...,n-1

%Alunos:
%Ana Sofia Janeiro 2019132578
%Bruno Teixeira 2019100036
%Rafael Ribeiro 2019131989
%Gonçalo Correia 2019150122

function T = DI_RTrapezios(f,a,b,n)

h = (b-a)/n;
s = 0;
x=a;

for i=1:n-1
	x=x+h;
	s = s+f(x);
end

T = h/2*((f(a) +2*s + f(b)));
