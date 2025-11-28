#include <iostream>
using namespace std;

class PointerPasser
{
private:
    double val;

public:
    // 1. Constructor
    PointerPasser() : val(10.0) {}

    // 2. Destructor
    ~PointerPasser() {}

    // 3. Setter (via pointer logic)
    void centimize(double *ptrd)
    {
        *ptrd *= 2.54;
    }

    // 4. Getter
    void getInput()
    {
        cout << "Enter inches: ";
        cin >> val;
    }

    // 5. Show
    void show()
    {
        cout << "Inches: " << val << endl;
        centimize(&val); // Pass address
        cout << "Centimeters: " << val << endl;
    }
};

int main()
{
    PointerPasser pp;
    pp.show();
    return 0;
}