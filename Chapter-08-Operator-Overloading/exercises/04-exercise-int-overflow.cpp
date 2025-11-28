#include <iostream>
#include <cstdlib> // for exit
using namespace std;

class Int
{
private:
    int i;

public:
    // 1. Constructor
    Int() : i(0) {}
    Int(int val) : i(val) {}

    // 2. Destructor
    ~Int() {}

    // 3. Setter
    void setInt(int val) { i = val; }

    // 4. Getter (using cin)
    void getInt()
    {
        cout << "Enter integer: ";
        cin >> i;
    }

    // 5. Show
    void show() const { cout << i; }

    // Helper to check overflow
    void checkOverflow(long double val) const
    {
        if (val > 2147483647.0L || val < -2147483648.0L)
        {
            cout << "\nError: Arithmetic Overflow";
            exit(1);
        }
    }

    Int operator+(Int i2)
    {
        long double res = (long double)i + i2.i;
        checkOverflow(res);
        return Int((int)res);
    }

    Int operator-(Int i2)
    {
        long double res = (long double)i - i2.i;
        checkOverflow(res);
        return Int((int)res);
    }

    Int operator*(Int i2)
    {
        long double res = (long double)i * i2.i;
        checkOverflow(res);
        return Int((int)res);
    }

    Int operator/(Int i2)
    {
        if (i2.i == 0)
        {
            cout << "\nError: Division by zero";
            exit(1);
        }
        return Int(i / i2.i);
    }
};

int main()
{
    Int i1(2000000000);
    Int i2(2000000000);
    Int i3;

    cout << "i1: ";
    i1.show();
    cout << endl;
    cout << "i2: ";
    i2.show();
    cout << endl;

    // Uncommenting this triggers overflow
    // i3 = i1 + i2;
    // cout << "Sum: "; i3.show();

    Int i4(100), i5(5);
    i3 = i4 / i5;
    cout << "100 / 5 = ";
    i3.show();
    cout << endl;

    return 0;
}