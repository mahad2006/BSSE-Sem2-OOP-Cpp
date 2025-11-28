#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0) {}
    ~Distance() {}
    void setDist(int f, float i)
    {
        feet = f;
        inches = i;
    }
    void getDist()
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void showDist() { cout << feet << "\'-" << inches << '\"'; }
    void show() { showDist(); }
};

int main()
{
    // Reference alias to dynamic object
    Distance &dist = *(new Distance);

    dist.getDist();
    dist.showDist();
    cout << endl;

    delete &dist; // Must delete address
    return 0;
}