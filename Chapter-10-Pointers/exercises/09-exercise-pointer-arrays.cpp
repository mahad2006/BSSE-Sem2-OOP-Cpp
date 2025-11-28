#include <iostream>
using namespace std;

class Matrix10
{
private:
    int a0[10], a1[10], a2[10], a3[10], a4[10]; // Explicit arrays
    int a5[10], a6[10], a7[10], a8[10], a9[10];
    int *ap[10]; // Array of pointers

public:
    // 1. Constructor
    Matrix10()
    {
        ap[0] = a0;
        ap[1] = a1;
        ap[2] = a2;
        ap[3] = a3;
        ap[4] = a4;
        ap[5] = a5;
        ap[6] = a6;
        ap[7] = a7;
        ap[8] = a8;
        ap[9] = a9;

        // Initialize logic
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                *(*(ap + j) + k) = 0;
    }

    // 2. Destructor
    ~Matrix10() {}

    // 3. Setter
    void fillMatrix()
    {
        int count = 0;
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                *(*(ap + j) + k) = count; // Pointer arithmetic access
                count += 10;
            }
        }
    }

    // 4. Getter (Dummy cin)
    void getDummy()
    {
        int temp;
        cout << "Press 1 to fill matrix: ";
        cin >> temp;
        if (temp == 1)
            fillMatrix();
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
    Matrix10 m;
    m.getDummy();
    m.show();
    return 0;
}