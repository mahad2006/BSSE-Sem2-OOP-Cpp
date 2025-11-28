#include <iostream>
#include <cmath> // for modf
using namespace std;

class bMoney
{
private:
    long double money;

public:
    bMoney() : money(0.0) {}
    bMoney(long double m) : money(m) {}
    ~bMoney() {}
    void set(long double m) { money = m; }
    void get()
    {
        cout << "Enter amount: ";
        cin >> money;
    }
    void show() { cout << "$" << money; }

    friend bMoney round(bMoney m);
};

bMoney round(bMoney m)
{
    long double intPart, fractPart;
    fractPart = modf(m.money, &intPart);
    if (fractPart >= 0.50)
        intPart += 1.0;
    return bMoney(intPart);
}

int main()
{
    bMoney m1, m2;
    m1.get();

    m2 = round(m1);
    cout << "Rounded: ";
    m2.show();
    cout << endl;

    return 0;
}