#include <iostream>
#include <string>
#include <cstdlib> // _atold or strtold
using namespace std;

class MoneyParser
{
private:
    char moneyStr[100];
    long double amount;

public:
    // 1. Constructor
    MoneyParser() : amount(0.0) { moneyStr[0] = '\0'; }

    // 2. Destructor
    ~MoneyParser() {}

    // 3. Setter
    void setStr(const char *s)
    {
        int j = 0;
        for (int i = 0; s[i] != '\0'; i++)
        {
            // Keep digits and decimal point only
            if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
            {
                moneyStr[j++] = s[i];
            }
        }
        moneyStr[j] = '\0';
        amount = strtold(moneyStr, NULL);
    }

    // 4. Getter (using cin)
    void getInput()
    {
        char temp[100];
        cout << "Enter money string (e.g., $1,234.56): ";
        cin >> temp;
        setStr(temp);
    }

    // 5. Show
    void show()
    {
        cout << "Parsed Long Double: " << amount << endl;
    }
};

int main()
{
    MoneyParser mp;
    mp.getInput();
    mp.show();
    return 0;
}