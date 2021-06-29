%Alunos:
%Ana Sofia Janeiro 2019132578
%Bruno Teixeira 2019100036
%Rafael Ribeiro 2019131989
%Gonçalo Correia 2019150122

function [t, u, v] = NRK4SED(f, g, a, b, n, u0, v0)
    h=(b-a)/n;
    t=a:h:b;
    u = zeros(1, n+1);
    v = zeros(1, n+1);
    u(1)=u0;
    v(1)=v0;
    
    for i=1:n
        k1u = h * f(t(i), u(i), v(i));
        k1v = h * g(t(i), u(i), v(i));
   
        k2u = h * f(t(i)+(h/2), u(i)+(k1u/2), v(i)+(k1v/2));
        k2v = h * g(t(i)+(h/2), u(i)+(k1u/2), v(i)+(k1v/2));
        
        k3u = h * f(t(i)+(h/2), u(i)+(k2u/2), v(i)+(k2v/2));
        k3v = h * g(t(i)+(h/2), u(i)+(k2u/2), v(i)+(k2v/2));
        
        k4u = h * f(t(i)+h, u(i) + k3u, v(i) + k3v);
        k4v = h * g(t(i)+h, u(i) + k3u, v(i) + k3v);
        
        u(i+1) = u(i) + (1/6)*(k1u + 2*k2u + 2*k3u + k4u);
        v(i+1) = v(i) + (1/6)*(k1v + 2*k2v + 2*k3v + k4v);
    end
end