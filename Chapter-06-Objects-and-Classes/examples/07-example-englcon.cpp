#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    // 1. Constructor (Overloaded)
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) : feet(ft), inches(in) {}

    // 2. Destructor
    ~Distance() {}

    // 3. Setter
    void add_dist(Distance d2, Distance d3)
    {
        inches = d2.inches + d3.inches;
        feet = 0;
        if (inches >= 12.0)
        {
            inches -= 12.0;
            feet++;
        }
        feet += d2.feet + d3.feet;
    }

    // 4. Getter (cin)
    void getDist()
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // 5. Show
    void showDist() const
    {
        cout << feet << "\'-" << inches << '\"';
    }
};

int main()
{
    Distance dist1, dist3;
    Distance dist2(11, 6.25);

    dist1.getDist();

    // Add dist1 and dist2, result in dist3
    dist3.add_dist(dist1, dist2);

    cout << "\ndist1 = ";
    dist1.showDist();
    cout << "\ndist2 = ";
    dist2.showDist();
    cout << "\ndist3 = ";
    dist3.showDist();
    cout << endl;

    return 0;
}