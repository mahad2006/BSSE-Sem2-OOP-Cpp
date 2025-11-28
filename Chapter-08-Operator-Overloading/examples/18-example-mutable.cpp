#include <iostream>
#include <string>
using namespace std;

class ScrollBar
{
private:
    int size;
    mutable string owner; // mutable allows modification in const objects

public:
    // 1. Constructor
    ScrollBar(int sz, string own) : size(sz), owner(own) {}

    // 2. Destructor
    ~ScrollBar() {}

    // 3. Setters
    void setSize(int sz) { size = sz; }

    void setOwner(string own) const
    { // const function modifying mutable
        owner = own;
    }

    // 4. Getter (using cin)
    void getInput()
    {
        cout << "Enter new size: ";
        cin >> size;
        cout << "Enter new owner: ";
        cin >> owner;
    }

    // 5. Show
    void show() const
    {
        cout << size << ", " << owner << endl;
    }
};

int main()
{
    const ScrollBar sbar(60, "Window1");

    // sbar.setSize(100); // Error: can't call non-const on const object

    sbar.setOwner("Window2"); // OK because owner is mutable

    sbar.show();
    return 0;
}