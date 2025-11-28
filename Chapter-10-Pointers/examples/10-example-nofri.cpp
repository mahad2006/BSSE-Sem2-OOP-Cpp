#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0) {}
    Distance(float fltfeet)
    { // Conversion ctor
        feet = int(fltfeet);
        inches = 12 * (fltfeet - feet);
    }
    ~Distance() {}
    void setDist(int f, float i)
    {
        feet = f;
        inches = i;
    }
    void getDist() { cin >> feet >> inches; }
    void show() const { cout << feet << "\'-" << inches << '\"'; }

    Distance operator+(Distance d2)
    {
        int f = feet + d2.feet;
        float i = inches + d2.inches;
        if (i >= 12.0)
        {
            i -= 12.0;
            f++;
        }
        return Distance(f + i / 12.0); // Simplified return logic
    }
};

int main()
{
    Distance d1 = 2.5;
    Distance d2 = 1.25;
    Distance d3;

    d3 = d1 + 10.0; // OK
    cout << "d3: ";
    d3.show();
    cout << endl;

    // d3 = 10.0 + d1; // ERROR: Can't do this without friend
    return 0;
}