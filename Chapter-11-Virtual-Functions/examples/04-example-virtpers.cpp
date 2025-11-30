#include <iostream>
using namespace std;

class Person
{
protected:
    char name[40];

public:
    Person() {}
    virtual ~Person() {}

    // 3. Setter (Name)
    void setName(char *n) { /* manual copy logic skipped for brevity */ }

    // 4. Getter (Name via cin)
    void getName()
    {
        cout << "Enter name: ";
        cin >> name;
    }

    // 5. Show
    void putName()
    {
        cout << "Name is: " << name << endl;
    }

    // Pure Virtual Functions
    virtual void getData() = 0;
    virtual bool isOutstanding() = 0;
};

class Student : public Person
{
private:
    float gpa;

public:
    Student() : gpa(0.0) {}
    ~Student() {}

    void setGPA(float g) { gpa = g; }

    // Getter (Input)
    void getData()
    {
        Person::getName();
        cout << "Enter student's GPA: ";
        cin >> gpa;
    }

    // Logic check
    bool isOutstanding() { return (gpa > 3.5); }

    void show() {} // dummy
};

class Professor : public Person
{
private:
    int numPubs;

public:
    Professor() : numPubs(0) {}
    ~Professor() {}

    void setPubs(int p) { numPubs = p; }

    // Getter (Input)
    void getData()
    {
        Person::getName();
        cout << "Enter number of publications: ";
        cin >> numPubs;
    }

    bool isOutstanding() { return (numPubs > 100); }

    void show() {} // dummy
};

int main()
{
    Person *persPtr[100];
    int n = 0;
    char choice;

    do
    {
        cout << "Enter student or professor (s/p): ";
        cin >> choice;

        if (choice == 's')
            persPtr[n] = new Student;
        else
            persPtr[n] = new Professor;

        persPtr[n++]->getData();

        cout << "Enter another (y/n)? ";
        cin >> choice;
    } while (choice == 'y');

    for (int j = 0; j < n; j++)
    {
        persPtr[j]->putName();
        if (persPtr[j]->isOutstanding())
            cout << "This person is outstanding\n";
    }

    // Cleanup
    for (int j = 0; j < n; j++)
        delete persPtr[j];

    return 0;
}