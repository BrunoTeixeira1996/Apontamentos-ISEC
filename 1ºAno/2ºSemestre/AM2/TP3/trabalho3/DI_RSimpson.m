%DI_RSimpson Calculo Integração Numérica através da Regra de Simpson
%   s = DI_RSimpson(f,a,b,n)
%   s = h*(f(a)+f(b)+s)/3;
%
%INPUT:
%   f - função real de variável real x
%   [a, b] - extremos do intervalo da variável independente x
%   n - número de subintervalos ou iterações da regra
%OUTPUT: 
%   s - Resultado da área do Integral
%   s = h*(f(a)+f(b)+s)/3 , i=2,...,n-1
%
%Alunos:
%Ana Sofia Janeiro 2019132578
%Bruno Teixeira 2019100036
%Rafael Ribeiro 2019131989
%Gonçalo Correia 2019150122

function out_S = DI_RSimpson(f,a,b,n)

h = (b-a)/n;
s = 0;
x=a;

for i=1:n-1
	x=x+h;
	if mod(i,2)==0
		s = s+2*f(x);
	else
		s = s+4*f(x);
    end
end

out_S = h/3*((f(a)+s+f(b)));
