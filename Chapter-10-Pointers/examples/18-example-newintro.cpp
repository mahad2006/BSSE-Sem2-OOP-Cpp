#include <iostream>
#include <cstring>
using namespace std;

class NewDemo
{
private:
    char *str;
    char *ptr;

public:
    // 1. Constructor
    NewDemo()
    {
        str = "Idle hands are the devil's workshop.";
        int len = strlen(str);
        ptr = new char[len + 1]; // Allocate
        strcpy(ptr, str);
    }

    // 2. Destructor
    ~NewDemo()
    {
        delete[] ptr; // Release
        cout << "Memory released." << endl;
    }

    // 3. Setter
    void setStr(char *s) { str = s; }

    // 4. Getter
    void getDummy()
    {
        int x;
        cin >> x;
    }

    // 5. Show
    void show()
    {
        cout << "ptr=" << ptr << endl;
    }
};

int main()
{
    NewDemo nd;
    nd.show();
    return 0;
}