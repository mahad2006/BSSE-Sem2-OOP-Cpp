#include <iostream>
#include <cstring>
#include <cstdlib> // for exit()
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
        strcpy(str, s);
    }

    // 4. Getter (using cin)
    void getStringInput()
    {
        cout << "Enter string: ";
        cin.get(str, SZ);
    }

    // 5. Show
    void show() const
    {
        cout << str;
    }

    // Overloaded + operator
    String operator+(String ss) const
    {
        String temp;
        if (strlen(str) + strlen(ss.str) < SZ)
        {
            strcpy(temp.str, str);
            strcat(temp.str, ss.str);
        }
        else
        {
            cout << "\nString overflow";
            exit(1);
        }
        return temp;
    }
};

int main()
{
    String s1 = "\nMerry Christmas! ";
    String s2 = "Happy new year!";
    String s3;

    s1.show();
    s2.show();

    s3 = s1 + s2; // Concatenation

    cout << "\nResult: ";
    s3.show();
    cout << endl;

    return 0;
}