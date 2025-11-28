#include <iostream>
#include <cstdlib>
using namespace std;

const int LIMIT = 100;

class SafeArray
{
private:
    int arr[LIMIT];

public:
    // 1. Constructor
    SafeArray()
    {
        for (int i = 0; i < LIMIT; i++)
            arr[i] = 0;
    }

    // 2. Destructor
    ~SafeArray() {}

    // 3. Setter (Helper to bulk set, though [] acts as setter too)
    void setAll(int val)
    {
        for (int i = 0; i < LIMIT; i++)
            arr[i] = val;
    }

    // 4. Getter (using cin via [])
    void getElementInput()
    {
        int idx;
        cout << "Enter index to set: ";
        cin >> idx;
        cout << "Enter value: ";
        cin >> (*this)[idx]; // Using overloaded operator
    }

    // 5. Show
    void show()
    {
        for (int i = 0; i < 5; i++)
            cout << "Element " << i << " is " << arr[i] << endl;
    }

    // Overloaded [] operator
    int &operator[](int n)
    {
        if (n < 0 || n >= LIMIT)
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[n];
    }
};

int main()
{
    SafeArray sa1;

    for (int j = 0; j < LIMIT; j++)
        sa1[j] = j * 10; // using [] on left side

    sa1.show();
    return 0;
}