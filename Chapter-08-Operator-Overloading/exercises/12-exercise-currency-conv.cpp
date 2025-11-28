#include <iostream>
using namespace std;

// Forward declaration needed for conversions
class Sterling;

class bMoney
{
private:
    long double money;

public:
    bMoney() : money(0.0) {}
    bMoney(long double m) : money(m) {}
    ~bMoney() {}
    void setMoney(long double m) { money = m; }
    void getInput()
    {
        cout << "Enter Dollars: ";
        cin >> money;
    }
    void show() const { cout << "$" << money; }

    // Explicit conversion operator
    operator double() { return money; }
};

class Sterling
{
private:
    long pounds;
    int shillings, pence;

public:
    Sterling() : pounds(0), shillings(0), pence(0) {}
    Sterling(double decPounds)
    {
        pounds = (long)decPounds;
        double frac = decPounds - pounds;
        double totPence = frac * 240;
        shillings = (int)totPence / 12;
        pence = (int)totPence % 12;
    }
    // Conversion from bMoney (1 pound = $50)
    Sterling(bMoney bm)
    {
        double usd = double(bm);
        double sterlingVal = usd / 50.0;
        *this = Sterling(sterlingVal); // reuse double ctor
    }

    ~Sterling() {}

    void setSterling(long p, int s, int pe)
    {
        pounds = p;
        shillings = s;
        pence = pe;
    }

    void getInput()
    {
        cout << "Enter Pounds Shillings Pence: ";
        cin >> pounds >> shillings >> pence;
    }

    void show() const
    {
        cout << "L" << pounds << "." << shillings << "." << pence;
    }

    // Conversion to bMoney
    operator bMoney()
    {
        double decimalPounds = pounds + (shillings * 12 + pence) / 240.0;
        return bMoney(decimalPounds * 50.0);
    }
};

int main()
{
    bMoney bm;
    bm.getInput();

    Sterling st = bm; // Convert Dollars to Sterling
    cout << "In Sterling: ";
    st.show();
    cout << endl;

    Sterling st2;
    st2.getInput();

    bMoney bm2 = st2; // Convert Sterling to Dollars
    cout << "In Dollars: ";
    bm2.show();
    cout << endl;

    return 0;
}