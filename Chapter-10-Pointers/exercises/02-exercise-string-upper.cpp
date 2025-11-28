#include <iostream>
#include <cstring>
#include <cctype> // for toupper
using namespace std;

class String
{
private:
    char *str;

public:
    // 1. Constructor
    String(const char *s = "")
    {
        int len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }

    // 2. Destructor
    ~String()
    {
        delete[] str;
    }

    // 3. Setter
    void setString(const char *s)
    {
        delete[] str;
        int len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }

    // 4. Getter (using cin)
    void getString()
    {
        char buffer[100];
        cout << "Enter string: ";
        cin >> buffer;
        setString(buffer);
    }

    // Function to uppercase string
    void upit()
    {
        char *ptr = str;
        while (*ptr)
        {
            *ptr = toupper(*ptr);
            ptr++;
        }
    }

    // 5. Show
    void show() const
    {
        cout << "String: " << str << endl;
    }
};

int main()
{
    String s;
    s.getString();

    cout << "Original ";
    s.show();

    s.upit();
    cout << "Uppercased ";
    s.show();

    return 0;
}