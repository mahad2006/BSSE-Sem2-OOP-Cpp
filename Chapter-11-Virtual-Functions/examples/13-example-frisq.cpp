#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0) {}
    Distance(int f, float i) : feet(f), inches(i) {}
    ~Distance() {}
    void set(int f, float i)
    {
        feet = f;
        inches = i;
    }
    void get() { cin >> feet >> inches; }
    void show() { cout << feet << "-" << inches; }

    friend float square(Distance);
};

float square(Distance d)
{
    float fltfeet = d.feet + d.inches / 12;
    return fltfeet * fltfeet;
}

int main()
{
    Distance dist(3, 6.0);
    float sqft = square(dist);

    cout << "Square: " << sqft << endl;
    return 0;
}