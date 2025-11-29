#include <iostream>
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
    void setInt(int val)
    {
        i = val;
    }

    // 4. Getter (using cin per instructions)
    void getInt()
    {
        cout << "Enter an integer value: ";
        cin >> i;
    }

    // 5. Show
    void show() const
    {
        cout << i;
    }

    // Method to add two Int objects
    void add(Int i1, Int i2)
    {
        i = i1.i + i2.i;
    }
};

int main()
{
    Int i1(7);
    Int i2(11);
    Int i3;

    cout << "i1: ";
    i1.show();
    cout << endl;
    cout << "i2: ";
    i2.show();
    cout << endl;

    i3.add(i1, i2);
    cout << "i3 (sum of i1 and i2): ";
    i3.show();
    cout << endl;

    return 0;
}