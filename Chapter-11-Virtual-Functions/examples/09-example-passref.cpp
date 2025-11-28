#include <iostream>
using namespace std;

class ReferencePasser
{
private:
    double val;

public:
    // 1. Constructor
    ReferencePasser() : val(10.0) {}

    // 2. Destructor
    ~ReferencePasser() {}

    // 3. Setter (via logic function)
    void centimize(double &v)
    {
        v *= 2.54;
    }

    // 4. Getter (cin)
    void getInput()
    {
        cout << "Enter inches: ";
        cin >> val;
    }

    // 5. Show
    void show()
    {
        cout << "Inches: " << val << endl;
        centimize(val); // Pass by reference
        cout << "Centimeters: " << val << endl;
    }
};

int main()
{
    ReferencePasser rp;
    rp.show();
    return 0;
}