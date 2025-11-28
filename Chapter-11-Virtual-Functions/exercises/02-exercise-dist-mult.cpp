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
    Distance(float flt)
    { // Conversion ctor
        feet = int(flt);
        inches = 12 * (flt - feet);
    }
    Distance(int f, float i) : feet(f), inches(i) {}

    // 2. Destructor
    ~Distance() {}

    // 3. Setter
    void setDist(int f, float i)
    {
        feet = f;
        inches = i;
    }

    // 4. Getter
    void getDist()
    {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // 5. Show
    void show() const { cout << feet << "\'-" << inches << '\"'; }

    // Friend operator *
    friend Distance operator*(Distance d1, Distance d2);
};

Distance operator*(Distance d1, Distance d2)
{
    float f1 = d1.feet + d1.inches / 12.0;
    float f2 = d2.feet + d2.inches / 12.0;
    float res = f1 * f2;  // Square feet? Logic is abstract multiplication
    return Distance(res); // Use conversion ctor
}

int main()
{
    Distance d1;
    d1.getDist();

    Distance d2(10.0); // 10 feet

    Distance d3 = d1 * d2; // 7.5 * dist2 logic check

    cout << "D1: ";
    d1.show();
    cout << endl;
    cout << "D2: ";
    d2.show();
    cout << endl;
    cout << "D1 * D2: ";
    d3.show();
    cout << endl;

    return 0;
}