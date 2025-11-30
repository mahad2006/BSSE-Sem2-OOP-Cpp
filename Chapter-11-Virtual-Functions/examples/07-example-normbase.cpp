#include <iostream>
using namespace std;

// Grandparent
class Parent
{
protected:
    int basedata;

public:
    Parent() : basedata(0) {}
    ~Parent() {}
    void set(int b) { basedata = b; }
    void get() { cin >> basedata; }
    void show() { cout << basedata; }
};

// Parent 1
class Child1 : public Parent
{
public:
    Child1() {}
    ~Child1() {}
};

// Parent 2
class Child2 : public Parent
{
public:
    Child2() {}
    ~Child2() {}
};

// Derived
class Grandchild : public Child1, public Child2
{
public:
    Grandchild() {}
    ~Grandchild() {}

    int getData()
    {
        // return basedata; // ERROR: Ambiguous which basedata
        return Child1::basedata; // Must verify which one
    }

    void set() {}
    void get() {}
    void show() {}
};

int main()
{
    Grandchild gc;
    // gc.getData(); // Needs explicit resolution
    cout << "Ambiguity demonstration (code shows commented error)." << endl;
    return 0;
}