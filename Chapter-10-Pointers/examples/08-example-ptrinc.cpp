#include <iostream>
using namespace std;

class PointerInc
{
private:
    int arr[5];
    int *ptr;

public:
    // 1. Constructor
    PointerInc()
    {
        int temp[] = {31, 54, 77, 52, 93};
        for (int i = 0; i < 5; i++)
            arr[i] = temp[i];
    }

    // 2. Destructor
    ~PointerInc() {}

    // 3. Setter
    void resetPtr() { ptr = arr; }

    // 4. Getter
    void getDummy()
    {
        int x;
        cin >> x;
    }

    // 5. Show
    void show()
    {
        ptr = arr;
        for (int j = 0; j < 5; j++)
            cout << *(ptr++) << endl; // Increment pointer
    }
};

int main()
{
    PointerInc pi;
    pi.show();
    return 0;
}