#include <iostream>
using namespace std;

class Alpha
{
private:
    int data1;

public:
    Alpha() : data1(99) {}
    ~Alpha() {}
    void set(int d) { data1 = d; }
    void get() { cin >> data1; }
    void show() { cout << data1; }

    friend class Beta; // Beta is a friend class
};

class Beta
{
public:
    Beta() {}
    ~Beta() {}

    void func1(Alpha a) { cout << "\ndata1=" << a.data1; }
    void func2(Alpha a) { cout << "\ndata1=" << a.data1; }

    void set() {}
    void get() {}
    void show() {}
};

int main()
{
    Alpha a;
    Beta b;
    b.func1(a);
    b.func2(a);
    cout << endl;
    return 0;
}