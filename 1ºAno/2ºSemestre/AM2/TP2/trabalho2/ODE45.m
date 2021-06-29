
function y = ODE45(f,a,b,n,y0)
    h = (b-a)/n;
    t = a:h:b;
    [~,yOde45] = ode45(f,t,y0);
    y=yOde45.';
end