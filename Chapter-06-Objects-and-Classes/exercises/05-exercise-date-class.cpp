#include <iostream>
using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;

public:
    // 1. Constructor
    Date() : month(0), day(0), year(0) {}

    // 2. Destructor
    ~Date() {}

    // 3. Setter
    void setDate(int m, int d, int y)
    {
        month = m;
        day = d;
        year = y;
    }

    // 4. Getter (using cin)
    void getDate()
    {
        char slash;
        cout << "Enter date (MM/DD/YYYY): ";
        cin >> month >> slash >> day >> slash >> year;
    }

    // 5. Show
    void show() const
    {
        cout << month << "/" << day << "/" << year;
    }
};

int main()
{
    Date d1;
    d1.getDate();
    cout << "Date entered: ";
    d1.show();
    cout << endl;
    return 0;
}