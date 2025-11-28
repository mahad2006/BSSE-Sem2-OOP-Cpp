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
    String() { str[0] = '\0'; }
    String(char s[]) { strcpy(str, s); }

    // 2. Destructor
    ~String() {}

    // 3. Setter (Concatenation Logic)
    void concat(String s2)
    {
        if (strlen(str) + strlen(s2.str) < SZ)
            strcat(str, s2.str);
        else
            cout << "\nString too long";
    }

    // 4. Getter (using cin)
    void getStringInput()
    {
        cout << "Enter string: ";
        cin.get(str, SZ);
    }

    // 5. Show
    void display() const
    {
        cout << str;
    }
    void show()
    {
        display();
        cout << endl;
    } // Required show
};

int main()
{
    String s1("Merry Christmas! ");
    String s2 = "Season's Greetings!";
    String s3;

    cout << "\ns1=";
    s1.display();
    cout << "\ns2=";
    s2.display();

    s3 = s1; // Assignment works for simple classes
    cout << "\ns3=";
    s3.display();

    s3.concat(s2);
    cout << "\ns3=";
    s3.display();
    cout << endl;

    return 0;
}