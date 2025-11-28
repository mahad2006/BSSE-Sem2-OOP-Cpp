#include <iostream>
using namespace std;

class StringComp
{
private:
    char str1[80];
    char str2[80];

public:
    // 1. Constructor
    StringComp()
    {
        str1[0] = '\0';
        str2[0] = '\0';
    }

    // 2. Destructor
    ~StringComp() {}

    // 3. Setter (Manual logic)
    int compstr(const char *s1, const char *s2)
    {
        while (*s1 && *s2)
        {
            if (*s1 < *s2)
                return -1;
            if (*s1 > *s2)
                return 1;
            s1++;
            s2++;
        }
        // Check lengths if prefix matches
        if (*s1)
            return 1; // s1 longer
        if (*s2)
            return -1; // s2 longer
        return 0;      // Equal
    }

    // 4. Getter
    void getInput()
    {
        cout << "Enter string 1: ";
        cin >> str1;
        cout << "Enter string 2: ";
        cin >> str2;
    }

    // 5. Show
    void show()
    {
        int result = compstr(str1, str2);
        cout << "Comparison result: " << result << endl;
        if (result == 0)
            cout << "Strings are equal.";
        else if (result < 0)
            cout << str1 << " comes before " << str2;
        else
            cout << str1 << " comes after " << str2;
        cout << endl;
    }
};

int main()
{
    StringComp sc;
    sc.getInput();
    sc.show();
    return 0;
}