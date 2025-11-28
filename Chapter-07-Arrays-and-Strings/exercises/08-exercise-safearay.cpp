#include <iostream>
#include <cstdlib> // exit()
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

    // 3. Setter
    void putEl(int index, int val)
    {
        if (index < 0 || index >= LIMIT)
        {
            cout << "\nIndex out of bounds!";
            exit(1);
        }
        arr[index] = val;
    }

    // 4. Getter (Logic + Cin wrapper)
    int getEl(int index) const
    {
        if (index < 0 || index >= LIMIT)
        {
            cout << "\nIndex out of bounds!";
            exit(1);
        }
        return arr[index];
    }

    void getInput()
    {
        int idx, val;
        cout << "Enter index and value: ";
        cin >> idx >> val;
        putEl(idx, val);
    }

    // 5. Show
    void show(int index)
    {
        cout << "Value at " << index << ": " << getEl(index) << endl;
    }
};

int main()
{
    SafeArray sa;

    // Test valid
    sa.putEl(7, 12345);
    sa.show(7);

    // Test input
    sa.getInput();

    // Test invalid (Uncomment to crash safely)
    // sa.putEl(101, 99);

    return 0;
}