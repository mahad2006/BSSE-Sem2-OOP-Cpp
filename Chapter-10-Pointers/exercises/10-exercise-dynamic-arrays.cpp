#include <iostream>
using namespace std;

class DynMatrix
{
private:
    int *ap[10]; // Array of pointers

public:
    // 1. Constructor
    DynMatrix()
    {
        for (int j = 0; j < 10; j++)
        {
            *(ap + j) = new int[10]; // Allocate 10 integers per pointer
        }
    }

    // 2. Destructor
    ~DynMatrix()
    {
        for (int j = 0; j < 10; j++)
        {
            delete[] *(ap + j);
        }
    }

    // 3. Setter (Fill)
    void fill()
    {
        int count = 0;
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                *(*(ap + j) + k) = count; // ap[j][k] logic
                count++;
            }
        }
    }

    // 4. Getter (Dummy)
    void getDummy()
    {
        int x;
        cout << "Enter any number to start: ";
        cin >> x;
        fill();
    }

    // 5. Show
    void show() const
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                cout << *(*(ap + j) + k) << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
    DynMatrix dm;
    dm.getDummy();
    dm.show();
    return 0;
}