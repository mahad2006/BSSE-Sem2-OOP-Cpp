#include <iostream>
using namespace std;

enum posneg
{
    pos,
    neg
};

// Base Class
class Distance
{
protected:
    int feet;
    float inches;

public:
    // 1. Constructor
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) : feet(ft), inches(in) {}

    // 2. Destructor
    ~Distance() {}

    // 3. Setter
    void setDist(int ft, float in)
    {
        feet = ft;
        inches = in;
    }

    // 4. Getter
    void getDist()
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // 5. Show
    void showDist() const
    {
        cout << feet << "\'-" << inches << '\"';
    }
};

// Derived Class
class DistSign : public Distance
{
private:
    posneg sign;

public:
    // 1. Constructor
    DistSign() : Distance() { sign = pos; }
    DistSign(int ft, float in, posneg sg = pos) : Distance(ft, in) { sign = sg; }

    // 2. Destructor
    ~DistSign() {}

    // 3. Setter
    void setSign(posneg s) { sign = s; }

    // 4. Getter (Overriding)
    void getDist()
    {
        Distance::getDist(); // Call base
        char ch;
        cout << "Enter sign (+ or -): ";
        cin >> ch;
        sign = (ch == '+') ? pos : neg;
    }

    // 5. Show (Overriding)
    void showDist() const
    {
        cout << ((sign == pos) ? "(+)" : "(-)");
        Distance::showDist();
    }
};

int main()
{
    DistSign alpha;
    alpha.getDist();

    DistSign beta(11, 6.25);
    DistSign gamma(100, 5.5, neg);

    cout << "\nalpha = ";
    alpha.showDist();
    cout << "\nbeta = ";
    beta.showDist();
    cout << "\ngamma = ";
    gamma.showDist();
    cout << endl;

    return 0;
}