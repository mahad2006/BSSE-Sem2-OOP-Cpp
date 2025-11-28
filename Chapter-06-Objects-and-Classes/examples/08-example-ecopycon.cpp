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
    Distance dist1(11, 6.25);

    // Default Copy Constructor used here
    Distance dist2(dist1);
    Distance dist3 = dist1;

    cout << "\ndist1 = ";
    dist1.showDist();
    cout << "\ndist2 = ";
    dist2.showDist();
    cout << "\ndist3 = ";
    dist3.showDist();
    cout << endl;

    return 0;
}