#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string school;
    string degree;

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
        cout << "\nSchool: " << school << "\nDegree: " << degree;
    }
    void set() {}
    void show() {}
};

class Employee
{
private:
    string name;
    unsigned long number;

public:
    Employee() {}
    ~Employee() {}
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
    void set() {}
    void show() {}
};

// Manager HAS-A Employee and HAS-A Student
class Manager
{
private:
    string title;
    double dues;
    Employee emp; // Containership
    Student stu;  // Containership
public:
    Manager() {}
    ~Manager() {}

    void getData()
    {
        emp.getData();
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter dues: ";
        cin >> dues;
        stu.getEdu();
    }

    void putData() const
    {
        emp.putData();
        cout << "\nTitle: " << title;
        cout << "\nDues: " << dues;
        stu.putEdu();
    }

    void set() {}
    void show() {}
};

int main()
{
    Manager m1;
    cout << "Enter data for Manager 1";
    m1.getData();

    cout << "\nData on Manager 1";
    m1.putData();
    cout << endl;
    return 0;
}