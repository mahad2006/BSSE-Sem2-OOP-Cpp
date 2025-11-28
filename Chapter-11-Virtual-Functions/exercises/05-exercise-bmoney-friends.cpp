#include <iostream>
using namespace std;

class bMoney
{
private:
    long double money;

public:
    bMoney() : money(0.0) {}
    explicit bMoney(long double m) : money(m) {}
    ~bMoney() {}
    void set(long double m) { money = m; }
    void get()
    {
        cout << "Enter amount: ";
        cin >> money;
    }
    void show() { cout << "$" << money; }

    // Friend functions
    friend bMoney operator*(long double n, bMoney m);
    friend bMoney operator/(long double n, bMoney m); // Generally meaningless financially but requested
    friend bMoney operator+(bMoney m1, bMoney m2);
};

bMoney operator+(bMoney m1, bMoney m2)
{
    return bMoney(m1.money + m2.money);
}

bMoney operator*(long double n, bMoney m)
{
    return bMoney(n * m.money);
}

bMoney operator/(long double n, bMoney m)
{
    return bMoney(n / m.money);
}

int main()
{
    bMoney m1, m2;
    m1.get();

    m2 = 2.0 * m1; // Friend *
    cout << "Double: ";
    m2.show();
    cout << endl;

    return 0;
}