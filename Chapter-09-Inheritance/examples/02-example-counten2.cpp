#include <iostream>
using namespace std;

// Base Class
class Counter
{
protected:
    unsigned int count;

public:
    // 1. Constructor
    Counter() : count(0) {}
    Counter(int c) : count(c) {}

    // 2. Destructor
    ~Counter() {}

    // 3. Setter
    void setCount(int c) { count = c; }

    // 4. Getter (using cin)
    void getInput()
    {
        cout << "Enter count: ";
        cin >> count;
    }

    // 5. Show
    void show() const { cout << "Count: " << count << endl; }

    Counter operator++() { return Counter(++count); }
};

// Derived Class
class CountDn : public Counter
{
public:
    // 1. Constructor (Calls base constructor)
    CountDn() : Counter() {}
    CountDn(int c) : Counter(c) {}

    // 2. Destructor
    ~CountDn() {}

    // 3. Setter
    void set(int c) { setCount(c); }

    // 4. Getter
    void get() { getInput(); }

    // 5. Show
    void display() { show(); }

    CountDn operator--() { return CountDn(--count); }
};

int main()
{
    CountDn c1;      // Default ctor
    CountDn c2(100); // 1-arg ctor

    cout << "c1: ";
    c1.show();
    cout << "c2: ";
    c2.show();

    ++c1;
    ++c1;
    ++c1;
    cout << "c1 after ++: ";
    c1.show();

    --c2;
    --c2;
    cout << "c2 after --: ";
    c2.show();

    return 0;
}