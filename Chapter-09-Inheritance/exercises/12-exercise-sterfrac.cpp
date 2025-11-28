#include <iostream>
using namespace std;

class Sterling
{
protected:
    long pounds;
    int shillings, pence;

public:
    Sterling() : pounds(0), shillings(0), pence(0) {}
    Sterling(double decimalPounds)
    {
        pounds = static_cast<long>(decimalPounds);
        double decFrac = decimalPounds - pounds;
        double totalPence = decFrac * 240;
        shillings = static_cast<int>(totalPence) / 12;
        pence = static_cast<int>(totalPence) % 12;
    }
    ~Sterling() {}
    void getSterling()
    {
        cout << "Enter L S P: ";
        cin >> pounds >> shillings >> pence;
    }
    void putSterling() const
    {
        cout << "L" << pounds << "." << shillings << "." << pence;
    }
    operator double() const
    {
        return pounds + (shillings * 12 + pence) / 240.0;
    }
    void setS() {}
    void show() { putSterling(); }
};

class Sterfrac : public Sterling
{
private:
    int eighths; // 1/8 of a penny
public:
    // 1. Constructor
    Sterfrac() : Sterling(), eighths(0) {}
    Sterfrac(double val) : Sterling(val)
    {
        // Calculate remainder for eighths
        double decPounds = val;
        long p = (long)decPounds;
        double frac = decPounds - p;
        double totalPence = frac * 240;
        int s = (int)totalPence / 12;
        int pe = (int)totalPence % 12;
        double fracPence = totalPence - (s * 12 + pe);
        eighths = (int)(fracPence * 8);
    }

    // 2. Destructor
    ~Sterfrac() {}

    // 3. Setter
    void setFrac(int e) { eighths = e; }

    // 4. Getter
    void getSterling()
    {
        int num, den;
        char slash;
        Sterling::getSterling(); // Gets L.S.P
        cout << "Enter fraction (n/8): ";
        cin >> num >> slash >> den;
        if (den == 8)
            eighths = num;
        else
            eighths = 0; // Simple validation
    }

    // 5. Show
    void putSterling() const
    {
        Sterling::putSterling();
        if (eighths != 0)
            cout << "-" << eighths << "/8";
    }
    void show() { putSterling(); }

    // Math Operators
    Sterfrac operator+(Sterfrac s2)
    {
        return Sterfrac(double(*this) + double(s2));
    }

    operator double() const
    {
        return Sterling::operator double() + (eighths / 8.0) / 240.0;
    }
};

int main()
{
    Sterfrac s1, s2, s3;

    cout << "Enter S1:" << endl;
    s1.getSterling();

    cout << "Enter S2:" << endl;
    s2.getSterling();

    s3 = s1 + s2;

    cout << "Sum: ";
    s3.show();
    cout << endl;

    return 0;
}