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

    // Overloaded < operator
    bool operator<(Distance d2) const
    {
        float bf1 = feet + inches / 12;
        float bf2 = d2.feet + d2.inches / 12;
        return (bf1 < bf2);
    }
};

int main()
{
    Distance dist1;
    dist1.getDist();
    Distance dist2(6, 2.5);

    cout << "\ndist1 = ";
    dist1.show();
    cout << "\ndist2 = ";
    dist2.show();

    if (dist1 < dist2)
        cout << "\ndist1 is less than dist2";
    else
        cout << "\ndist1 is greater than or equal to dist2";

    cout << endl;
    return 0;
}