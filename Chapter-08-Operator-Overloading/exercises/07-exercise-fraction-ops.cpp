#include <iostream>
using namespace std;

class Fraction
{
private:
    int num, den;

public:
    // 1. Constructor
    Fraction() : num(0), den(1) {}
    Fraction(int n, int d) : num(n), den(d)
    {
        if (den == 0)
        {
            cout << "Error: Denom 0";
            den = 1;
        }
    }

    // 2. Destructor
    ~Fraction() {}

    // 3. Setter
    void setFraction(int n, int d)
    {
        num = n;
        den = d;
    }

    // 4. Getter (using cin)
    void getFraction()
    {
        char slash;
        cout << "Enter fraction (n/d): ";
        cin >> num >> slash >> den;
    }

    // 5. Show
    void show() const { cout << num << "/" << den; }

    // Operators
    Fraction operator+(Fraction f)
    {
        return Fraction(num * f.den + f.num * den, den * f.den);
    }
    Fraction operator-(Fraction f)
    {
        return Fraction(num * f.den - f.num * den, den * f.den);
    }
    Fraction operator*(Fraction f)
    {
        return Fraction(num * f.num, den * f.den);
    }
    Fraction operator/(Fraction f)
    {
        return Fraction(num * f.den, den * f.num);
    }
    bool operator==(Fraction f)
    {
        return (num * f.den == f.num * den);
    }
    bool operator!=(Fraction f)
    {
        return !(*this == f);
    }
};

int main()
{
    Fraction f1, f2, f3;
    f1.getFraction();
    f2.getFraction();

    f3 = f1 + f2;
    cout << "Sum: ";
    f3.show();
    cout << endl;
    f3 = f1 * f2;
    cout << "Prod: ";
    f3.show();
    cout << endl;

    if (f1 == f2)
        cout << "Fractions are equal." << endl;
    else
        cout << "Fractions are not equal." << endl;

    return 0;
}