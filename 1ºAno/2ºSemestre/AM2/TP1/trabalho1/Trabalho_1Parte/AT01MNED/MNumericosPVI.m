%  função para o uso dos três métodos em simultâneo
%Alunos:
%Ana Sofia Janeiro 2019132578
%Bruno Teixeira 2019100036
%Rafael Ribeiro 2019131989
%Gonçalo Correia 2019150122

function y = MNumericosPVI(f,a,b,n,y0)

MetodoEuler=NEuler(f,a,b,n,y0);
MetodoRK2=NRK2(f,a,b,n,y0);
MetodoRK4=NRK4(f,a,b,n,y0);


y=table(MetodoEuler',MetodoRK2',MetodoRK4','VariableNames',{'MetodoEuler','MetodoRK2','MetodoRK4'});