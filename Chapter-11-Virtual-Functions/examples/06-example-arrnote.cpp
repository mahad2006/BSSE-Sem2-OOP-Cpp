#include <iostream>
using namespace std;

class ArrayNote
{
private:
    int arr[5];

public:
    // 1. Constructor
    ArrayNote()
    {
        arr[0] = 31;
        arr[1] = 54;
        arr[2] = 77;
        arr[3] = 52;
        arr[4] = 93;
    }

    // 2. Destructor
    ~ArrayNote() {}

    // 3. Setter
    void setArr(int idx, int val) { arr[idx] = val; }

    // 4. Getter (cin)
    void getInput()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter val " << i << ": ";
            cin >> arr[i];
        }
    }

    // 5. Show
    void show()
    {
        for (int j = 0; j < 5; j++)
            cout << arr[j] << endl;
    }
};

int main()
{
    ArrayNote an;
    an.show();
    return 0;
}