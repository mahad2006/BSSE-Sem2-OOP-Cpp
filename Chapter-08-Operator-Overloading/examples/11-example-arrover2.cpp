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

    // 3. Setter (via access function return by ref)
    int &access(int n)
    {
        if (n < 0 || n >= LIMIT)
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[n];
    }

    // 4. Getter (using cin - filling manually)
    void getArrayInput()
    {
        cout << "Enter value for index 0: ";
        cin >> access(0);
    }

    // 5. Show
    void show()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Element " << i << " is " << arr[i] << endl;
        }
    }
};

int main()
{
    SafeArray sa1;

    for (int j = 0; j < LIMIT; j++)
        sa1.access(j) = j * 10; // Left side of equal sign

    sa1.show();
    return 0;
}