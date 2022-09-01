using System;

namespace OOP_LR9_Luchytskyi
{
    class Program
    {
        static void Main(string[] args)
        {
            double x, y, z, res;
            string range;
            while (true)
            {
                Console.WriteLine("X = 0 to exit");
                Console.Write("Write X please: ");
                x = Convert.ToDouble(Console.ReadLine());
                if (x == 0)
                    break;
                Console.Write("Write Y please: ");
                y = Convert.ToDouble(Console.ReadLine());
                Console.Write("Write Z please: ");
                z = Convert.ToDouble(Console.ReadLine());

                res = Math.Log10(y + Math.Sqrt(y + z * z)) * z + y;
                Console.WriteLine("\nResult: {0:0.000}", res);

                range = "";
                if (x < -10)
                    range = "less -10";
                if (x > -10 && x < -1)
                    range = "less -1";
                if (x > 1 && x < 10)
                    range = "more 1";
                if (x > 10)
                    range = "more 10";

                Console.WriteLine("\nX range: " + range);

                if (res >= 0)
                    range = "positive";
                else
                    range = "negative";

                Console.WriteLine("Result range: " + range + "\n");
            }

            Console.WriteLine("\nPress any button to exit");
            Console.ReadKey();
        }
    }
}
