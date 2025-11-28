#include <iostream>
using namespace std;

class A
{
public:
    A() {}
    ~A() {}
    void show() { cout << "Class A\n"; }
    void set() {}
    void get() {}
};

class B
{
public:
    B() {}
    ~B() {}
    void show() { cout << "Class B\n"; }
    void set() {}
    void get() {}
};

class C : public A, public B
{
public:
    C() {}
    ~C() {}
    // Ambiguity resolved by explicitly calling A:: or B:: in main
    void set() {}
    void get() {}
    void show() { cout << "Class C\n"; }
};

int main()
{
    C objC;
    // objC.show(); // Ambiguous if C didn't have its own show
    objC.A::show(); // Explicitly call A
    objC.B::show(); // Explicitly call B
    return 0;
}