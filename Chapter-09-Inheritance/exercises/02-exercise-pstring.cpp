#include <iostream>
#include <cstring>
using namespace std;

// Base Class (Standard C-string wrapper)
class String
{
protected:
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

    // 3. Setter
    void setString(char s[]) { strcpy(str, s); }

    // 4. Getter (cin)
    void display() const { cout << str; } // Using display as show/getter equivalent for output

    // Explicit Getter for Input
    void getStringInput()
    {
        cout << "Enter string: ";
        cin >> str;
    }

    // 5. Show
    void show() const { cout << str; }

    // Operator needed for exercise
    operator char *() { return str; }
};

// Derived Class
class Pstring : public String
{
public:
    // 1. Constructor (Checking bounds)
    Pstring(char s[])
    {
        if (strlen(s) > SZ - 1)
        {
            // Copy only SZ-1 characters
            int i;
            for (i = 0; i < SZ - 1; i++)
                str[i] = s[i];
            str[i] = '\0'; // Null terminate
        }
        else
        {
            strcpy(str, s);
        }
    }

    // No-arg Constructor
    Pstring() : String() {}

    // 2. Destructor
    ~Pstring() {}

    // 3. Setter
    void setPString(char s[])
    {
        if (strlen(s) > SZ - 1)
        {
            strncpy(str, s, SZ - 1);
            str[SZ - 1] = '\0';
        }
        else
        {
            strcpy(str, s);
        }
    }

    // 4. Getter
    void getStringInput()
    {
        cout << "Enter string: ";
        cin.get(str, SZ); // Safe input by default with get
    }

    // 5. Show
    void show() { cout << str; }
};

int main()
{
    // String longer than 80 chars
    char longStr[] = "This string is definitely longer than eighty characters and should trigger the Pstring protection mechanism to cut it off before it overflows the buffer and causes a crash.";

    Pstring s1(longStr); // Uses protected constructor

    cout << "Original length: " << strlen(longStr) << endl;
    cout << "Pstring content: ";
    s1.show();
    cout << "\nPstring length: " << strlen(s1) << endl;

    return 0;
}