#include <iostream>
#include <cstring>
using namespace std;

const int MAX_LEN = 80;

class String
{
private:
    char str[MAX_LEN];

public:
    // 1. Constructor
    String() { str[0] = '\0'; }
    String(const char s[])
    {
        strcpy(str, s);
    }

    // 2. Destructor
    ~String() {}

    // 3. Setter (Assignment)
    void set(const char s[])
    {
        strcpy(str, s);
    }

    // 4. Getter (cin)
    void getInput()
    {
        cout << "Enter a string (max 79 chars): ";
        cin.ignore(); // Clear buffer
        cin.getline(str, MAX_LEN);
    }

    // 5. Show
    void display() const
    {
        cout << str;
    }

    // Required show function
    void show() const
    {
        display();
        cout << endl;
    }

    // Additional utility
    void concat(String s2)
    {
        if (strlen(str) + strlen(s2.str) < MAX_LEN)
        {
            strcat(str, s2.str);
        }
        else
        {
            cout << "\nError: Concatenation too long." << endl;
        }
    }
};

int main()
{
    String s1("I'm happy with ");
    String s2 = "C++.";
    String s3;

    s1.show();
    s2.show();

    s3.concat(s1);
    s3.concat(s2);

    cout << "s3: ";
    s3.show();

    s3.getInput();
    cout << "You entered: ";
    s3.show();

    return 0;
}