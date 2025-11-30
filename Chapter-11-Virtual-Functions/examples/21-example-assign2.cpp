#include <iostream>
using namespace std;

class Alpha
{
private:
    int data;

public:
    Alpha() : data(0) {}
    Alpha(int d) : data(d) {}
    ~Alpha() {}
    void set(int d) { data = d; }
    void get() { cin >> data; }
    void show() { cout << data; }

    Alpha &operator=(Alpha &a)
    {
        data = a.data;
        cout << "\nAssignment op invoked";
        return *this;
    }
};

int main()
{
    Alpha a1(37);
    Alpha a2, a3;

    a3 = a2 = a1;

    cout << "\na2=";
    a2.show();
    cout << "\na3=";
    a3.show();
    cout << endl;
    return 0;
}