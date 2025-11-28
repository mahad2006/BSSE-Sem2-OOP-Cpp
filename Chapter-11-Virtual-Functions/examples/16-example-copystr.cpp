#include <iostream>
using namespace std;

class StringCopier
{
private:
    char *str1;
    char str2[80];

public:
    // 1. Constructor
    StringCopier()
    {
        str1 = "Self-conquest is the greatest victory.";
    }

    // 2. Destructor
    ~StringCopier() {}

    // 3. Setter (Copy Logic)
    void copystr(char *dest, const char *src)
    {
        while (*src)
            *dest++ = *src++;
        *dest = '\0';
    }

    // 4. Getter
    void getDummy()
    {
        int x;
        cin >> x;
    }

    // 5. Show
    void show()
    {
        copystr(str2, str1);
        cout << str2 << endl;
    }
};

int main()
{
    StringCopier sc;
    sc.show();
    return 0;
}