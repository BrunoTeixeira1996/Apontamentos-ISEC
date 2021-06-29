%Interface EDO/PVI
%
%
%Alunos:
%Ana Sofia Janeiro 2019132578
%Bruno Teixeira 2019100036
%Rafael Ribeiro 2019131989
%Gonçalo Correia 2019150122
clear
primeiraVez=1;
menuPVI=1;
while menuPVI~=5
    clc;
    disp('--------------------------------------------------------------')
    disp('            PROBLEMAS DE VALOR INICIAL (PVI)                  ')
    disp('------------------------------------------------------------- ')
    if (~primeiraVez)
    menuPVI=menu('Métodos Numéricos para PVI',...
                 'Dados do PVI',...
                 'Solução Exata',...
                 'Solução Aproximada',...
                 'Gráficos de Resultados',...
                 'Sair');
    else
        primeiraVez=0;
        menuPVI=1;
    end
    y=[];
    switch menuPVI
        case 1
            
            while 1 %verifica se existe uma variavel simbolica(t ou y)
              strF=input('\n f(t,y) = ','s');
              f=@(t,y) eval(vectorize(strF));
              try
                  syms t y;
                  fTeste=f(t,y);
                  break;
                  
              catch me
                  errordlg('Erro! Introduza uma função em t,y','ERRO','modal');
              end
            end
            
            while 1
               a=str2num(input('a = ','s'));
               if(isscalar(a) && isreal(a))
                    break;
                else
                    errordlg('Erro! Introduza um numero real para a','ERRO','modal');
                end
            end
            
            while 1 %verifica se o b é escalar, real e se é maior que a
              b=str2num(input('b = ','s'));
              if(isscalar(b) && isreal(b) && b > a)
                  break;
              else
                  errordlg('Introduza um numero real b, com b > a','ERRO','modal');
              end
            end
            while 1
               n=str2num(input('n = ','s'));
               if(isscalar(n) && n == floor(n) && n > 0)
                   break;
               else
                errordlg('Introduza um valor correto para n','ERRO','modal');
               end
            end
            while 1
              y0=str2num(input('y0 = ','s'));
              if(isscalar(y0))
                  break;
              else
                 errordlg('Introduza um valor escalar para o y0','ERRO','modal');
              end
            end
              
        case 2
              sExata=dsolve(['Dy=', strF],...
                            ['y(',num2str(a),')=',num2str(y0)]);
              g=@(t) eval(vectorize(char(sExata)));
              h=(b-a)/n;
              t=a:h:b;
              yExata=g(t);
              disp('Solução exata do PVI')
              disp(yExata)
        case 3
            y=MenuMNPVI(f,a,b,n,y0);
        case 4
            graficoRes(f,a,b,n,y0);

    end
    input('Prima numa tecla para continuar')
end
    
