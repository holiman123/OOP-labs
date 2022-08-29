#include <iostream>
using namespace std;

class Krest
{
private:
    double a, b;
public:
    Krest();
    Krest(double, double);
    ~Krest();
    double getA();
    double getB();
    void setA(double);
    void setB(double);
    double getSpace();

    friend ostream& operator << (ostream& t, Krest& k)
    {
        return t << "a: " << k.getA() << " b: " << k.getB() << " space: " << k.getSpace();
    }
    Krest operator + (Krest& k)
    {
        return Krest(getA() + k.getA(), getB() + k.getB());
    }
    Krest operator ++ ()
    {
        setA(getA() + 1);
        setB(getB() + 1);
        return *this;
    }
    Krest operator ++ (int notused)
    {
        Krest temp = *this;
        setA(getA() + 1);
        setB(getB() + 1);
        return temp;
    }
    Krest operator -- ()
    {
        setA(getA() - 1);
        setB(getB() - 1);
        return *this;
    }
    Krest operator -- (int notused)
    {
        Krest temp = *this;
        setA(getA() - 1);
        setB(getB() - 1);
        return temp;
    }
};

Krest::Krest()
{
    this->a = 0;
    this->b = 0;
    std::cout << "Constructer without params called: " << this << std::endl;
}
Krest::Krest(double a, double b)
{
    this->a = a;
    this->b = b;
    std::cout << "Constructer with params a: " << a << " b: " << b << " called by: " << this << std::endl;
}
Krest::~Krest()
{
    std::cout << "destructer called for " << this << std::endl;
}

double Krest::getA()
{
    return this->a;
}
double Krest::getB()
{
    return this->b;
}

void Krest::setA(double a)
{
    this->a = a;
}
void Krest::setB(double b)
{
    this->b = b;
}

double Krest::getSpace()
{
    return (4 * a * b) + (b * b);
}

int main()
{
    Krest k1 = Krest(1, 1);
    k1++;
    Krest k2 = Krest(1, 2) + k1;
    cout << k1 << endl;
    cout << k2 << endl;

    std::getchar();
}
