#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Fraction
{
private:
    int num, den;

public:
    // 1. Constructor
    Fraction() : num(0), den(1) {}
    Fraction(int n, int d) : num(n), den(d) { lowterms(); }

    // 2. Destructor
    ~Fraction() {}

    // 3. Setter
    void setFrac(int n, int d)
    {
        num = n;
        den = d;
        lowterms();
    }

    // 4. Getter
    void getFrac() { /* Not used in this specific logic */ }

    // 5. Show
    void show() const { cout << num << "/" << den; }

    void mul(Fraction f1, Fraction f2)
    {
        num = f1.num * f2.num;
        den = f1.den * f2.den;
        lowterms();
    }

    void lowterms()
    {
        long tnum = abs(num), tden = abs(den), temp, gcd;
        if (tden == 0)
            return;
        if (tnum == 0)
        {
            num = 0;
            den = 1;
            return;
        }
        while (tnum != 0)
        {
            if (tnum < tden)
            {
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum = tnum - tden;
        }
        gcd = tden;
        num = num / gcd;
        den = den / gcd;
    }
};

int main()
{
    int d;
    cout << "Enter denominator: ";
    cin >> d;

    cout << setw(6) << " ";
    // Header row
    for (int i = 1; i < d; i++)
    {
        Fraction f(i, d);
        cout << setw(6);
        f.show();
    }
    cout << endl;

    // Table rows
    for (int i = 1; i < d; i++)
    {
        Fraction f_row(i, d);
        cout << setw(6);
        f_row.show(); // Row header

        for (int j = 1; j < d; j++)
        {
            Fraction f_col(j, d);
            Fraction result;
            result.mul(f_row, f_col);
            cout << setw(6);
            result.show();
        }
        cout << endl;
    }
    return 0;
}