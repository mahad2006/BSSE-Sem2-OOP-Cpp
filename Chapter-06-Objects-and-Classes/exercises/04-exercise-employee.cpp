#include <iostream>
using namespace std;

class Employee
{
private:
    int emp_num;
    float emp_comp;

public:
    // 1. Constructor
    Employee() : emp_num(0), emp_comp(0.0) {}

    // 2. Destructor
    ~Employee() {}

    // 3. Setter
    void setData(int num, float comp)
    {
        emp_num = num;
        emp_comp = comp;
    }

    // 4. Getter (using cin)
    void getData()
    {
        cout << "Enter Employee Number: ";
        cin >> emp_num;
        cout << "Enter Compensation: ";
        cin >> emp_comp;
    }

    // 5. Show
    void show() const
    {
        cout << "Employee Number: " << emp_num << endl;
        cout << "Compensation: $" << emp_comp << endl;
    }
};

int main()
{
    Employee e1, e2, e3;

    cout << "\n--- Employee 1 ---\n";
    e1.getData();
    cout << "\n--- Employee 2 ---\n";
    e2.getData();
    cout << "\n--- Employee 3 ---\n";
    e3.getData();

    cout << "\n--- Data Display ---\n";
    e1.show();
    e2.show();
    e3.show();

    return 0;
}