#include <iostream>
using namespace std;

class ArrayWrapper
{
private:
    int *ap[10]; // 10 arrays

public:
    // 1. Constructor
    ArrayWrapper()
    {
        for (int i = 0; i < 10; i++)
            ap[i] = new int[10];
    }

    // 2. Destructor
    ~ArrayWrapper()
    {
        for (int i = 0; i < 10; i++)
            delete[] ap[i];
    }

    // 3. Setter (Helper using pointer notation)
    void setVal(int row, int col, int val)
    {
        *(*(ap + row) + col) = val;
    }

    // 4. Getter (Helper using pointer notation)
    int getVal(int row, int col) const
    {
        return *(*(ap + row) + col);
    }

    // Required Input Getter
    void getUserInput()
    {
        cout << "Filing array wrapper automatically...\n";
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                setVal(j, k, j * 10 + k);
            }
        }
    }

    // 5. Show
    void show()
    {
        // Access using "array notation" provided by class design
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                cout << (*this)[j * 10 + k] << " ";
            }
            cout << endl;
        }
    }

    // Overloaded [] to simulate 1D array access (0 to 99)
    int &operator[](int index)
    {
        int row = index / 10;
        int col = index % 10;
        return *(*(ap + row) + col);
    }
};

int main()
{
    ArrayWrapper aw;
    aw.getUserInput();
    aw.show();

    // Test direct access
    cout << "\nValue at index 55 (row 5, col 5): " << aw[55] << endl;

    return 0;
}