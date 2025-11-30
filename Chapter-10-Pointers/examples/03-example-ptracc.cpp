#include <iostream>
using namespace std;

class PointerAccess
{
private:
    int var1, var2;
    int *ptr;

public:
    // 1. Constructor
    PointerAccess() : var1(11), var2(22), ptr(NULL) {}

    // 2. Destructor
    ~PointerAccess() {}

    // 3. Setter
    void setValues(int v1, int v2)
    {
        var1 = v1;
        var2 = v2;
    }

    // 4. Getter (cin)
    void getInput()
    {
        cout << "Enter two ints: ";
        cin >> var1 >> var2;
    }

    // 5. Show
    void show()
    {
        ptr = &var1;
        cout << "Ptr points to: " << *ptr << endl;
        ptr = &var2;
        cout << "Ptr points to: " << *ptr << endl;
    }
};

int main()
{
    PointerAccess pa;
    pa.show();
    return 0;
}