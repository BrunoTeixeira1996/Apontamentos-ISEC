using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercicio3
{
    class Retangulo: FiguraPlana
    {
        public float Largura { get; set; }
        public float Comprimento { get; set; }

        // construtor do retangulo
        public Retangulo(float LarguraRetangulo, float ComprimentoRetangulo)
        {
            Largura = LarguraRetangulo;
            Comprimento = ComprimentoRetangulo;
        }

        public override double Area() { return Comprimento * Largura; }
        public override double Perimetro() { return 2 * (Comprimento + Largura); }
        public override string ToString()
        {
            return string.Format("Retangulo : Comprimento = {0:F2} , Largura = {1:F2} \nArea = {2:F2} , Perimetro = {3:F2} \n", Comprimento ,Largura, Area(), Perimetro());
        }


    }
}
