#include <iostream>
using namespace std;

const int LEN = 80;

class Employee
{
private:
    char name[LEN];
    unsigned long number;

public:
    Employee() : number(0) {}
    ~Employee() {}
    void setEmp(unsigned long n) { number = n; }
    void getData()
    {
        cout << "\nEnter name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }
    void putData() const
    {
        cout << "\nName: " << name << "\nNumber: " << number;
    }
    void show() { putData(); }
};

enum Period
{
    HOURLY,
    WEEKLY,
    MONTHLY
};

class Employee2 : public Employee
{
private:
    double compensation;
    Period payPeriod;

public:
    // 1. Constructor
    Employee2() : compensation(0.0), payPeriod(HOURLY) {}

    // 2. Destructor
    ~Employee2() {}

    // 3. Setter
    void setComp(double c, Period p)
    {
        compensation = c;
        payPeriod = p;
    }

    // 4. Getter
    void getData()
    {
        Employee::getData();
        cout << "Enter compensation: ";
        cin >> compensation;
        char ch;
        cout << "Enter period (h/w/m): ";
        cin >> ch;
        if (ch == 'h')
            payPeriod = HOURLY;
        else if (ch == 'w')
            payPeriod = WEEKLY;
        else
            payPeriod = MONTHLY;
    }

    // 5. Show
    void putData() const
    {
        Employee::putData();
        cout << "\nCompensation: $" << compensation;
        cout << "\nPeriod: ";
        if (payPeriod == HOURLY)
            cout << "Hourly";
        else if (payPeriod == WEEKLY)
            cout << "Weekly";
        else
            cout << "Monthly";
    }
    void show() { putData(); }
};

int main()
{
    Employee2 e2;
    e2.getData();
    e2.show();
    cout << endl;
    return 0;
}