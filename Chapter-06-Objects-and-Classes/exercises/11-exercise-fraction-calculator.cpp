// 11-exercise-fraction-calculator.cpp
#include <iostream>
#include <cmath> // for abs
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
    void setFrac(int n, int d)
    {
        num = n;
        den = d;
    }

    // 4. Getter
    void getFrac()
    {
        char dummy;
        cout << "Enter fraction (n/d): ";
        cin >> num >> dummy >> den;
    }

    // 5. Show
    void show() const { cout << num << "/" << den; }

    // Math operations
    void add(Fraction f1, Fraction f2)
    {
        num = f1.num * f2.den + f1.den * f2.num;
        den = f1.den * f2.den;
        lowterms();
    }
    void sub(Fraction f1, Fraction f2)
    {
        num = f1.num * f2.den - f1.den * f2.num;
        den = f1.den * f2.den;
        lowterms();
    }
    void mul(Fraction f1, Fraction f2)
    {
        num = f1.num * f2.num;
        den = f1.den * f2.den;
        lowterms();
    }
    void div(Fraction f1, Fraction f2)
    {
        num = f1.num * f2.den;
        den = f1.den * f2.num;
        lowterms();
    }

    // Simplify fraction
    void lowterms()
    {
        long tnum, tden, temp, gcd;
        tnum = abs(num);
        tden = abs(den);
        if (tden == 0)
        {
            cout << "Error";
            return;
        }
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
    Fraction f1, f2, result;
    char op;

    do
    {
        f1.getFrac();
        cout << "Enter operator (+, -, *, /): ";
        cin >> op;
        f2.getFrac();

        switch (op)
        {
        case '+':
            result.add(f1, f2);
            break;
        case '-':
            result.sub(f1, f2);
            break;
        case '*':
            result.mul(f1, f2);
            break;
        case '/':
            result.div(f1, f2);
            break;
        }
        cout << "Result: ";
        result.show();
        cout << endl;
        cout << "Do another (y/n)? ";
        cin >> op;
    } while (op == 'y');

    return 0;
}