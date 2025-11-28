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
        cout << "\nEnter last name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }
    void putData() const
    {
        cout << "\nName: " << name << "\nNumber: " << number;
    }
};

class Laborer : public Employee
{
public:
    Laborer() {}
    ~Laborer() {}
    // Uses base methods
};

class Foreman : public Laborer
{
private:
    float quotas; // percent of quotas met
public:
    Foreman() : quotas(0.0) {}
    ~Foreman() {}

    void getData()
    {
        Laborer::getData();
        cout << "Enter quotas: ";
        cin >> quotas;
    }

    void putData() const
    {
        Laborer::putData();
        cout << "\nQuotas: " << quotas;
    }
};

int main()
{
    Laborer l1;
    Foreman f1;

    cout << "\nEnter data for laborer 1";
    l1.getData();
    cout << "\nEnter data for foreman 1";
    f1.getData();

    cout << "\nData on laborer 1";
    l1.putData();
    cout << "\nData on foreman 1";
    f1.putData();
    cout << endl;
    return 0;
}