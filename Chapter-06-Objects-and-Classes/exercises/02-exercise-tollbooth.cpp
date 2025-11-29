#include <iostream>
using namespace std;

class TollBooth
{
private:
    unsigned int totalCars;
    double totalCash;

public:
    // 1. Constructor
    TollBooth() : totalCars(0), totalCash(0.0) {}

    // 2. Destructor
    ~TollBooth() {}

    // 3. Setters (Specific logic for this problem)
    void payingCar()
    {
        totalCars++;
        totalCash += 0.50;
    }

    void nopayCar()
    {
        totalCars++;
    }

    // 4. Getter (using cin - essentially a menu here)
    void getInput()
    {
        char ch;
        cout << "Press 'p' for paying car, 'n' for non-paying, 'q' to quit: ";
        cin >> ch;
        if (ch == 'p')
            payingCar();
        if (ch == 'n')
            nopayCar();
    }

    // 5. Show
    void show() const
    {
        cout << "\nTotal Cars: " << totalCars;
        cout << "\nTotal Cash: " << totalCash << endl;
    }
};

int main()
{
    TollBooth booth;
    char ch = 'a';

    cout << "TollBooth System\n";
    while (ch != 'q')
    {
        cout << "\n'p' = paying, 'n' = nopay, 'q' = quit/display: ";
        cin >> ch;
        if (ch == 'p')
            booth.payingCar();
        else if (ch == 'n')
            booth.nopayCar();
    }

    booth.show();
    return 0;
}