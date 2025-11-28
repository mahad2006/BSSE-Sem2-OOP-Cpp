#include <iostream>
using namespace std;

class ArrayAdder
{
private:
    float *arr1;
    float *arr2;
    float *arr3;
    int size;

public:
    // 1. Constructor
    ArrayAdder(int s) : size(s)
    {
        arr1 = new float[s];
        arr2 = new float[s];
        arr3 = new float[s];
    }

    // 2. Destructor
    ~ArrayAdder()
    {
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
    }

    // 3. Setter / Logic
    void addArrays()
    {
        for (int i = 0; i < size; i++)
        {
            *(arr3 + i) = *(arr1 + i) + *(arr2 + i);
        }
    }

    // 4. Getter (cin)
    void getInput()
    {
        cout << "Enter values for Array 1:\n";
        for (int i = 0; i < size; i++)
        {
            cout << "A1[" << i << "]: ";
            cin >> *(arr1 + i);
        }
        cout << "Enter values for Array 2:\n";
        for (int i = 0; i < size; i++)
        {
            cout << "A2[" << i << "]: ";
            cin >> *(arr2 + i);
        }
    }

    // 5. Show
    void show() const
    {
        cout << "Results (Array 3):\n";
        for (int i = 0; i < size; i++)
        {
            cout << *(arr3 + i) << " ";
        }
        cout << endl;
    }
};

int main()
{
    ArrayAdder aa(5); // Size 5
    aa.getInput();
    aa.addArrays();
    aa.show();
    return 0;
}