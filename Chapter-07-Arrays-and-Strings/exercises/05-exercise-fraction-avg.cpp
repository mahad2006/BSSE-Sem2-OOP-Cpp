#include <iostream>
using namespace std;

class Fraction
{
private:
    int num, den;

public:
    // 1. Constructor
    Fraction() : num(0), den(1) {}
    Fraction(int n, int d) : num(n), den(d) {}

    // 2. Destructor
    ~Fraction() {}

    // 3. Setter
    void setFract(int n, int d)
    {
        num = n;
        den = d;
    }

    // 4. Getter (using cin)
    void getFract()
    {
        char dummy;
        cout << "Enter fraction (n/d): ";
        cin >> num >> dummy >> den;
    }

    // 5. Show
    void showFract() const { cout << num << "/" << den; }

    // Math Logic
    Fraction add(Fraction f2)
    {
        int n = num * f2.den + f2.num * den;
        int d = den * f2.den;
        return Fraction(n, d);
    }

    Fraction div(int divisor)
    {
        return Fraction(num, den * divisor);
    }

    // Simplification (gcd logic inside)
    void lowterms()
    {
        long tnum, tden, temp, gcd;
        tnum = labs(num);
        tden = labs(den);
        if (tden == 0)
        {
            cout << "Illegal fraction: division by 0";
            return;
        }
        else if (tnum == 0)
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
    Fraction fracs[100];
    Fraction sum(0, 1), avg;
    int n = 0;
    char ch;

    do
    {
        fracs[n++].getFract();
        cout << "Another (y/n)? ";
        cin >> ch;
    } while (ch == 'y' && n < 100);

    for (int i = 0; i < n; i++)
    {
        sum = sum.add(fracs[i]);
    }

    avg = sum.div(n);
    avg.lowterms();

    cout << "Average is: ";
    avg.showFract();
    cout << endl;

    return 0;
}