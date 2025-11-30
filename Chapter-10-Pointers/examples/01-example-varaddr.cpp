#include <iostream>
using namespace std;

class AddressDemo
{
private:
    int var1, var2, var3;

public:
    // 1. Constructor
    AddressDemo() : var1(0), var2(0), var3(0) {}

    // 2. Destructor
    ~AddressDemo() {}

    // 3. Setter
    void setVars(int v1, int v2, int v3)
    {
        var1 = v1;
        var2 = v2;
        var3 = v3;
    }

    // 4. Getter (cin)
    void getVars()
    {
        cout << "Enter 3 integers: ";
        cin >> var1 >> var2 >> var3;
    }

    // 5. Show
    void show()
    {
        cout << "Value: " << var1 << " Address: " << &var1 << endl;
        cout << "Value: " << var2 << " Address: " << &var2 << endl;
        cout << "Value: " << var3 << " Address: " << &var3 << endl;
    }
};

int main()
{
    AddressDemo ad;
    ad.setVars(11, 22, 33);
    ad.show();
    return 0;
}