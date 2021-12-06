using Ficha_4.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Ficha_4.App_Data
{
    public class DadosExemplo
    {
        static List<UnidadeMonetaria> ListaDeUnidadesMonetarias;
        static int counter = 0;

        public static List<UnidadeMonetaria> UnidadesMonetarias
        {
            get
            {
                if (ListaDeUnidadesMonetarias == null)
                    ListaDeUnidadesMonetarias = GerarDadosAleatorios();

                return ListaDeUnidadesMonetarias;
            }
        }

        public static int GetId()
        {
            return ++counter;
        }

        static private List<UnidadeMonetaria> GerarDadosAleatorios()
        {
            List<UnidadeMonetaria> newList = new List<UnidadeMonetaria>();
            UnidadeMonetaria um1 = new UnidadeMonetaria
            {
                Codigo = "USD",
                ValorPorEuro = 0.88,
                Id = ++counter,
                Data = DateTime.Now
            };
            UnidadeMonetaria um2 = new UnidadeMonetaria
            {
                Codigo = "JPY",
                ValorPorEuro = 0.077,
                Id = ++counter,
                Data = DateTime.Now
            };

            newList.Add(um1);
            newList.Add(um2);

            return newList;
        }
    }
}
