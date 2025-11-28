#include <iostream>
using namespace std;

const int LEN = 80;

// Base 1: Student
class Student
{
private:
    char school[LEN];
    char degree[LEN];

public:
    Student() {}
    ~Student() {}

    void getEdu()
    {
        cout << "Enter school: ";
        cin >> school;
        cout << "Enter degree: ";
        cin >> degree;
    }

    void putEdu() const
    {
        cout << "\nSchool: " << school;
        cout << "\nDegree: " << degree;
    }

    // Required dummy functions
    void setDummy() {}
    void show() {}
};

// Base 2: Employee
class Employee
{
private:
    char name[LEN];
    unsigned long number;

public:
    Employee() : number(0) {}
    ~Employee() {}

    void getData()
    {
        cout << "\nEnter last name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }

    void putData() const
    {
        cout << "\nName: " << name << "\nNumber: " << number;
    }

    void setDummy() {}
    void show() {}
};

// Derived: Manager
class Manager : private Employee, private Student
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
        cout << "Enter golf dues: ";
        cin >> dues;
        Student::getEdu();
    }

    void putData() const
    {
        Employee::putData();
        cout << "\nTitle: " << title;
        cout << "\nGolf dues: " << dues;
        Student::putEdu();
    }

    // Required dummy
    void setDummy() {}
    void show() {}
};

int main()
{
    Manager m1;
    cout << "Enter data for manager 1";
    m1.getData();

    cout << "\nData on manager 1";
    m1.putData();
    cout << endl;
    return 0;
}