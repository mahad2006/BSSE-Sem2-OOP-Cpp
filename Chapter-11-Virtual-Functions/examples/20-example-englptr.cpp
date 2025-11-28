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

    // 2. Destructor
    ~Distance() {}

    // 3. Setter
    void setDist(int f, float i)
    {
        feet = f;
        inches = i;
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
    void showDist()
    {
        cout << feet << "\'-" << inches << '\"';
    }
};

int main()
{
    Distance dist;
    dist.getDist();
    dist.showDist();

    Distance *distptr;
    distptr = new Distance;
    distptr->getDist(); // Access via pointer
    distptr->showDist();
    cout << endl;

    delete distptr;
    return 0;
}