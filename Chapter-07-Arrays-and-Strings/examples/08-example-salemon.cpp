#include <iostream>
#include <iomanip>
using namespace std;

const int DISTRICTS = 4;
const int MONTHS = 3;

class SalesMon
{
private:
    double sales[DISTRICTS][MONTHS];

public:
    // 1. Constructor
    SalesMon()
    {
        for (int d = 0; d < DISTRICTS; d++)
            for (int m = 0; m < MONTHS; m++)
                sales[d][m] = 0.0;
    }

    // 2. Destructor
    ~SalesMon() {}

    // 3. Setter
    void setSale(int d, int m, double val)
    {
        sales[d][m] = val;
    }

    // 4. Getter (using cin)
    void getSalesInput()
    {
        for (int d = 0; d < DISTRICTS; d++)
        {
            for (int m = 0; m < MONTHS; m++)
            {
                cout << "Enter sales for district " << d + 1
                     << ", month " << m + 1 << ": ";
                cin >> sales[d][m];
            }
        }
    }

    // 5. Show
    void show()
    {
        cout << "\n\n\t\tMonth\n";
        cout << "\t1\t2\t3\n";
        for (int d = 0; d < DISTRICTS; d++)
        {
            cout << "\nDistrict " << d + 1;
            for (int m = 0; m < MONTHS; m++)
            {
                cout << setiosflags(ios::fixed)
                     << setiosflags(ios::showpoint)
                     << setprecision(2)
                     << "\t" << sales[d][m];
            }
        }
        cout << endl;
    }
};

int main()
{
    SalesMon sm;
    sm.getSalesInput();
    sm.show();
    return 0;
}