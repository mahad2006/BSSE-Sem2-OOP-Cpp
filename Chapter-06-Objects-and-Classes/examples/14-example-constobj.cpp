#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    // 1. Constructor
    Distance(int ft, float in) : feet(ft), inches(in) {}

    // 2. Destructor
    ~Distance() {}

    // 3. Setter (Non-const)
    void getDist()
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // 4. Getter (Non-const placeholder)
    void dummyGet()
    {
        int x;
        cin >> x;
    }

    // 5. Show (Const function)
    void showDist() const
    {
        cout << feet << "\'-" << inches << '\"';
    }
};

int main()
{
    const Distance football(300, 0);

    // football.getDist(); // ERROR: getDist() is non-const

    cout << "football = ";
    football.showDist(); // OK: showDist() is const
    cout << endl;

    return 0;
}