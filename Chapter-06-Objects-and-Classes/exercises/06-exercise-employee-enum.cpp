#include <iostream>
using namespace std;

enum etype
{
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

class Date
{
private:
    int month, day, year;

public:
    Date() : month(0), day(0), year(0) {}
    ~Date() {}
    void setDate(int m, int d, int y)
    {
        month = m;
        day = d;
        year = y;
    }
    void getDate()
    {
        char dummy;
        cout << "Enter date of hiring (MM/DD/YYYY): ";
        cin >> month >> dummy >> day >> dummy >> year;
    }
    void show() const { cout << month << "/" << day << "/" << year; }
};

class Employee
{
private:
    int emp_num;
    float emp_comp;
    Date dateOfHiring;
    etype jobTitle;

public:
    // 1. Constructor
    Employee() : emp_num(0), emp_comp(0.0) {}

    // 2. Destructor
    ~Employee() {}

    // 3. Setter (Simplified for brevity)
    void setInfo(int n, float c, etype j)
    {
        emp_num = n;
        emp_comp = c;
        jobTitle = j;
    }

    // 4. Getter (using cin)
    void getData()
    {
        cout << "Enter Employee Number: ";
        cin >> emp_num;
        cout << "Enter Compensation: ";
        cin >> emp_comp;
        dateOfHiring.getDate();

        char type;
        cout << "Enter job type (l, s, m, a, e, r): ";
        cin >> type;
        switch (type)
        {
        case 'l':
            jobTitle = laborer;
            break;
        case 's':
            jobTitle = secretary;
            break;
        case 'm':
            jobTitle = manager;
            break;
        case 'a':
            jobTitle = accountant;
            break;
        case 'e':
            jobTitle = executive;
            break;
        case 'r':
            jobTitle = researcher;
            break;
        default:
            jobTitle = laborer;
        }
    }

    // 5. Show
    void show() const
    {
        cout << "\nNumber: " << emp_num;
        cout << "\nCompensation: " << emp_comp;
        cout << "\nHired: ";
        dateOfHiring.show();
        cout << "\nJob: ";
        switch (jobTitle)
        {
        case laborer:
            cout << "Laborer";
            break;
        case secretary:
            cout << "Secretary";
            break;
        case manager:
            cout << "Manager";
            break;
        case accountant:
            cout << "Accountant";
            break;
        case executive:
            cout << "Executive";
            break;
        case researcher:
            cout << "Researcher";
            break;
        }
        cout << endl;
    }
};

int main()
{
    Employee e1, e2, e3;
    e1.getData();
    e2.getData();
    e3.getData();

    e1.show();
    e2.show();
    e3.show();
    return 0;
}