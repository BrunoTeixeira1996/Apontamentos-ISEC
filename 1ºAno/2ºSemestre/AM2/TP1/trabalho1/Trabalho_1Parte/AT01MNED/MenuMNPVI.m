%MENUMNPVI  Menu de Métodos Numéricos para um PVI
%   y = MenuMNPVI(f,a,b,n,y0)
%   y'= f(t,y) com t=[a, b] e y(a)=y0 condição inicial  
%
%INPUT:
%   f - função do 2.É membro da Equação Diferencial
%   [a, b] - extremos do intervalo da variável independente t
%   n - número de subintervalos ou iterações do método
%   y0 - condição inicial t=a -> y=y0
%OUTPUT: 
%   y - vector das soluções aproximações
%
%Alunos:
%Ana Sofia Janeiro 2019132578
%Bruno Teixeira 2019100036
%Rafael Ribeiro 2019131989
%Gonçalo Correia 2019150122

function y=MenuMNPVI(f,a,b,n,y0)
y=[];
menuMNPVI = 1;
while menuMNPVI~=20
    clc
    disp('--------------------------------------------------')
    disp('           Métodos Numéricos para PVI             ')
    disp('--------------------------------------------------')
    menuMNPVI=menu('Métodos Numéricos para PVI', ...
                   'Método de Euler',...
                   'Método de Euler - Melhorado',...
                   'Método RK2',...
                   'Método RK4',...
                   'ODE45',....
                   'Todos',...
                   'Sair');
    switch menuMNPVI
        case 1
              y=table(NEuler(f,a,b,n,y0)','VariableNames',{'Método de Euler'});
        case 2
              y=NEuler_Melhorada(f,a,b,n,y0);
        case 3  
              y=table(NRK2(f,a,b,n,y0)','VariableNames',{'Método RK2'});                
        case 4
              y=table(NRK4(f,a,b,n,y0)','VariableNames',{'Método RK4'});
        case 5
              y=ODE45(f,a,b,n,y0);
        case 6
              y=MNumericosPVI(f,a,b,n,y0);
        case 7
              break;
    end
    disp('-----------Solução aproximada do PVI---------')
    disp(y)
    input('Prima numa tecla para continuar !')
end
            