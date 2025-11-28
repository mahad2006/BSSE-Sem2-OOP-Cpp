#include <iostream>
using namespace std;

class FloatArray
{
private:
    float *arr;
    int size;

public:
    // 1. Constructor
    FloatArray(int s) : size(s)
    {
        arr = new float[size]; // Allocate memory
    }

    // 2. Destructor
    ~FloatArray()
    {
        delete[] arr; // Clean up
    }

    // 3. Setter (using pointer notation)
    void setVal(int index, float val)
    {
        *(arr + index) = val;
    }

    // 4. Getter (using cin and pointer notation)
    void getInput()
    {
        cout << "Enter " << size << " numbers:\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Value " << i + 1 << ": ";
            cin >> *(arr + i);
        }
    }

    // 5. Show (Calculates average)
    void show() const
    {
        float sum = 0.0;
        for (int i = 0; i < size; i++)
        {
            sum += *(arr + i);
        }
        cout << "Average: " << sum / size << endl;
    }
};

int main()
{
    int s;
    cout << "How many numbers? ";
    cin >> s;

    FloatArray fa(s);
    fa.getInput();
    fa.show();

    return 0;
}