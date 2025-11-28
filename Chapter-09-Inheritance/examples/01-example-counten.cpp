#include <iostream>
using namespace std;

// Base Class
class Counter
{
protected: // NOTE: protected, not private
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
    void show() const
    {
        cout << "Count: " << count << endl;
    }

    // Increment
    Counter operator++()
    {
        return Counter(++count);
    }

    int get_count_val() const { return count; }
};

// Derived Class
class CountDn : public Counter
{
public:
    // 1. Constructor (Inherits default from base implicitly, but we define explicit)
    CountDn() : Counter() {}
    CountDn(int c) : Counter(c) {}

    // 2. Destructor
    ~CountDn() {}

    // 3. Setter (Uses base setter)
    void set(int c) { setCount(c); }

    // 4. Getter (Uses base getter)
    void get() { getInput(); }

    // 5. Show (Uses base show)
    void display() { show(); }

    // Decrement operator (New feature)
    Counter operator--()
    {
        return Counter(--count);
    }
};

int main()
{
    CountDn c1; // c1 of class CountDn

    cout << "Initial value:";
    c1.show();

    ++c1;
    ++c1;
    ++c1; // Increment 3 times
    cout << "After ++ x3: ";
    c1.show();

    --c1;
    --c1; // Decrement 2 times
    cout << "After -- x2: ";
    c1.show();

    return 0;
}