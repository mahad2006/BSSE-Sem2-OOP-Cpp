#include <iostream>
#include <iomanip>
using namespace std;

const int DISTRICTS = 4;
const int MONTHS = 3;

class SalesInit
{
private:
    double sales[DISTRICTS][MONTHS];

public:
    // 1. Constructor (Initialize 2D array manually here for class logic)
    SalesInit()
    {
        // Simulating the initialization list logic from example
        double temp[DISTRICTS][MONTHS] = {
            {1432.07, 234.50, 654.01},
            {322.00, 13838.32, 17589.88},
            {9328.34, 934.00, 4492.30},
            {12838.29, 2332.63, 32.93}};
        for (int d = 0; d < DISTRICTS; d++)
            for (int m = 0; m < MONTHS; m++)
                sales[d][m] = temp[d][m];
    }

    // 2. Destructor
    ~SalesInit() {}

    // 3. Setter
    void setVal(int d, int m, double v) { sales[d][m] = v; }

    // 4. Getter (Dummy)
    void getDummy()
    {
        int x;
        cin >> x;
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
                cout << setw(10) << setiosflags(ios::fixed)
                     << setiosflags(ios::showpoint) << setprecision(2)
                     << sales[d][m];
            }
        }
        cout << endl;
    }
};

int main()
{
    SalesInit si;
    si.show();
    return 0;
}