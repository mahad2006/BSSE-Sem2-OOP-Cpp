#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    long number;

public:
    // 1. Constructor
    Employee() : name(""), number(0) {}

    // 2. Destructor
    ~Employee() {}

    // 3. Setter
    void setData(string n, long num)
    {
        name = n;
        number = num;
    }

    // 4. Getter (using cin)
    void getData()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }

    // 5. Show
    void putData() const
    {
        cout << "Name: " << name << "\tNumber: " << number << endl;
    }
};

int main()
{
    Employee emps[100];
    int count = 0;
    char choice;

    do
    {
        cout << "Employee " << count + 1 << endl;
        emps[count++].getData();
        cout << "Enter another (y/n)? ";
        cin >> choice;
    } while (choice == 'y' && count < 100);

    cout << "\n--- Employee Data ---\n";
    for (int i = 0; i < count; i++)
    {
        emps[i].putData();
    }

    return 0;
}