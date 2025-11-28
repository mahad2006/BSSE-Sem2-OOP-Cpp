#include <iostream>
#include <cstdlib> // for exit()
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

    // 3. Setter (put element)
    void putEl(int n, int elvalue)
    {
        if (n < 0 || n >= LIMIT)
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        arr[n] = elvalue;
    }

    // 4. Getter (Logic getter)
    int getEl(int n) const
    {
        if (n < 0 || n >= LIMIT)
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[n];
    }

    // 4.1 Required cin Getter (fills array manually)
    void fillArray()
    {
        cout << "Filling array from 0 to 4 (test)..." << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter value for index " << i << ": ";
            cin >> arr[i];
        }
    }

    // 5. Show
    void show()
    {
        // Displaying first 5 elements for brevity
        for (int i = 0; i < 5; i++)
        {
            cout << "Element " << i << " is " << arr[i] << endl;
        }
    }
};

int main()
{
    SafeArray sa1;

    // Using putEl logic
    for (int j = 0; j < 5; j++)
        sa1.putEl(j, j * 10);

    sa1.show();

    return 0;
}