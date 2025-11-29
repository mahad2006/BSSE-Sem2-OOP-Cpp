// 10-exercise-ship-class.cpp
#include <iostream>
using namespace std;

class Angle
{
private:
    int degrees;
    float minutes;
    char direction;

public:
    Angle() : degrees(0), minutes(0), direction('N') {}
    ~Angle() {}
    void getAngle()
    {
        cout << "  Degrees: ";
        cin >> degrees;
        cout << "  Minutes: ";
        cin >> minutes;
        cout << "  Direction: ";
        cin >> direction;
    }
    void show() const { cout << degrees << "\xF8" << minutes << "' " << direction; }
};

class Ship
{
private:
    static int count;
    int serialNumber;
    Angle latitude;
    Angle longitude;

public:
    // 1. Constructor
    Ship()
    {
        count++;
        serialNumber = count;
    }

    // 2. Destructor
    ~Ship() {}

    // 3. Setter (Simplified)
    void setShip(Angle lat, Angle lon)
    {
        latitude = lat;
        longitude = lon;
    }

    // 4. Getter (using cin)
    void getShip()
    {
        cout << "\nEnter Latitude:\n";
        latitude.getAngle();
        cout << "Enter Longitude:\n";
        longitude.getAngle();
    }

    // 5. Show
    void show() const
    {
        cout << "Ship Serial: " << serialNumber << endl;
        cout << "Position: ";
        latitude.show();
        cout << ", ";
        longitude.show();
        cout << endl;
    }
};

int Ship::count = 0;

int main()
{
    Ship s1, s2, s3;

    cout << "--- Enter Ship 1 Data ---";
    s1.getShip();
    cout << "--- Enter Ship 2 Data ---";
    s2.getShip();
    cout << "--- Enter Ship 3 Data ---";
    s3.getShip();

    cout << "\n--- Report ---\n";
    s1.show();
    s2.show();
    s3.show();

    return 0;
}