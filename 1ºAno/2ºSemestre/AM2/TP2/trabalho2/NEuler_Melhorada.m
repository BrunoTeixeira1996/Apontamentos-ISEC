%Alunos:
%Ana Sofia Janeiro 2019132578
%Bruno Teixeira 2019100036
%Rafael Ribeiro 2019131989
%Gonçalo Correia 2019150122



function [t, u, v] = NEuler_Melhorada(f,g,a,b,n,u0,v0)
    h = (b-a)/n;
    t = a:h:b;
    u = zeros(1,n+1);
    u(1) = u0;
    v = zeros(1,n+1);
    v(1) = v0;
   
    for i=1:n
        uFun = f(t(i),u(i),v(i));
        vFun = g(t(i),u(i),v(i));
        u(i+1)=u(i)+h*(uFun+f(t(i+1), u(i)+h*uFun, v(i)+h*uFun))/2;
        v(i+1)=v(i)+h*(vFun+g(t(i+1), u(i)+h*uFun, v(i)+h*uFun))/2;
    end

end
