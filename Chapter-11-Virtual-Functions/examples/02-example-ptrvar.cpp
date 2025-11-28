#include <iostream>
using namespace std;

class PointerVarDemo
{
private:
    int var1, var2;
    int *ptr;

public:
    // 1. Constructor
    PointerVarDemo() : var1(11), var2(22), ptr(NULL) {}

    // 2. Destructor
    ~PointerVarDemo() {}

    // 3. Setter
    void setPtrToVar1() { ptr = &var1; }
    void setPtrToVar2() { ptr = &var2; }

    // 4. Getter (cin)
    void getInput()
    {
        cout << "Enter val 1: ";
        cin >> var1;
        cout << "Enter val 2: ";
        cin >> var2;
    }

    // 5. Show
    void show()
    {
        cout << "Pointer value: " << ptr << endl;
    }
};

int main()
{
    PointerVarDemo pd;
    pd.setPtrToVar1();
    pd.show();
    pd.setPtrToVar2();
    pd.show();
    return 0;
}