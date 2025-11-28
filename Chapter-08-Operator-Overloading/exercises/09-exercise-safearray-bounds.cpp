#include <iostream>
#include <cstdlib>
using namespace std;

class SafeArray
{
private:
    int lower, upper;
    int arr[100]; // Fixed size storage mapping

public:
    // 1. Constructor
    SafeArray(int low, int up) : lower(low), upper(up)
    {
        if (upper - lower >= 100)
        {
            cout << "Array too big";
            exit(1);
        }
    }

    // 2. Destructor
    ~SafeArray() {}

    // 3. Setter (using array bounds)
    void setElement(int idx, int val)
    {
        if (idx < lower || idx > upper)
        {
            cout << "Bounds Error";
            exit(1);
        }
        arr[idx - lower] = val;
    }

    // 4. Getter (using cin for a specific index)
    void getInputForIndex(int idx)
    {
        if (idx < lower || idx > upper)
        {
            cout << "Bounds Error";
            exit(1);
        }
        cout << "Enter value for index " << idx << ": ";
        cin >> arr[idx - lower];
    }

    // 5. Show
    void show()
    {
        for (int i = lower; i <= upper; i++)
            cout << "Arr[" << i << "]=" << arr[i - lower] << endl;
    }

    // Subscript operator
    int &operator[](int idx)
    {
        if (idx < lower || idx > upper)
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[idx - lower];
    }
};

int main()
{
    // Array from index 100 to 105
    SafeArray sa(100, 105);

    for (int i = 100; i <= 105; i++)
        sa[i] = i * 10;

    sa.show();
    return 0;
}