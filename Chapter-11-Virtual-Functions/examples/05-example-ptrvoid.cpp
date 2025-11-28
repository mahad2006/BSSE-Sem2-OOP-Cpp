#include <iostream>
using namespace std;

class VoidPtrDemo
{
private:
    int intvar;
    float flovar;
    int *ptrint;
    float *ptrflo;
    void *ptrvoid;

public:
    // 1. Constructor
    VoidPtrDemo() : intvar(0), flovar(0.0) {}

    // 2. Destructor
    ~VoidPtrDemo() {}

    // 3. Setter
    void setValues(int i, float f)
    {
        intvar = i;
        flovar = f;
        ptrint = &intvar;
        ptrflo = &flovar;
    }

    // 4. Getter (cin)
    void getValues()
    {
        cout << "Enter int: ";
        cin >> intvar;
        cout << "Enter float: ";
        cin >> flovar;
    }

    // 5. Show
    void show()
    {
        ptrvoid = &intvar; // int* to void*
        cout << "Void ptr to int addr: " << ptrvoid << endl;
        ptrvoid = &flovar; // float* to void*
        cout << "Void ptr to float addr: " << ptrvoid << endl;
    }
};

int main()
{
    VoidPtrDemo vp;
    vp.setValues(10, 3.14);
    vp.show();
    return 0;
}