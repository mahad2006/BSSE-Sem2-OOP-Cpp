#include <iostream>
using namespace std;

class Base
{
public:
    Base() {}
    virtual ~Base() {} // Virtual destructor is good practice
    void set() {}
    void get() {}

    // Virtual Function
    virtual void show() { cout << "Base\n"; }
};

class Derv1 : public Base
{
public:
    Derv1() {}
    ~Derv1() {}
    void set() {}
    void get() {}
    void show() { cout << "Derv1\n"; }
};

class Derv2 : public Base
{
public:
    Derv2() {}
    ~Derv2() {}
    void set() {}
    void get() {}
    void show() { cout << "Derv2\n"; }
};

int main()
{
    Derv1 dv1;
    Derv2 dv2;
    Base *ptr;

    ptr = &dv1;
    ptr->show(); // Calls Derv1::show()

    ptr = &dv2;
    ptr->show(); // Calls Derv2::show()

    return 0;
}