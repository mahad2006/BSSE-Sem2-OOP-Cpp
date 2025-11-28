#include <iostream>
using namespace std;

class Distance
{
private:
    const float MTF; // Meters to feet factor
    int feet;
    float inches;

public:
    // 1. Constructor (No args)
    Distance() : feet(0), inches(0.0), MTF(3.280833F) {}

    // Constructor (1 arg) - Conversion from float (meters)
    Distance(float meters) : MTF(3.280833F)
    {
        float fltfeet = MTF * meters;
        feet = int(fltfeet);
        inches = 12 * (fltfeet - feet);
    }

    // Constructor (2 args)
    Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) {}

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

    // Conversion Operator: Distance to float (meters)
    operator float() const
    {
        float fracfeet = inches / 12;
        fracfeet += static_cast<float>(feet);
        return fracfeet / MTF;
    }
};

int main()
{
    // float to Distance
    Distance dist1 = 2.35F;
    cout << "\ndist1 = ";
    dist1.show();

    // Distance to float
    float mtrs = static_cast<float>(dist1);
    cout << "\ndist1 = " << mtrs << " meters\n";

    Distance dist2(5, 10.25);
    mtrs = dist2; // Implicit conversion
    cout << "\ndist2 = " << mtrs << " meters\n";

    return 0;
}