#include <iostream>
#include <string>
using namespace std;

// Simulating graphics types for portability
typedef string color;
typedef string fstyle;

class Circle
{
protected:
    int xCo, yCo;
    int radius;
    color fillcolor;
    fstyle fillstyle;

public:
    // 1. Constructor
    Circle() : xCo(0), yCo(0), radius(0), fillcolor(""), fillstyle("") {}

    // 2. Destructor
    ~Circle() {}

    // 3. Setter
    void set(int x, int y, int r, color fc, fstyle fs)
    {
        xCo = x;
        yCo = y;
        radius = r;
        fillcolor = fc;
        fillstyle = fs;
    }

    // 4. Getter (cin)
    void getInput()
    {
        cout << "Enter x y r: ";
        cin >> xCo >> yCo >> radius;
        cout << "Enter color and style: ";
        cin >> fillcolor >> fillstyle;
    }

    // 5. Show (Draw simulation)
    void draw()
    {
        cout << "Drawing Circle at (" << xCo << "," << yCo << ") "
             << "Radius: " << radius << " Color: " << fillcolor
             << " Style: " << fillstyle << endl;
    }
};

int main()
{
    Circle c1, c2, c3;

    c1.set(15, 7, 5, "BLUE", "X_FILL");
    c2.set(41, 12, 7, "RED", "O_FILL");
    c3.set(65, 18, 4, "GREEN", "MEDIUM_FILL");

    c1.draw();
    c2.draw();
    c3.draw();

    return 0;
}