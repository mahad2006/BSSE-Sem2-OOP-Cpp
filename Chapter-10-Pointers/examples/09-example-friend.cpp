#include <iostream>
using namespace std;

class Beta; // Forward declaration

class Alpha
{
private:
    int data;

public:
    Alpha() : data(3) {}
    ~Alpha() {}
    void set(int d) { data = d; }
    void get() { cin >> data; }
    void show() { cout << data; }

    friend int friFunc(Alpha, Beta);
};

class Beta
{
private:
    int data;

public:
    Beta() : data(7) {}
    ~Beta() {}
    void set(int d) { data = d; }
    void get() { cin >> data; }
    void show() { cout << data; }

    friend int friFunc(Alpha, Beta);
};

int friFunc(Alpha a, Beta b)
{
    return (a.data + b.data);
}

int main()
{
    Alpha aa;
    Beta bb;

    cout << "Sum: " << friFunc(aa, bb) << endl;
    return 0;
}