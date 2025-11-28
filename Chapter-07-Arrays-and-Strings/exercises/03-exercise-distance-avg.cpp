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
    Distance(int f, float i) : feet(f), inches(i) {}

    // 2. Destructor
    ~Distance() {}

    // 3. Setter
    void setDist(int f, float i)
    {
        feet = f;
        inches = i;
    }

    // 4. Getter (using cin)
    void getDist()
    {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // 5. Show
    void showDist() const
    {
        cout << feet << "\'-" << inches << '\"';
    }

    // Helper logic for averaging
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

    void div_dist(Distance d2, int divisor)
    {
        float fltFeet = d2.feet + d2.inches / 12.0;
        fltFeet /= divisor;
        feet = int(fltFeet);
        inches = (fltFeet - feet) * 12.0;
    }
};

int main()
{
    Distance distArr[100];
    Distance total(0, 0.0), average;
    int count = 0;
    char ch;

    do
    {
        cout << "Enter Distance " << count + 1 << endl;
        distArr[count++].getDist();
        cout << "Enter another (y/n)? ";
        cin >> ch;
    } while (ch != 'n' && count < 100);

    for (int i = 0; i < count; i++)
    {
        total.add_dist(total, distArr[i]);
    }

    average.div_dist(total, count);

    cout << "\nAverage Distance is: ";
    average.showDist();
    cout << endl;

    return 0;
}