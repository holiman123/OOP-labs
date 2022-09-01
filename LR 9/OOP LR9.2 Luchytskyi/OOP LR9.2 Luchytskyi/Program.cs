using System;

namespace OOP_LR9._2_Luchytskyi
{
    class Program
    {
        static void Main(string[] args)
        {
            double priceX, priceY, p;
            Console.Write("Write first price: ");
            priceX = Convert.ToDouble(Console.ReadLine());
            Console.Write("Write second price: ");
            priceY = Convert.ToDouble(Console.ReadLine());

            Console.Write("Write percent to implement: ");
            p = Convert.ToDouble(Console.ReadLine()) / 100 + 1;

            Console.WriteLine("\nNew firts price: " + priceX * p);
            Console.WriteLine("New second price: " + priceY * p + "\n");

            Console.WriteLine("Press any button to exit");
            Console.ReadKey();
        }
    }
}
