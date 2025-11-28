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

    // Overloaded + operator
    Distance operator+(Distance d2) const
    {
        int f = feet + d2.feet;
        float i = inches + d2.inches;
        if (i >= 12.0)
        {
            i -= 12.0;
            f++;
        }
        return Distance(f, i);
    }
};

int main()
{
    Distance dist1, dist3, dist4;
    dist1.getDist();

    Distance dist2(11, 6.25);

    dist3 = dist1 + dist2;
    dist4 = dist1 + dist2 + dist3;

    cout << "dist1 = ";
    dist1.show();
    cout << endl;
    cout << "dist2 = ";
    dist2.show();
    cout << endl;
    cout << "dist3 = ";
    dist3.show();
    cout << endl;
    cout << "dist4 = ";
    dist4.show();
    cout << endl;

    return 0;
}