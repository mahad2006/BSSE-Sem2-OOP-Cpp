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
    // 1. Constructor (No args)
    String() { str[0] = '\0'; }

    // Conversion Constructor (char* to String)
    String(char s[]) { strcpy(str, s); }

    // 2. Destructor
    ~String() {}

    // 3. Setter
    void setString(char s[]) { strcpy(str, s); }

    // 4. Getter (using cin)
    void getStringInput()
    {
        cout << "Enter string: ";
        cin.get(str, SZ);
    }

    // 5. Show
    void show() const { cout << str; }

    // Conversion Operator (String to char*)
    operator char *() { return str; }
};

int main()
{
    String s1;
    char xstr[] = "Joyeux Noel! ";

    s1 = xstr; // uses constructor
    s1.show();

    String s2 = "Bonne Annee!";
    // uses conversion operator to print as char*
    cout << static_cast<char *>(s2) << endl;

    return 0;
}