#include <iostream>
using namespace std;

class Sales
{
private:
    static const int SIZE = 6;
    double sales[SIZE];

public:
    // 1. Constructor
    Sales()
    {
        for (int i = 0; i < SIZE; i++)
            sales[i] = 0.0;
    }

    // 2. Destructor
    ~Sales() {}

    // 3. Setter
    void setSale(int day, double amount)
    {
        if (day >= 0 && day < SIZE)
            sales[day] = amount;
    }

    // 4. Getter (using cin)
    void getSalesInput()
    {
        cout << "Enter widget sales for 6 days:\n";
        for (int j = 0; j < SIZE; j++)
        {
            cout << "Day " << j + 1 << ": ";
            cin >> sales[j];
        }
    }

    // 5. Show
    void showAverage() const
    {
        double total = 0;
        for (int j = 0; j < SIZE; j++)
            total += sales[j];
        double average = total / SIZE;
        cout << "Average = " << average << endl;
    }

    // Required Show function
    void show() { showAverage(); }
};

int main()
{
    Sales s;
    s.getSalesInput();
    s.show();
    return 0;
}