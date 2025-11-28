#include <iostream>
using namespace std;

class DayCounter
{
private:
    int days_per_month[12];
    int month, day;

public:
    // 1. Constructor (Initialize array)
    DayCounter() : month(0), day(0)
    {
        int dpm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 0; i < 12; i++)
            days_per_month[i] = dpm[i];
    }

    // 2. Destructor
    ~DayCounter() {}

    // 3. Setter
    void setDate(int m, int d)
    {
        month = m;
        day = d;
    }

    // 4. Getter (using cin)
    void getDateInput()
    {
        cout << "Enter month (1 to 12): ";
        cin >> month;
        cout << "Enter day (1 to 31): ";
        cin >> day;
    }

    // 5. Show
    void show()
    {
        int total_days = day;
        for (int j = 0; j < month - 1; j++)
            total_days += days_per_month[j];
        cout << "Total days from start of year is: " << total_days << endl;
    }
};

int main()
{
    DayCounter dc;
    dc.getDateInput();
    dc.show();
    return 0;
}