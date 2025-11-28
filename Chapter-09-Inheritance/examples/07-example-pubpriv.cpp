#include <iostream>
using namespace std;

class A
{
private:
    int privA;

protected:
    int protA;

public:
    int pubA;

    A() : privA(1), protA(2), pubA(3) {}
    ~A() {}

    // Required functions for format
    void setA(int p, int pr, int pu)
    {
        privA = p;
        protA = pr;
        pubA = pu;
    }
    void getA()
    {
        cout << "Enter A val: ";
        cin >> pubA;
    }
    void show() { cout << privA << protA << pubA << endl; }
};

class B : public A
{
public:
    void func()
    {
        int a;
        // a = privA; // Error: not accessible
        a = protA; // OK
        a = pubA;  // OK
    }
};

class C : private A
{
public:
    void func()
    {
        int a;
        // a = privA; // Error: not accessible
        a = protA; // OK
        a = pubA;  // OK
    }
};

int main()
{
    int a;
    B objB;
    // a = objB.privA; // Error
    // a = objB.protA; // Error
    a = objB.pubA; // OK (Public inheritance)

    C objC;
    // a = objC.privA; // Error
    // a = objC.protA; // Error
    // a = objC.pubA; // Error (Private inheritance makes public members private)

    cout << "Compilation check for Access Specifiers completed." << endl;
    return 0;
}