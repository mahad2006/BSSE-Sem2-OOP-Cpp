#include <iostream>
#include <typeinfo>
using namespace std;

class Base
{
public:
    virtual void virtFunc() {}
    // Required filler
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

bool isDerv1(Base *pUnknown)
{
    if (dynamic_cast<Derv1 *>(pUnknown))
        return true;
    else
        return false;
}

int main()
{
    Derv1 *d1 = new Derv1;
    Derv2 *d2 = new Derv2;

    if (isDerv1(d1))
        cout << "d1 is Derv1\n";
    else
        cout << "d1 is NOT Derv1\n";

    if (isDerv1(d2))
        cout << "d2 is Derv1\n";
    else
        cout << "d2 is NOT Derv1\n";

    return 0;
}