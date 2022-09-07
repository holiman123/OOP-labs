using System;

namespace OOP_LR_16
{
    class Program
    {
        delegate double function(double x);

        static double getIntegral(function func, double a, double b, double interval)
        {
            double sum = 0;
            if (a == 0)
                a += interval;

            for (double i = a; i < b; i += interval)
            {
                sum += func(i) * interval + (func(i + interval) - func(i)) * interval / 2;
            }
            return sum;
        }

        static double func1(double x)
        {
            return 1 / (x * x * x);
        }
        static double func2(double x)
        {
            return 1 / Math.Sqrt(x);
        }
        static double func3(double x)
        {
            return Math.Pow(Math.E, -x) + 1;
        }

        static void myHandler(ConsoleKeyInfo k)
        {
            if (k.KeyChar == 'l')
                Console.WriteLine("Luchytskyi");
        }

        static void Main(string[] args)
        {
            MyClassWithEvent evt = new MyClassWithEvent();

            evt.keyPressed += new MyEventHandler(myHandler);
            evt.fire();

            Console.WriteLine("Integral (1 to 2) of func1: " + getIntegral(func1, 1, 2, 0.00005));
            Console.WriteLine("Integral (1 to 2) of func2: " + getIntegral(func2, 1, 2, 0.00005));
            Console.WriteLine("Integral (1 to 2) of func3: " + getIntegral(func3, 1, 2, 0.00005));

            Console.ReadKey();
        }
    }

    delegate void MyEventHandler(ConsoleKeyInfo k);

    class MyClassWithEvent
    {
        public event MyEventHandler keyPressed;

        public void fire()
        {
            if (keyPressed != null)
            {
                ConsoleKeyInfo k = Console.ReadKey(true);
                keyPressed(k);
            }
        }
    }
}
