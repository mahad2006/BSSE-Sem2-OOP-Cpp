#include <iostream>
using namespace std;

class Sterling
{
private:
    long pounds;
    int shillings, pence;

public:
    // 1. Constructor
    Sterling() : pounds(0), shillings(0), pence(0) {}
    Sterling(double decimalPounds)
    {
        pounds = static_cast<long>(decimalPounds);
        double decFrac = decimalPounds - pounds;
        double totalPence = decFrac * 240;
        shillings = static_cast<int>(totalPence) / 12;
        pence = static_cast<int>(totalPence) % 12;
    }
    Sterling(long p, int s, int pe) : pounds(p), shillings(s), pence(pe) {}

    // 2. Destructor
    ~Sterling() {}

    // 3. Setter
    void setSterling(long p, int s, int pe)
    {
        pounds = p;
        shillings = s;
        pence = pe;
    }

    // 4. Getter (using cin)
    void getSterling()
    {
        cout << "Enter pounds shillings pence: ";
        cin >> pounds >> shillings >> pence;
    }

    // 5. Show
    void show() const
    {
        cout << "L" << pounds << "." << shillings << "." << pence;
    }

    // Conversion to double
    operator double() const
    {
        return pounds + (shillings * 12 + pence) / 240.0;
    }

    Sterling operator+(Sterling s2)
    {
        return Sterling(double(*this) + double(s2));
    }
    Sterling operator-(Sterling s2)
    {
        return Sterling(double(*this) - double(s2));
    }
    Sterling operator*(double factor)
    {
        return Sterling(double(*this) * factor);
    }
    Sterling operator/(Sterling s2)
    {
        return Sterling(double(*this) / double(s2));
    }
    Sterling operator/(double div)
    {
        return Sterling(double(*this) / div);
    }
};

int main()
{
    Sterling s1(5, 2, 6);
    Sterling s2(2, 10, 0);
    Sterling s3;

    s3 = s1 + s2;
    cout << "Sum: ";
    s3.show();
    cout << endl;

    s3 = s1 * 2.5;
    cout << "Mult: ";
    s3.show();
    cout << endl;

    return 0;
}