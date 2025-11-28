#include <iostream>
#include <cstring> // For standard string functions
using namespace std;

class StringFuncs
{
private:
    char str1[80];
    char str2[80];

public:
    // 1. Constructor
    StringFuncs()
    {
        strcpy(str1, "I like C++.");
        strcpy(str2, "");
    }

    // 2. Destructor
    ~StringFuncs() {}

    // 3. Setter (String concatenation)
    void concatenate()
    {
        strcat(str1, " But I love OOP!");
    }

    // 4. Getter (cin)
    void getInput()
    {
        cout << "Enter a string (replaces str2): ";
        cin.ignore(); // Clear buffer
        cin.getline(str2, 80);
    }

    // 5. Show
    void show()
    {
        cout << "\nstr1: " << str1 << endl;
        cout << "str2: " << str2 << endl;
        cout << "Length of str1: " << strlen(str1) << endl;

        if (strcmp(str1, str2) == 0)
        {
            cout << "str1 and str2 are equal." << endl;
        }
        else
        {
            cout << "str1 and str2 are different." << endl;
        }
    }
};

int main()
{
    StringFuncs sf;
    sf.show();
    sf.concatenate();
    sf.getInput();
    sf.show();
    return 0;
}