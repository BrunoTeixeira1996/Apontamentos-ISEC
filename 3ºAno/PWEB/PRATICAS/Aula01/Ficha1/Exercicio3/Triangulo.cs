using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercicio3
{
    class Triangulo: FiguraPlana
    {
        public float LadoA { get; set; }
        public float LadoB { get; set; }
        public float LadoC { get; set; }

        public Triangulo(float LadoAT, float LadoBT, float LadoCT)
        {
            LadoA = LadoAT;
            LadoB = LadoBT;
            LadoC = LadoCT;
        }

        public override double Area()
        {
            float primeiro = (LadoA + LadoB + LadoC) / 2;
            float segundo = primeiro * ((primeiro - LadoA) * (primeiro - LadoB) * (primeiro - LadoC));
            return Math.Sqrt(segundo);
        }
        public override double Perimetro() { return LadoA + LadoB + LadoC; }

        public override string ToString()
        {
            return string.Format("Triangulo : LadoA = {0:F2} , LadoB = {1:F2}, LadoC = {2:F2}\nArea = {3:F2} , Perimetro = {4:F2} \n",  LadoA, LadoB, LadoC, Area(), Perimetro());
        }
    }
}
