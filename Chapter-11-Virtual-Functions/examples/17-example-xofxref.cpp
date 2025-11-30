#include <iostream>
using namespace std;

class Alpha
{
private:
    int data;

public:
    Alpha() : data(0) {}
    Alpha(int d) : data(d) {}

    // Copy Constructor
    Alpha(Alpha &a)
    {
        data = a.data;
        cout << "\nCopy constructor invoked";
    }

    ~Alpha() {}
    void set(int d) { data = d; }
    void get() { cin >> data; }
    void show() { cout << data; }

    void operator=(Alpha &a)
    {
        data = a.data;
        cout << "\nAssignment op invoked";
    }
};

int main()
{
    Alpha a1(37);
    Alpha a2;

    a2 = a1; // Assignment

    Alpha a3(a1); // Copy constructor
    cout << endl;
    return 0;
}