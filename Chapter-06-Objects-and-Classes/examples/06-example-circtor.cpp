#include <iostream>
#include <string>
using namespace std;

typedef string color;
typedef string fstyle;

class Circle
{
private:
    int xCo, yCo;
    int radius;
    color fillcolor;
    fstyle fillstyle;

public:
    // 1. Constructor
    Circle(int x, int y, int r, color fc, fstyle fs)
        : xCo(x), yCo(y), radius(r), fillcolor(fc), fillstyle(fs) {}

    // 2. Destructor
    ~Circle() {}

    // 3. Setter
    void set(int x, int y, int r)
    {
        xCo = x;
        yCo = y;
        radius = r;
    }

    // 4. Getter (cin)
    void getInput()
    {
        cout << "Enter x y r: ";
        cin >> xCo >> yCo >> radius;
    }

    // 5. Show (Draw)
    void draw()
    {
        cout << "Drawing Circle at (" << xCo << "," << yCo << ") "
             << "Radius: " << radius << " Color: " << fillcolor << endl;
    }
};

int main()
{
    Circle c1(15, 7, 5, "BLUE", "X_FILL");
    Circle c2(41, 12, 7, "RED", "O_FILL");
    Circle c3(65, 18, 4, "GREEN", "MEDIUM_FILL");

    c1.draw();
    c2.draw();
    c3.draw();

    return 0;
}