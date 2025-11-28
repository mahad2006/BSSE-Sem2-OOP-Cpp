#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char *str;

public:
    // 1. Constructor
    String(const char *s)
    {
        int length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // 2. Destructor
    ~String()
    {
        cout << "Deleting str.\n";
        delete[] str;
    }

    // 3. Setter
    void setString(const char *s)
    {
        delete[] str; // Delete old
        int length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // 4. Getter
    void getInput()
    {
        char buffer[100];
        cout << "Enter text: ";
        cin >> buffer;
        setString(buffer);
    }

    // 5. Show
    void show() const
    {
        cout << str << endl;
    }

    // Required by format: public display function
    void display() { show(); }
};

int main()
{
    String s1("Who knows nothing doubts nothing.");
    cout << "s1=";
    s1.display();
    return 0;
}