#include <iostream>

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
    void print_sqrt();
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

void Krest::print_sqrt()
{
    std::cout << "A: " << a << "\nB: " << b << "\nArea: " << getSpace() << std::endl;
}

int main()
{
    void (Krest:: * pf)();
    pf = &Krest::print_sqrt;
    std::cout << &pf << std::endl;

    Krest *testKrest = new Krest(3, 4);
    std::cout << testKrest << std::endl;
    (testKrest->*pf)();

    testKrest->~Krest();

    std::getchar();
}
