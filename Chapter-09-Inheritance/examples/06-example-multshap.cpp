#include <iostream>
using namespace std;

// Base Class
class Shape
{
protected:
    int xCo, yCo;
    string color;

public:
    // 1. Constructor
    Shape() : xCo(0), yCo(0), color("White") {}
    Shape(int x, int y, string c) : xCo(x), yCo(y), color(c) {}

    // 2. Destructor
    ~Shape() {}

    // 3. Setter
    void setShape(int x, int y, string c)
    {
        xCo = x;
        yCo = y;
        color = c;
    }

    // 4. Getter (cin)
    void getShape()
    {
        cout << "Enter x, y, color: ";
        cin >> xCo >> yCo >> color;
    }

    // 5. Show / Draw
    void draw() const
    {
        cout << "Shape at (" << xCo << "," << yCo << ") Color: " << color << endl;
    }
};

class Circle : public Shape
{
private:
    int radius;

public:
    Circle(int x, int y, int r, string c) : Shape(x, y, c), radius(r) {}
    ~Circle() {}

    void draw() const
    {
        cout << "Drawing Circle at (" << xCo << "," << yCo
             << ") Radius: " << radius << " Color: " << color << endl;
    }
};

class Rect : public Shape
{
private:
    int width, height;

public:
    Rect(int x, int y, int h, int w, string c) : Shape(x, y, c), width(w), height(h) {}
    ~Rect() {}

    void draw() const
    {
        cout << "Drawing Rect at (" << xCo << "," << yCo
             << ") W:" << width << " H:" << height << " Color: " << color << endl;
    }
};

class Tria : public Shape
{
private:
    int height;

public:
    Tria(int x, int y, int h, string c) : Shape(x, y, c), height(h) {}
    ~Tria() {}

    void draw() const
    {
        cout << "Drawing Triangle at (" << xCo << "," << yCo
             << ") Height: " << height << " Color: " << color << endl;
    }
};

int main()
{
    Circle c(40, 12, 5, "Blue");
    Rect r(12, 7, 10, 15, "Red");
    Tria t(60, 7, 11, "Green");

    c.draw();
    r.draw();
    t.draw();

    return 0;
}