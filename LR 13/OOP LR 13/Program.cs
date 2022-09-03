using System;

namespace OOP_LR_13
{

    abstract class Transport
    {
        public int amountOfPeople { get; set; }
        public int serNumber { get; set; }
        public double velocity { get; set; }

        public abstract double getRoutePrice(double route);
        public Transport(int serNumber, double velocity, int amountOfPeople)
        {
            this.serNumber = serNumber;
            this.velocity = velocity;
            this.amountOfPeople = amountOfPeople;

            Console.WriteLine("Abstract transport created with serial number: " + this.serNumber);
        }
        public override bool Equals(object obj)
        {
            if (!(obj is Transport))
                return false;
            return this.serNumber == ((Transport)obj).serNumber;
        }
        public static bool operator ==(Transport op1, Transport op2)
        {
            return op1.Equals(op2);
        }
        public static bool operator !=(Transport op1, Transport op2)
        {
            return !op1.Equals(op2);
        }
    }

    class Airplane : Transport
    {
        public double fuelConsumption { get; set; }
        public static double fuelPrice { get; set; }

        public Airplane(int serNumber, double velocity, int amountOfPeople, double fuelConsumption)
            : base(serNumber, velocity, amountOfPeople)
        {
            this.fuelConsumption = fuelConsumption;

            Console.WriteLine("New airplane created with serial number: " + this.serNumber);
        }
        public override double getRoutePrice(double route)
        {
            return (route / fuelConsumption) * fuelPrice * 1.3;
        }
    }
    class Car : Transport
    {
        public double fuelConsumption { get; set; }
        public static double fuelPrice { get; set; }

        public Car(int serNumber, double velocity, int amountOfPeople, double fuelConsumption)
            : base(serNumber, velocity, amountOfPeople)
        {
            this.fuelConsumption = fuelConsumption;

            Console.WriteLine("New car created with serial number: " + this.serNumber);
        }
        public override double getRoutePrice(double route)
        {
            return (route / fuelConsumption) * fuelPrice * 1.05;
        }
    }
    class Train : Transport
    {
        public double fuelConsumption { get; set; }
        public static double fuelPrice { get; set; }

        public Train(int serNumber, double velocity, int amountOfPeople, double fuelConsumption)
            : base(serNumber, velocity, amountOfPeople)
        {
            this.fuelConsumption = fuelConsumption;

            Console.WriteLine("New car created with serial number: " + this.serNumber);
        }
        public override double getRoutePrice(double route)
        {
            return (route / fuelConsumption) * fuelPrice * 1.2;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            double route1 = 10000; // km

            Airplane.fuelPrice = 100;
            Car.fuelPrice = 10;
            Train.fuelPrice = 50;

            Transport[] trans = new Transport[3];
            trans[0] = new Airplane(11, 800, 200, 150);
            trans[1] = new Car(21, 80, 5, 10);
            trans[2] = new Train(31, 150, 1000, 100);

            Console.WriteLine("Airplane cost: " + trans[0].getRoutePrice(route1));
            Console.WriteLine("Car cost: " + trans[1].getRoutePrice(route1));
            Console.WriteLine("Train cost: " + trans[2].getRoutePrice(route1));

            Console.ReadKey();
        }
    }
}
