// 09-exercise-fraction-class.cpp
#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    // 1. Constructor
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int n, int d) : numerator(n), denominator(d) {}

    // 2. Destructor
    ~Fraction() {}

    // 3. Setter
    void setFraction(int n, int d)
    {
        numerator = n;
        denominator = d;
    }

    // 4. Getter (using cin)
    void getFraction()
    {
        char dummy;
        cout << "Enter fraction (num/den): ";
        cin >> numerator >> dummy >> denominator;
    }

    // 5. Show
    void show() const
    {
        cout << numerator << "/" << denominator;
    }

    // Add function
    void add(Fraction f1, Fraction f2)
    {
        numerator = (f1.numerator * f2.denominator) + (f1.denominator * f2.numerator);
        denominator = f1.denominator * f2.denominator;
    }
};

int main()
{
    Fraction f1, f2, f3;

    cout << "Enter Fraction 1:\n";
    f1.getFraction();

    cout << "Enter Fraction 2:\n";
    f2.getFraction();

    f3.add(f1, f2);

    cout << "Sum = ";
    f3.show();
    cout << endl;

    return 0;
}