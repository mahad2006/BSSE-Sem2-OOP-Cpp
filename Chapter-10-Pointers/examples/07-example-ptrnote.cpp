#include <iostream>
using namespace std;

class PointerNote
{
private:
    int arr[5];

public:
    // 1. Constructor
    PointerNote()
    {
        arr[0] = 31;
        arr[1] = 54;
        arr[2] = 77;
        arr[3] = 52;
        arr[4] = 93;
    }

    // 2. Destructor
    ~PointerNote() {}

    // 3. Setter
    void setVal(int i, int v) { *(arr + i) = v; }

    // 4. Getter (cin)
    void getDummy()
    {
        int x;
        cin >> x;
    }

    // 5. Show (Pointer Notation)
    void show()
    {
        for (int j = 0; j < 5; j++)
            cout << *(arr + j) << endl; // Pointer arithmetic
    }
};

int main()
{
    PointerNote pn;
    pn.show();
    return 0;
}