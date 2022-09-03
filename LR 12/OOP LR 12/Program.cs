using System;

namespace OOP_LR_12
{

    class Triangle
    {
        public double a { get; set; }
        public double b { get; set; }
        public double c { get; set; }

        public Triangle()
        {
            a = 0;
            b = 0;
            c = 0;
        }
        public Triangle(double a, double b, double c)
        {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        public double getSpace()
        {
            double p = (a + b + c) / 2;
            return Math.Sqrt(p * (p-a) * (p-b) * (p-c));
        }
        public static bool operator ==(Triangle op1, Triangle op2)
        {
            return op1.a == op2.a && op1.b == op2.b && op1.c == op2.c;
        }
        public static bool operator !=(Triangle op1, Triangle op2)
        {
            return op1.a != op2.a || op1.b != op2.b || op1.c != op2.c;
        }

        public override string ToString()
        { 
            return string.Format("a: {0:0.00}\nb: {1:0.00}\nc: {2:0.00}\nSpace: {3:0.00}", a, b, c, getSpace()); 
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Triangle t1 = new Triangle(1,1,1);
            Console.WriteLine(t1.ToString());

            Triangle t2 = new Triangle(2, 2, 2);
            Console.WriteLine("\n" + t2.ToString());

            Console.WriteLine("\nIs t1 == t2: " + (t1 == t2));

            t2.a = 1;
            t2.b = 1;
            t2.c = 1;
            Console.WriteLine("\n" + t2.ToString());
            Console.WriteLine("\nIs t1 == t2: " + (t1 == t2));

            Console.ReadKey();
        }
    }
}
