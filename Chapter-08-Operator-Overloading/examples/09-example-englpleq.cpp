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

    // Overloaded += operator
    void operator+=(Distance d2)
    {
        feet += d2.feet;
        inches += d2.inches;
        if (inches >= 12.0)
        {
            inches -= 12.0;
            feet++;
        }
    }
};

int main()
{
    Distance dist1;
    dist1.getDist();
    Distance dist2(11, 6.25);

    cout << "\ndist1 = ";
    dist1.show();
    cout << "\ndist2 = ";
    dist2.show();

    dist1 += dist2; // Add dist2 to dist1

    cout << "\nAfter addition, dist1 = ";
    dist1.show();
    cout << endl;
    return 0;
}