#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    // 1. Constructor
    Distance() : feet(0), inches(0.0) {}

    // Constructor with args (acting as setter helper)
    Distance(int ft, float in) : feet(ft), inches(in) {}

    // 2. Destructor
    ~Distance() {}

    // 3. Setter
    void setDist(int ft, float in)
    {
        feet = ft;
        inches = in;
    }

    // 4. Getter (using cin)
    void getDist()
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // 5. Show
    void show() const
    {
        cout << feet << "\'-" << inches << '\"';
    }
};

int main()
{
    Distance d1, d2;
    d1.setDist(11, 6.25);
    d2.getDist();

    cout << "\ndist1 = ";
    d1.show();
    cout << "\ndist2 = ";
    d2.show();
    cout << endl;
    return 0;
}