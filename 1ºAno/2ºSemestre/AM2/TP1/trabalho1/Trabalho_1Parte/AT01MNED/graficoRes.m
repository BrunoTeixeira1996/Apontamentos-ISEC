%Alunos:
%Ana Sofia Janeiro 2019132578
%Bruno Teixeira 2019100036
%Rafael Ribeiro 2019131989
%Gonçalo Correia 2019150122


function graficoRes(f,a,b,n,y0)


MetodoEuler=NEuler(f,a,b,n,y0);
MetodoRK2=NRK2(f,a,b,n,y0);
MetodoRK4=NRK4(f,a,b,n,y0);

h=(b-a)/n;
t=a:h:b;


hold on

plot(t,MetodoEuler,'--r');
plot(t,MetodoRK2,'-.b');
plot(t,MetodoRK4,'--g');
legend('Euler','Metodo RK2','Metodo RK4');
grid on
xlabel('t');
ylabel('y');
hold off