#include <iostream>
#include <string>
using namespace std;

// Base 1
class Type
{
private:
    string dimensions;
    string grade;

public:
    Type() : dimensions("N/A"), grade("N/A") {}
    Type(string di, string gr) : dimensions(di), grade(gr) {}
    ~Type() {}

    void getType()
    {
        cout << "Enter dim: ";
        cin >> dimensions;
        cout << "Enter grade: ";
        cin >> grade;
    }

    void showType() const
    {
        cout << "\nDim: " << dimensions << "\nGrade: " << grade;
    }

    // Dummy setter
    void setT(string d, string g)
    {
        dimensions = d;
        grade = g;
    }
};

// Base 2
class Distance
{
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) : feet(ft), inches(in) {}
    ~Distance() {}

    void getDist()
    {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    void showDist() const
    {
        cout << feet << "\'-" << inches << '\"';
    }

    void setD(int f, float i)
    {
        feet = f;
        inches = i;
    }
};

// Derived
class Lumber : public Type, public Distance
{
private:
    int quantity;
    double price;

public:
    Lumber() : Type(), Distance(), quantity(0), price(0.0) {}

    Lumber(string di, string gr, int ft, float in, int qu, float prc) : Type(di, gr), Distance(ft, in), quantity(qu), price(prc) {}

    ~Lumber() {}

    void getLumber()
    {
        Type::getType();
        Distance::getDist();
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price: ";
        cin >> price;
    }

    void showLumber() const
    {
        Type::showType();
        cout << "\nLength: ";
        Distance::showDist();
        cout << "\nPrice for " << quantity << " pieces: $" << price * quantity;
    }

    void setAll() {} // dummy
};

int main()
{
    Lumber siding;
    cout << "\nEnter siding data:\n";
    siding.getLumber();

    Lumber studs("2x4", "const", 8, 0.0, 200, 4.45);

    cout << "\nSiding";
    siding.showLumber();
    cout << "\nStuds";
    studs.showLumber();
    cout << endl;
    return 0;
}