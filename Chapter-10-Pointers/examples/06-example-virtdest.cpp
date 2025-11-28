#include <iostream>
using namespace std;

class Base
{
public:
    Base() {}
    // Virtual Destructor ensures derived destructor is called
    virtual ~Base() { cout << "Base destroyed\n"; }
    void set() {}
    void get() {}
    void show() {}
};

class Derv : public Base
{
public:
    Derv() {}
    ~Derv() { cout << "Derv destroyed\n"; }
    void set() {}
    void get() {}
    void show() {}
};

int main()
{
    Base *pBase = new Derv;
    delete pBase; // Should call Derv destructor then Base destructor
    return 0;
}