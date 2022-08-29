#include <iostream>
#include <stack>
using namespace std;

class MyClass
{
public:
    float *myArray;
    int n;
    MyClass(int i);
    ~MyClass();
};

MyClass::MyClass(int i)
{
    n = i;
    myArray = new float[i];
    for (; i > 0; i--)
    {
        if (i % 2 == 0)
            myArray[i] = i;
        else
            myArray[i] = i - 1.9;
    }
}

MyClass::~MyClass()
{
    cout << "Called destructor. Deleted " << &myArray << endl;
    delete myArray;
}

void myFunction(MyClass &obj)
{
    stack<float> stack;
    for (int i = 0; i < obj.n; i++)
    {
        stack.push(obj.myArray[i+1]);
    }

    for (int i = 0; i < obj.n; i++)
    {
        obj.myArray[i+1] = stack.top();
        stack.pop();
    }
}

void printArray(float *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i+1];
    }
    cout << endl;
}

int main()
{
    MyClass classEx (14);
    printArray(classEx.myArray, classEx.n);

    myFunction(classEx);
    printArray(classEx.myArray, classEx.n);

    getchar();
}
