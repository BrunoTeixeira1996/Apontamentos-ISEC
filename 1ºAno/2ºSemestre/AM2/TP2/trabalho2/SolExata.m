%Alunos:
%Ana Sofia Janeiro 2019132578
%Bruno Teixeira 2019100036
%Rafael Ribeiro 2019131989
%Gonçalo Correia 2019150122

function [t, exata] = SolExata(ODE, a, b, n, u0, v0)
    syms y(t);
    tempExata = dsolve(ODE, ['y(0)=',num2str(u0)], ...
        ['Dy(0)=',num2str(v0)], 't');
    if(~isempty(tempExata))
        ext=@(t) eval(vectorize(char(tempExata)));
        h=(b-a)/n;
        t=a:h:b;
        exata=ext(t);
    else
        exata=[];
end