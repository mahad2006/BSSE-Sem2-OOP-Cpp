#include <iostream>
using namespace std;

class Base
{
public:
    // 1. Constructor
    Base() {}
    // 2. Destructor
    ~Base() {}
    // 3. Setter
    void set() {}
    // 4. Getter
    void get() {}
    // 5. Show (Normal function)
    void show() { cout << "Base\n"; }
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
    ptr->show(); // Calls Base::show()

    ptr = &dv2;
    ptr->show(); // Calls Base::show()

    return 0;
}