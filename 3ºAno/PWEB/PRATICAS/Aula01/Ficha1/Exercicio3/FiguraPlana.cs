using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercicio3
{
    // class abstrata que representa uma Figura Plana
    // com esta class nao é possivel serem criados objetos
    // serve apenas para mostrar informação ao utilizador como se fosse uma especie de esqueleto
    abstract class FiguraPlana
    {
        public abstract double Area();
        public abstract double Perimetro();

        // ToString() é mesmo um metodo de classes no c# então é preciso dar override porque 
        // como é uma classe abstrata nao vai derivar de nenhuma, nem se quer vai ser instanciada
        // https://www.damirscorner.com/blog/posts/20131028-UsingAbstractOverrideInC.html
        public abstract override string ToString();
    }
}
