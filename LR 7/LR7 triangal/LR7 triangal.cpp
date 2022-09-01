#include <iostream>
#include <string>
using namespace std;

#define PI 3.14159265

class Triangle
{
    double a, b, angle;

public:
    virtual string getSpacePerimeter()// = 0;
        // comment from here to make abstract
    {
        return "Space: типо посчиатл\nPerimeter: типо тоже посчитал";
    }
    Triangle(double a, double b, double angle)
    {
        setA(a);
        setB(b);
        setAngle(angle);

        cout << "New random triangle was send by God to us!" << endl;
    }
    Triangle()
    {
        setA(0);
        setB(0);
        setAngle(0);

        cout << "New void triangle was created!" << endl;
    }
    // to her
    ~Triangle() { cout << "Destroyed " << this << endl; }

    double getA() { return a; }
    double getB() { return b; }
    double getAngle() { return angle; }

    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }
    void setAngle(double angle) { this->angle = angle; }
};

class Equilateral : public Triangle
{
public:
    Equilateral(double side)
    {
        setA(side);
        setB(side);
        setAngle(60);

        cout << "New equilateral triangle appeared from nowhere!" << endl;
    }

    string getSpacePerimeter()
    {        
        return "Space: " + to_string((getA() * getA() * sqrt(3) / 4)) + "\nPerimetr: " + to_string(getA() * 3);
    }
};

class Isosceles : public Triangle
{
public:
    Isosceles(double side, double angle)
    {
        setA(side);
        setB(side);
        setAngle(angle);

        cout << "New isosceles triangle was born!" << endl;
    }

    string getSpacePerimeter()
    {
        return "Space: " + to_string(getA() * getA() * sin(getAngle() * PI / 180)) + "\nPerimetr: " + to_string(sqrt((2 * getA() * getA()) * (1 - cos(getAngle()))) + (2 * getA()));
    }
};

class Rectangular : public Triangle
{
public:
    Rectangular(double cathetus, double hypotenuse)
    {
        setA(cathetus);
        setB(hypotenuse);

        cout << "New rectangular triangle sees his first light!" << endl;
    }

    string getSpacePerimeter()
    {
        double tempB = sqrt(getB()*getB() - getA()*getA());
        return "Space: " + to_string(getA() * tempB / 2) + "\nPerimeter: " + to_string(getA() + getB() + tempB);
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Triangle* triangels[3];
    triangels[0] = new Equilateral(2);
    triangels[1] = new Isosceles(2, 60);
    triangels[2] = new Rectangular(2, 3);
    triangels[3] = new Triangle(2, 3, 60);

    cout << endl;

    cout << triangels[0]->getSpacePerimeter() << endl << endl;
    cout << triangels[1]->getSpacePerimeter() << endl << endl;
    cout << triangels[2]->getSpacePerimeter() << endl << endl;
    cout << triangels[3]->getSpacePerimeter() << endl;

    getchar();
}
