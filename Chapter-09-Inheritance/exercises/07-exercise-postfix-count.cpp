#include <iostream>
using namespace std;

class Counter
{
protected:
    unsigned int count;

public:
    Counter() : count(0) {}
    Counter(int c) : count(c) {}
    ~Counter() {}
    void setCount(int c) { count = c; }
    void getCount()
    {
        cout << "Enter count: ";
        cin >> count;
    }
    void show() const { cout << "Count: " << count << endl; }
    Counter operator++() { return Counter(++count); }
    Counter operator++(int) { return Counter(count++); }
};

class CountDn : public Counter
{
public:
    // 1. Constructor
    CountDn() : Counter() {}
    CountDn(int c) : Counter(c) {}

    // 2. Destructor
    ~CountDn() {}

    // 3. Setter
    void set(int c) { setCount(c); }

    // 4. Getter
    void get() { getCount(); }

    // 5. Show
    void display() { show(); }

    // Prefix --
    CountDn operator--()
    {
        return CountDn(--count);
    }

    // Postfix --
    CountDn operator--(int)
    {
        return CountDn(count--);
    }
};

int main()
{
    CountDn c1(10);

    cout << "Start: ";
    c1.show();

    --c1; // Prefix
    cout << "Prefix --: ";
    c1.show();

    c1--; // Postfix
    cout << "Postfix --: ";
    c1.show();

    return 0;
}