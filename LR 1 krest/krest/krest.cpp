#include <iostream>

class Krest
{
private:
    double a, b, space;
public:
    Krest();
    Krest(double, double);
    ~Krest();
    double GetA();
    double GetB();
    void SetA(double);
    void SetB(double);
    double GetSpace();
    void print_sqrt();
};

Krest::Krest()
{
    a = 0;
    b = 0;
    space = 0;
    std::cout << "Constructer without params called: " << this << std::endl;
}

Krest::Krest(double a, double b)
{
    this->a = a;
    this->b = b;
    space = NULL;
    GetSpace();
    std::cout << "Constructer with params a: " << a << " b: " << b << " called by: " << this << std::endl;
}

Krest::~Krest()
{
    std::cout << "destructer called for " << this << std::endl;
}

double Krest::GetA()
{
    return this->a;
}

double Krest::GetB()
{
    return this->b;
}

void Krest::SetA(double a)
{
    this->a = a;
}
void Krest::SetB(double b)
{
    this->b = b;
}

double Krest::GetSpace()
{
    if (space == 0)
        space = (4 * a * b) + (b * b);
    return space;
}

void Krest::print_sqrt()
{
    std::cout << "A: " << a << "\nB: " << b << "\nArea: " << space << std::endl;
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
