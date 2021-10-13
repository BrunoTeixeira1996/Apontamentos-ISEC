using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercicio3
{
    class Circulo: FiguraPlana
    {
        public float Raio { get; set; }

        public Circulo(float RaioCirculo)
        {
            Raio = RaioCirculo;
        }

        public override double Area() { return Math.PI * (Math.Pow(Raio, 2)); }
        public override double Perimetro() { return 2 * Math.PI * Raio; }
        public override string ToString()
        {
            return string.Format("Circulo : Raio = {0}\nArea = {1:00.00} , Perimetro = {2:00.00}", Raio, Area(), Perimetro());
        }
    }
}
