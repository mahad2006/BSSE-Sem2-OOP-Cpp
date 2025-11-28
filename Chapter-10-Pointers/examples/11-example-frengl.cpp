#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0) {}
    Distance(float fltfeet)
    {
        feet = int(fltfeet);
        inches = 12 * (fltfeet - feet);
    }
    ~Distance() {}
    void setDist(int f, float i)
    {
        feet = f;
        inches = i;
    }
    void getDist() { cin >> feet >> inches; }
    void show() const { cout << feet << "\'-" << inches << '\"'; }

    friend Distance operator+(Distance, Distance);
};

Distance operator+(Distance d1, Distance d2)
{
    int f = d1.feet + d2.feet;
    float i = d1.inches + d2.inches;
    if (i >= 12.0)
    {
        i -= 12.0;
        f++;
    }
    return Distance(f + i / 12.0); // Reusing float constructor logic approximation
}

int main()
{
    Distance d1 = 2.5;
    Distance d3;

    d3 = 10.0 + d1; // Works because of friend!
    cout << "d3: ";
    d3.show();
    cout << endl;
    return 0;
}