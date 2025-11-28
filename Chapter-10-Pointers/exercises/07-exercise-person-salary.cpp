#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    float salary;

public:
    void setData()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
    }
    void printData() const
    {
        cout << name << " ($" << salary << ")" << endl;
    }
    float getSalary() const { return salary; }
};

class SalarySorter
{
private:
    Person *ptrs[100];
    int n;

public:
    // 1. Constructor
    SalarySorter() : n(0) {}

    // 2. Destructor
    ~SalarySorter()
    {
        for (int i = 0; i < n; i++)
            delete ptrs[i];
    }

    // 3. Setter (Sort Logic)
    void bsort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (ptrs[i]->getSalary() > ptrs[j]->getSalary())
                {
                    Person *temp = ptrs[i];
                    ptrs[i] = ptrs[j];
                    ptrs[j] = temp;
                }
            }
        }
    }

    // 4. Getter (Add persons)
    void getInputs()
    {
        char ch;
        do
        {
            ptrs[n] = new Person;
            ptrs[n]->setData();
            n++;
            cout << "Enter another (y/n)? ";
            cin >> ch;
        } while (ch == 'y');
    }

    // 5. Show
    void show() const
    {
        cout << "\n--- Sorted by Salary ---\n";
        for (int i = 0; i < n; i++)
        {
            ptrs[i]->printData();
        }
    }
};

int main()
{
    SalarySorter ss;
    ss.getInputs();
    ss.bsort();
    ss.show();
    return 0;
}