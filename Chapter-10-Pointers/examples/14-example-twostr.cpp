#include <iostream>
using namespace std;

class StringDemo
{
private:
    char str1[20];    // Array
    const char *str2; // Pointer constant

public:
    // 1. Constructor
    StringDemo() : str2("Defined as pointer")
    {
        // copy manually to array
        const char *src = "Defined as array";
        int i = 0;
        while (src[i])
        {
            str1[i] = src[i];
            i++;
        }
        str1[i] = '\0';
    }

    // 2. Destructor
    ~StringDemo() {}

    // 3. Setter
    void incrementPointer()
    {
        str2++; // Valid for pointer
        // str1++; // Invalid for array
    }

    // 4. Getter
    void getDummy()
    {
        char c;
        cin >> c;
    }

    // 5. Show
    void show()
    {
        cout << str1 << endl;
        cout << str2 << endl;
        incrementPointer();
        cout << str2 << " (after increment)" << endl;
    }
};

int main()
{
    StringDemo sd;
    sd.show();
    return 0;
}