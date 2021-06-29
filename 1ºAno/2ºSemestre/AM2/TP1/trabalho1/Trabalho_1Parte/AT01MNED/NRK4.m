% N_RK4 - Metodo de Runge-Kutta de 2 ordem
% y = RK4(f, a, b, n, y0)
% y'= f(t,y) com t=[a, b] e y(a)=y0 condição inicial
% 
% INPUT:
%   f - função do 2º membro da Equação Diferencial
%   [a, b] - extremos do intervalo da variável independente t
%   n - número de subintervalos ou iterações do método
%   y0 - condição inicial t=a -> y=y0
% 
% OUTPUT: 
%   y - vector das aproximações discretas da solução exacta
%
%Alunos:
%Ana Sofia Janeiro 2019132578
%Bruno Teixeira 2019100036
%Rafael Ribeiro 2019131989
%Gonçalo Correia 2019150122

function y = NRK4(f,a,b,n,y0)

h = (b-a)/n;
t=a:h:b;
y=zeros(1,n+1);
y(1)=y0;


for i=1:n
    k1 = f(t(i), y(i));
    k2 = f(t(i)+(h/2), y(i)+(h*k1)/2);
    k3 = f(t(i)+(h/2), y(i)+h*(k2/2));
    k4 = f(t(i)+h, y(i)+(h*k3));
    
    y(i+1)=y(i)+(h/6)*(k1+2*k2+2*k3+k4);
    t(i+1)=t(i)+h;
    
end