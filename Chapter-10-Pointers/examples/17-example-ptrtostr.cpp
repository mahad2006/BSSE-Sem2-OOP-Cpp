#include <iostream>
using namespace std;

class StringArray
{
private:
    static const int DAYS = 7;
    const char *arrptrs[DAYS];

public:
    // 1. Constructor
    StringArray()
    {
        arrptrs[0] = "Sunday";
        arrptrs[1] = "Monday";
        arrptrs[2] = "Tuesday";
        arrptrs[3] = "Wednesday";
        arrptrs[4] = "Thursday";
        arrptrs[5] = "Friday";
        arrptrs[6] = "Saturday";
    }

    // 2. Destructor
    ~StringArray() {}

    // 3. Setter
    void setPtr(int i, const char *s) { arrptrs[i] = s; }

    // 4. Getter
    void getDummy()
    {
        int x;
        cin >> x;
    }

    // 5. Show
    void show()
    {
        for (int j = 0; j < DAYS; j++)
            cout << arrptrs[j] << endl;
    }
};

int main()
{
    StringArray sa;
    sa.show();
    return 0;
}