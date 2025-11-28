#include <iostream>
using namespace std;

class MaxFinder
{
private:
    int arr[100];
    int size;

public:
    // 1. Constructor
    MaxFinder() : size(0) {}

    // 2. Destructor
    ~MaxFinder() {}

    // 3. Setter
    void setSize(int s) { size = s; }

    // 4. Getter (Input numbers)
    void getNumbers()
    {
        cout << "Enter count of numbers: ";
        cin >> size;
        for (int i = 0; i < size; i++)
        {
            cout << "Value " << i + 1 << ": ";
            cin >> arr[i];
        }
    }

    // Logic function
    int maxint(int values[], int n)
    {
        int maxIdx = 0;
        for (int i = 1; i < n; i++)
        {
            if (values[i] > values[maxIdx])
                maxIdx = i;
        }
        return maxIdx;
    }

    // 5. Show
    void show()
    {
        int idx = maxint(arr, size);
        cout << "Largest value is " << arr[idx] << " at index " << idx << endl;
    }
};

int main()
{
    MaxFinder mf;
    mf.getNumbers();
    mf.show();
    return 0;
}