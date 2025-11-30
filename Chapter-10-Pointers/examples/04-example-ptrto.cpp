#include <iostream>
using namespace std;

class PointerAssign
{
private:
    int var1, var2;
    int *ptr;

public:
    // 1. Constructor
    PointerAssign() : var1(0), var2(0), ptr(NULL) {}

    // 2. Destructor
    ~PointerAssign() {}

    // 3. Setter (Indirect assignment)
    void assignIndirectly(int val)
    {
        ptr = &var1;
        *ptr = val;  // Assigns to var1
        var2 = *ptr; // Assigns to var2
    }

    // 4. Getter (cin)
    void getDummy()
    {
        int x;
        cout << "Enter dummy: ";
        cin >> x;
    }

    // 5. Show
    void show()
    {
        cout << "var1=" << var1 << ", var2=" << var2 << endl;
    }
};

int main()
{
    PointerAssign pa;
    pa.assignIndirectly(37);
    pa.show();
    return 0;
}