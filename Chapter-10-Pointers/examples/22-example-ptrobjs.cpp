#include <iostream>
using namespace std;

class Person
{
protected:
    char name[40];

public:
    // 1. Constructor
    Person() { name[0] = '\0'; }

    // 2. Destructor
    ~Person() {}

    // 3. Setter
    void setName()
    {
        cout << "Enter name: ";
        cin >> name;
    }

    // 4. Getter
    void getNameInput() { setName(); }

    // 5. Show
    void printName()
    {
        cout << "\nName is: " << name;
    }
    void show() { printName(); }
};

int main()
{
    Person *persPtr[100];
    int n = 0;
    char choice;

    do
    {
        persPtr[n] = new Person;
        persPtr[n]->setName();
        n++;
        cout << "Enter another (y/n)? ";
        cin >> choice;
    } while (choice == 'y');

    for (int j = 0; j < n; j++)
    {
        cout << "\nPerson number " << j + 1;
        persPtr[j]->printName();
    }
    cout << endl;

    // Cleanup
    for (int j = 0; j < n; j++)
        delete persPtr[j];

    return 0;
}