#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

class MoneyFormatter
{
private:
    long double amount;
    string formatted;

public:
    // 1. Constructor
    MoneyFormatter() : amount(0.0) {}

    // 2. Destructor
    ~MoneyFormatter() {}

    // 3. Setter (Logic)
    void ldtoms(long double val)
    {
        amount = val;
        stringstream ss;
        ss << fixed << setprecision(2) << amount;
        string s = ss.str();

        string res = "$";
        int decimalPos = s.find('.');
        int count = 0;

        // Insert commas
        for (int i = decimalPos - 1; i >= 0; i--)
        {
            if (count > 0 && count % 3 == 0)
                res.insert(1, ",");
            res.insert(1, 1, s[i]);
            count++;
        }
        res += s.substr(decimalPos); // Append decimal part
        formatted = res;
    }

    // 4. Getter (using cin)
    void getInput()
    {
        cout << "Enter amount (long double): ";
        cin >> amount;
        ldtoms(amount);
    }

    // 5. Show
    void show()
    {
        cout << "Formatted: " << formatted << endl;
    }
};

int main()
{
    MoneyFormatter mf;
    mf.getInput();
    mf.show();
    return 0;
}