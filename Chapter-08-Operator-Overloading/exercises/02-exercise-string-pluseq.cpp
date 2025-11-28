#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class String
{
private:
    enum
    {
        SZ = 80
    };
    char str[SZ];

public:
    // 1. Constructor
    String() { strcpy(str, ""); }
    String(char s[]) { strcpy(str, s); }

    // 2. Destructor
    ~String() {}

    // 3. Setter
    void setString(char s[])
    {
        if (strlen(s) < SZ)
            strcpy(str, s);
    }

    // 4. Getter (using cin)
    void getStringInput()
    {
        cout << "Enter string: ";
        cin.get(str, SZ);
        // Clear buffer if needed, simplistic approach here
        if (cin.peek() == '\n')
            cin.ignore();
    }

    // 5. Show
    void show() const
    {
        cout << str;
    }

    // Overloaded += operator
    void operator+=(String ss)
    {
        if (strlen(str) + strlen(ss.str) < SZ)
        {
            strcat(str, ss.str);
        }
        else
        {
            cout << "\nString overflow";
            exit(1);
        }
    }
};

int main()
{
    String s1 = "Merry Christmas! ";
    String s2 = "Happy New Year!";
    String s3; // Empty

    cout << "s1: ";
    s1.show();
    cout << endl;
    cout << "s2: ";
    s2.show();
    cout << endl;

    s1 += s2; // Concatenate s2 onto s1

    cout << "s1 += s2 result: ";
    s1.show();
    cout << endl;

    return 0;
}