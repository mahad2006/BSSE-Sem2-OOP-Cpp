#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;

public:
    Person() {}
    ~Person() {}
    void setName()
    {
        cout << "Enter name: ";
        cin >> name;
    }
    void printName() { cout << endl
                            << name; }
    string getName() { return name; }

    void set(string n) { name = n; }
    void get() { setName(); }
    void show() { printName(); }
};

// Global sort helpers
void order(Person **pp1, Person **pp2)
{
    if ((*pp1)->getName() > (*pp2)->getName())
    {
        Person *temp = *pp1;
        *pp1 = *pp2;
        *pp2 = temp;
    }
}

void bsort(Person **pp, int n)
{
    for (int j = 0; j < n - 1; j++)
        for (int k = j + 1; k < n; k++)
            order(pp + j, pp + k);
}

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

    cout << "\nUnsorted list:";
    for (int j = 0; j < n; j++)
        persPtr[j]->printName();

    bsort(persPtr, n);

    cout << "\nSorted list:";
    for (int j = 0; j < n; j++)
        persPtr[j]->printName();

    cout << endl;
    // Cleanup
    for (int j = 0; j < n; j++)
        delete persPtr[j];

    return 0;
}