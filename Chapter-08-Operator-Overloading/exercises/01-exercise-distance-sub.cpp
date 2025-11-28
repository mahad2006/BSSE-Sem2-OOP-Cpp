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

    // Overloaded - operator
    Distance operator-(Distance d2) const
    {
        int f = feet - d2.feet;
        float i = inches - d2.inches;
        if (i < 0)
        {
            i += 12.0;
            f--;
        }
        return Distance(f, i);
    }
};

int main()
{
    Distance dist1, dist2, dist3;

    cout << "Enter Distance 1:";
    dist1.getDist();

    cout << "Enter Distance 2 (smaller than D1):";
    dist2.getDist();

    dist3 = dist1 - dist2;

    cout << "\nResult (D1 - D2) = ";
    dist3.show();
    cout << endl;

    return 0;
}