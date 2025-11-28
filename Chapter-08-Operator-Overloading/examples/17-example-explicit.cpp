#include <iostream>
using namespace std;

class Distance
{
private:
    const float MTF;
    int feet;
    float inches;

public:
    // 1. Constructor
    Distance() : feet(0), inches(0.0), MTF(3.280833F) {}

    // EXPLICIT Constructor
    explicit Distance(float meters) : MTF(3.280833F)
    {
        float fltfeet = MTF * meters;
        feet = int(fltfeet);
        inches = 12 * (fltfeet - feet);
    }

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
        cout << "Enter feet/inches: ";
        cin >> feet >> inches;
    }

    // 5. Show
    void show() const
    {
        cout << feet << "\'-" << inches << '\"';
    }
};

void fancyDist(Distance d)
{
    cout << "(in feet and inches) = ";
    d.show();
    cout << endl;
}

int main()
{
    // Explicit call works
    Distance dist1(2.35F);
    cout << "\ndist1 = ";
    dist1.show();

    float mtrs = 3.0F;

    // fancyDist(mtrs); // ERROR: Implicit conversion prevented by 'explicit'

    // Must cast explicitly or construct object
    fancyDist(Distance(mtrs));

    return 0;
}