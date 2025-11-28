#include <iostream>
#include <iomanip>
using namespace std;

const int DISTRICTS = 4;
const int MONTHS = 3;

class SalesFunc
{
private:
    double sales[DISTRICTS][MONTHS];

public:
    // 1. Constructor
    SalesFunc()
    {
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
    ~SalesFunc() {}

    // 3. Setter
    void setVal(int d, int m, double v) { sales[d][m] = v; }

    // 4. Getter
    void getDummy()
    {
        int x;
        cin >> x;
    }

    // 5. Show
    void show()
    {
        display(sales); // Call internal helper function
    }

    // Helper function representing the example's standalone function
    void display(double funsales[DISTRICTS][MONTHS])
    {
        cout << "\n\n\t\tMonth\n";
        cout << "\t1\t2\t3\n";
        for (int d = 0; d < DISTRICTS; d++)
        {
            cout << "\nDistrict " << d + 1;
            for (int m = 0; m < MONTHS; m++)
            {
                cout << setiosflags(ios::fixed) << setw(10)
                     << setiosflags(ios::showpoint) << setprecision(2)
                     << funsales[d][m];
            }
        }
        cout << endl;
    }
};

int main()
{
    SalesFunc sf;
    sf.show();
    return 0;
}