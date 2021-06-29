%N_ODE45  ODE45 do Matlab.
%   [t,y] = N_ODE45(f,a,b,n,y0) Método numérico para a resolução de um PVI
%   y'= f(t,y) com t=[a, b] e y(a)=y0 condição inicial  
%
%Alunos:
%Ana Sofia Janeiro 2019132578
%Bruno Teixeira 2019100036
%Rafael Ribeiro 2019131989
%Gonçalo Correia 2019150122



 
function [t,y]=ODE45(f,a,b,n,y0)
h=(b-a)/n;
tspan=a:h:b;
[t,y] = ode45(f,tspan,y0);