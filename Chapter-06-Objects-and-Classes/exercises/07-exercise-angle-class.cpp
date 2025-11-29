// 07-exercise-angle-class.cpp
#include <iostream>
using namespace std;

class Angle
{
private:
    int degrees;
    float minutes;
    char direction;

public:
    // 1. Constructor
    Angle() : degrees(0), minutes(0.0), direction('N') {}
    Angle(int d, float m, char dir) : degrees(d), minutes(m), direction(dir) {}

    // 2. Destructor
    ~Angle() {}

    // 3. Setter
    void setAngle(int d, float m, char dir)
    {
        degrees = d;
        minutes = m;
        direction = dir;
    }

    // 4. Getter (using cin)
    void getAngle()
    {
        cout << "Enter degrees: ";
        cin >> degrees;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter direction (N/S/E/W): ";
        cin >> direction;
    }

    // 5. Show
    void show() const
    {
        cout << degrees << "\xF8" << minutes << "' " << direction;
    }
};

int main()
{
    Angle lat(17, 31.5, 'S');
    cout << "Initialized Latitude: ";
    lat.show();
    cout << endl;

    Angle userAngle;
    cout << "\n--- Input a custom angle ---\n";
    userAngle.getAngle();

    cout << "You entered: ";
    userAngle.show();
    cout << endl;

    return 0;
}