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
    void setData(unsigned long n) { number = n; }
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

class Manager : public Employee
{
private:
    char title[LEN];
    double dues;

public:
    Manager() : dues(0.0) {}
    ~Manager() {}
    void getData()
    {
        Employee::getData();
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter dues: ";
        cin >> dues;
    }
    void putData() const
    {
        Employee::putData();
        cout << "\nTitle: " << title << "\nDues: " << dues;
    }
    void show() { putData(); }
};

class Executive : public Manager
{
private:
    double yearlyBonus;
    int shares;

public:
    // 1. Constructor
    Executive() : yearlyBonus(0.0), shares(0) {}

    // 2. Destructor
    ~Executive() {}

    // 3. Setter
    void setExec(double b, int s)
    {
        yearlyBonus = b;
        shares = s;
    }

    // 4. Getter
    void getData()
    {
        Manager::getData();
        cout << "Enter yearly bonus: ";
        cin >> yearlyBonus;
        cout << "Enter shares: ";
        cin >> shares;
    }

    // 5. Show
    void putData() const
    {
        Manager::putData();
        cout << "\nBonus: " << yearlyBonus << "\nShares: " << shares;
    }
    void show() { putData(); }
};

int main()
{
    Executive e;
    e.getData();
    e.show();
    cout << endl;
    return 0;
}