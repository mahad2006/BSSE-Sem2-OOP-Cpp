#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std;

class bMoney
{
private:
    long double money;

public:
    // 1. Constructor
    bMoney() : money(0.0) {}
    bMoney(char s[]) { setMoneyStr(s); }

    // 2. Destructor
    ~bMoney() {}

    // 3. Setter (String to long double)
    void setMoneyStr(string s)
    {
        string clean;
        for (char c : s)
        {
            if ((c >= '0' && c <= '9') || c == '.')
                clean += c;
        }
        money = strtold(clean.c_str(), NULL);
    }

    // Logic Setter (Add)
    void madd(bMoney m1, bMoney m2)
    {
        money = m1.money + m2.money;
    }

    // 4. Getter (using cin)
    void getMoney()
    {
        string s;
        cout << "Enter money string (e.g., $1,000.50): ";
        cin >> s;
        setMoneyStr(s);
    }

    // 5. Show (Long double to String logic built-in)
    void putMoney() const
    {
        stringstream ss;
        ss << fixed << setprecision(2) << money;
        string s = ss.str();
        int dec = s.find('.');
        string out = "$";
        int count = 0;
        for (int i = dec - 1; i >= 0; i--)
        {
            if (count && count % 3 == 0)
                out.insert(1, ",");
            out.insert(1, 1, s[i]);
            count++;
        }
        out += s.substr(dec);
        cout << out << endl;
    }
};

int main()
{
    bMoney m1, m2, m3;

    cout << "Money 1:" << endl;
    m1.getMoney();

    cout << "Money 2:" << endl;
    m2.getMoney();

    m3.madd(m1, m2);

    cout << "Sum: ";
    m3.putMoney();

    return 0;
}