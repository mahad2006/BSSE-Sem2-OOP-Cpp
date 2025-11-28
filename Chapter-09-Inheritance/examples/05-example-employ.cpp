#include <iostream>
using namespace std;

const int LEN = 80;

// Base Class
class Employee
{
private:
    char name[LEN];
    unsigned long number;

public:
    // 1. Constructor
    Employee() : number(0) {}

    // 2. Destructor
    ~Employee() {}

    // 3. Setter (not used, direct input via getter)
    void setData(unsigned long n) { number = n; }

    // 4. Getter
    void getData()
    {
        cout << "\nEnter last name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }

    // 5. Show
    void putData() const
    {
        cout << "\nName: " << name;
        cout << "\nNumber: " << number;
    }
};

// Derived: Manager
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
        cout << "Enter golf club dues: ";
        cin >> dues;
    }

    void putData() const
    {
        Employee::putData();
        cout << "\nTitle: " << title;
        cout << "\nGolf club dues: " << dues;
    }
};

// Derived: Scientist
class Scientist : public Employee
{
private:
    int pubs;

public:
    Scientist() : pubs(0) {}
    ~Scientist() {}

    void getData()
    {
        Employee::getData();
        cout << "Enter number of pubs: ";
        cin >> pubs;
    }

    void putData() const
    {
        Employee::putData();
        cout << "\nNumber of publications: " << pubs;
    }
};

// Derived: Laborer
class Laborer : public Employee
{
public:
    Laborer() {}
    ~Laborer() {}
    // Uses base getData/putData
};

int main()
{
    Manager m1;
    Scientist s1;
    Laborer l1;

    cout << "\nEnter data for Manager 1";
    m1.getData();
    cout << "\nEnter data for Scientist 1";
    s1.getData();
    cout << "\nEnter data for Laborer 1";
    l1.getData();

    cout << "\nData on Manager 1";
    m1.putData();
    cout << "\nData on Scientist 1";
    s1.putData();
    cout << "\nData on Laborer 1";
    l1.putData();
    cout << endl;

    return 0;
}