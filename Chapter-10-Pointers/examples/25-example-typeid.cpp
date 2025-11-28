#include <iostream>
#include <typeinfo>
using namespace std;

class Base
{
    virtual void virtFunc() {}

public:
    Base() {}
    virtual ~Base() {}
    void set() {}
    void get() {}
    void show() {}
};
class Derv1 : public Base
{
};
class Derv2 : public Base
{
};

void displayName(Base *pB)
{
    cout << "pointer to object of " << typeid(*pB).name() << endl;
}

int main()
{
    Base *pBase = new Derv1;
    displayName(pBase);

    pBase = new Derv2;
    displayName(pBase);

    return 0;
}