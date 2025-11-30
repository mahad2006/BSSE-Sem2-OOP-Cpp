#include <iostream>
using namespace std;

class Shape
{
protected:
    int xCo, yCo;

public:
    Shape() : xCo(0), yCo(0) {}
    Shape(int x, int y) : xCo(x), yCo(y) {}
    virtual ~Shape() {}

    void setShape(int x, int y)
    {
        xCo = x;
        yCo = y;
    }
    void getShape()
    {
        cout << "Enter x y: ";
        cin >> xCo >> yCo;
    }

    virtual void draw() = 0; // Pure virtual
    void show() {}           // dummy
};

class Ball : public Shape
{
private:
    int radius;

public:
    Ball(int x, int y, int r) : Shape(x, y), radius(r) {}
    ~Ball() {}
    void setR(int r) { radius = r; }
    void getR()
    {
        cout << "Enter r: ";
        cin >> radius;
    }

    void draw()
    {
        cout << "Drawing Ball at " << xCo << "," << yCo << " Radius " << radius << endl;
    }
};

class Rect : public Shape
{
private:
    int width, height;

public:
    Rect(int x, int y, int h, int w) : Shape(x, y), height(h), width(w) {}
    ~Rect() {}
    void setDim(int h, int w)
    {
        height = h;
        width = w;
    }
    void getDim() { cin >> height >> width; }

    void draw()
    {
        cout << "Drawing Rect at " << xCo << "," << yCo << " H:" << height << " W:" << width << endl;
    }
};

class Tria : public Shape
{
private:
    int height;

public:
    Tria(int x, int y, int h) : Shape(x, y), height(h) {}
    ~Tria() {}
    void setH(int h) { height = h; }
    void getH() { cin >> height; }

    void draw()
    {
        cout << "Drawing Triangle at " << xCo << "," << yCo << " Height " << height << endl;
    }
};

int main()
{
    Shape *pShapes[3];

    pShapes[0] = new Ball(40, 12, 5);
    pShapes[1] = new Rect(12, 7, 10, 15);
    pShapes[2] = new Tria(60, 7, 11);

    for (int j = 0; j < 3; j++)
        pShapes[j]->draw();

    for (int j = 0; j < 3; j++)
        delete pShapes[j];

    return 0;
}