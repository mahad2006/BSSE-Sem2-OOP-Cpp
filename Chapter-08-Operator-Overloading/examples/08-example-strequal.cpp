#include <iostream>
#include <cstring>
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
    void setString(char s[]) { strcpy(str, s); }

    // 4. Getter (using cin)
    void getStr()
    {
        cin.get(str, SZ);
    }

    // 5. Show
    void show() const { cout << str; }

    // Overloaded == operator
    bool operator==(String ss) const
    {
        return (strcmp(str, ss.str) == 0);
    }
};

int main()
{
    String s1 = "yes";
    String s2 = "no";
    String s3;

    cout << "Enter 'yes' or 'no': ";
    s3.getStr();

    if (s3 == s1)
        cout << "You typed yes\n";
    else if (s3 == s2)
        cout << "You typed no\n";
    else
        cout << "You didn't follow instructions\n";

    return 0;
}