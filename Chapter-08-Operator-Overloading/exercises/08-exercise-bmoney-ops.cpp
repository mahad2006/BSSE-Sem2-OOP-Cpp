#include <iostream>
#include <iomanip>
using namespace std;

class bMoney
{
private:
    long double money;

public:
    // 1. Constructor
    bMoney() : money(0.0) {}
    explicit bMoney(long double m) : money(m) {}

    // 2. Destructor
    ~bMoney() {}

    // 3. Setter
    void setMoney(long double m) { money = m; }

    // 4. Getter (using cin)
    void getMoneyInput()
    {
        cout << "Enter amount: ";
        cin >> money;
    }

    // 5. Show
    void show() const
    {
        cout << fixed << setprecision(2) << "$" << money;
    }

    bMoney operator+(bMoney m2) { return bMoney(money + m2.money); }
    bMoney operator-(bMoney m2) { return bMoney(money - m2.money); }
    bMoney operator*(long double factor) { return bMoney(money * factor); }
    long double operator/(bMoney m2) { return money / m2.money; }
    bMoney operator/(long double div) { return bMoney(money / div); }
};

int main()
{
    bMoney m1, m2, m3;

    m1.getMoneyInput();
    m2.getMoneyInput();

    m3 = m1 + m2;
    cout << "Sum: ";
    m3.show();
    cout << endl;

    m3 = m1 * 2.0;
    cout << "M1 * 2: ";
    m3.show();
    cout << endl;

    long double ratio = m1 / m2;
    cout << "Ratio M1/M2: " << ratio << endl;

    return 0;
}