#include <iostream>
#include <cmath>
using namespace std;

class Polar
{
private:
    double radius;
    double angle; // radians

public:
    // 1. Constructor
    Polar() : radius(0.0), angle(0.0) {}
    Polar(double r, double a) : radius(r), angle(a) {}

    // 2. Destructor
    ~Polar() {}

    // 3. Setter
    void setPolar(double r, double a)
    {
        radius = r;
        angle = a;
    }

    // 4. Getter
    void getPolar()
    {
        cout << "Enter radius and angle (rads): ";
        cin >> radius >> angle;
    }

    // 5. Show
    void show() const
    {
        cout << "(" << radius << ", " << angle << ")";
    }

    // Operator + converts to rect, adds, converts back
    Polar operator+(Polar p2)
    {
        double x1 = radius * cos(angle);
        double y1 = radius * sin(angle);
        double x2 = p2.radius * cos(p2.angle);
        double y2 = p2.radius * sin(p2.angle);

        double xSum = x1 + x2;
        double ySum = y1 + y2;

        double r = sqrt(xSum * xSum + ySum * ySum);
        double a = atan2(ySum, xSum);
        return Polar(r, a);
    }
};

int main()
{
    Polar p1(10, 0.0);      // Point (10, 0)
    Polar p2(10, 1.570796); // Point (0, 10) roughly

    Polar p3 = p1 + p2;

    cout << "P1: ";
    p1.show();
    cout << endl;
    cout << "P2: ";
    p2.show();
    cout << endl;
    cout << "Sum: ";
    p3.show();
    cout << endl; // Should be ~ (14.14, 0.785)

    return 0;
}