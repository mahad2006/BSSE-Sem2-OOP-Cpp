#include <iostream>
using namespace std;

const int MAX = 5;

class ArrayPasser
{
private:
    double arr[MAX];

public:
    // 1. Constructor
    ArrayPasser()
    {
        arr[0] = 10.0;
        arr[1] = 43.1;
        arr[2] = 95.9;
        arr[3] = 59.7;
        arr[4] = 87.3;
    }

    // 2. Destructor
    ~ArrayPasser() {}

    // 3. Setter (Logic)
    void centimize(double *ptrd)
    {
        for (int j = 0; j < MAX; j++)
            *ptrd++ *= 2.54;
    }

    // 4. Getter
    void getInput()
    {
        cout << "Enter 5 values: ";
        for (int i = 0; i < MAX; i++)
            cin >> arr[i];
    }

    // 5. Show
    void show()
    {
        centimize(arr); // Pass array address
        for (int j = 0; j < MAX; j++)
            cout << "arr[" << j << "]=" << arr[j] << " cm" << endl;
    }
};

int main()
{
    ArrayPasser ap;
    ap.show();
    return 0;
}