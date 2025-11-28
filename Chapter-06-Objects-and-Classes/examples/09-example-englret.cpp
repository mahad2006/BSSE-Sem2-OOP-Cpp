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

    // 3. Setter / Helper to add
    Distance add_dist(Distance d2)
    {
        Distance temp;
        temp.inches = inches + d2.inches;
        if (temp.inches >= 12.0)
        {
            temp.inches -= 12.0;
            temp.feet = 1;
        }
        temp.feet += feet + d2.feet;
        return temp;
    }

    // 4. Getter
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

    // Returns object which is assigned to dist3
    dist3 = dist1.add_dist(dist2);

    cout << "\ndist1 = ";
    dist1.showDist();
    cout << "\ndist2 = ";
    dist2.showDist();
    cout << "\ndist3 = ";
    dist3.showDist();
    cout << endl;

    return 0;
}