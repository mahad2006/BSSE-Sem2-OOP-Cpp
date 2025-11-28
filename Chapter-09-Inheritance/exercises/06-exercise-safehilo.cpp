#include <iostream>
#include <cstdlib>
using namespace std;

// Base Class (Standard SafeArray)
class SafeArray
{
protected:
    enum
    {
        LIMIT = 100
    };
    int arr[LIMIT];

public:
    SafeArray()
    {
        for (int i = 0; i < LIMIT; i++)
            arr[i] = 0;
    }
    ~SafeArray() {}
    void set(int i, int v)
    {
        if (i >= 0 && i < LIMIT)
            arr[i] = v;
    }
    void get() {}  // dummy
    void show() {} // dummy
    // Simple subscript
    int &operator[](int n)
    {
        if (n < 0 || n >= LIMIT)
        {
            cout << "Error";
            exit(1);
        }
        return arr[n];
    }
};

// Derived Class
class SafeHiLo : public SafeArray
{
private:
    int lower;
    int upper;

public:
    // 1. Constructor
    SafeHiLo(int lo, int up) : lower(lo), upper(up)
    {
        if (upper - lower >= LIMIT)
        {
            cout << "Range too large";
            exit(1);
        }
    }

    // 2. Destructor
    ~SafeHiLo() {}

    // 3. Setter (Dummy required by format)
    void setBounds(int l, int u)
    {
        lower = l;
        upper = u;
    }

    // 4. Getter (using cin)
    void getInput()
    {
        int idx, val;
        cout << "Enter index (" << lower << "-" << upper << "): ";
        cin >> idx;
        cout << "Enter value: ";
        cin >> val;
        (*this)[idx] = val; // uses overloaded []
    }

    // 5. Show
    void show()
    {
        cout << "Array Bounds: " << lower << " to " << upper << endl;
    }

    // Overloaded Subscript
    int &operator[](int n)
    {
        if (n < lower || n > upper)
        {
            cout << "\nIndex " << n << " out of bounds ("
                 << lower << "-" << upper << ")";
            exit(1);
        }
        return arr[n - lower]; // Map to 0-based index
    }
};

int main()
{
    SafeHiLo sa(100, 110);
    sa.show();

    // Valid access
    sa[100] = 50;
    sa[110] = 99;

    cout << "Val at 100: " << sa[100] << endl;
    cout << "Val at 110: " << sa[110] << endl;

    // Invalid access (uncomment to test)
    // sa[99] = 10;

    return 0;
}