#include <iostream>
using namespace std;

class AClass
{
private:
    int alpha;

public:
    // 1. Constructor
    AClass() : alpha(0) {}

    // 2. Destructor
    ~AClass() {}

    // 3. Setter (Non-const)
    void setAlpha(int a)
    {
        alpha = a;
    }

    // 4. Getter (cin)
    void getAlpha()
    {
        cout << "Enter alpha: ";
        cin >> alpha;
    }

    // 5. Show (Const function)
    void showAlpha() const
    {
        cout << "Alpha is " << alpha << endl;
    }

    // Const function logic check
    void conFunc() const
    {
        // alpha = 99; // ERROR: Can't modify in const func
        cout << "Inside const function." << endl;
    }
};

int main()
{
    AClass a;
    a.setAlpha(10);
    a.showAlpha();
    a.conFunc();
    return 0;
}