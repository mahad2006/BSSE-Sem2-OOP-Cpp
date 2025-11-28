#include <iostream>
using namespace std;

class Part
{
private:
    int modelNumber;
    int partNumber;
    float cost;

public:
    // 1. Constructor
    Part()
    {
        modelNumber = 0;
        partNumber = 0;
        cost = 0.0;
    }

    // 2. Destructor
    ~Part() {}

    // 3. Setter
    void setPart(int mn, int pn, float c)
    {
        modelNumber = mn;
        partNumber = pn;
        cost = c;
    }

    // 4. Getter (using cin)
    void getPart()
    {
        cout << "Enter Model Number: ";
        cin >> modelNumber;
        cout << "Enter Part Number: ";
        cin >> partNumber;
        cout << "Enter Cost: ";
        cin >> cost;
    }

    // 5. Show
    void show() const
    {
        cout << "Model " << modelNumber;
        cout << ", Part " << partNumber;
        cout << ", Cost $" << cost << endl;
    }
};

int main()
{
    Part p1;
    p1.setPart(6244, 373, 217.55);
    p1.show();
    return 0;
}