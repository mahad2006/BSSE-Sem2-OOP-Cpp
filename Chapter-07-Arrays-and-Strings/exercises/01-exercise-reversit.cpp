#include <iostream>
#include <cstring>
using namespace std;

class StringReverser
{
private:
    char str[100];

public:
    // 1. Constructor
    StringReverser() { str[0] = '\0'; }

    // 2. Destructor
    ~StringReverser() {}

    // 3. Setter (Manual Logic)
    void reversit(char s[])
    {
        int len = strlen(s);
        for (int i = 0; i < len / 2; i++)
        {
            char temp = s[i];
            s[i] = s[len - 1 - i];
            s[len - 1 - i] = temp;
        }
    }

    // 4. Getter (using cin.get)
    void getStringInput()
    {
        cout << "Enter a string: ";
        cin.get(str, 100);
    }

    // 5. Show
    void show()
    {
        cout << "Original/Stored string: " << str << endl;
        reversit(str);
        cout << "Reversed string: " << str << endl;
    }
};

int main()
{
    StringReverser sr;
    sr.getStringInput();
    sr.show();
    return 0;
}