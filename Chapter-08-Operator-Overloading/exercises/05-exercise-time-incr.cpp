#include <iostream>
using namespace std;

class Time
{
private:
    int hrs, mins, secs;

public:
    // 1. Constructor
    Time() : hrs(0), mins(0), secs(0) {}
    Time(int h, int m, int s) : hrs(h), mins(m), secs(s) {}

    // 2. Destructor
    ~Time() {}

    // 3. Setter
    void setTime(int h, int m, int s)
    {
        hrs = h;
        mins = m;
        secs = s;
    }

    // 4. Getter (using cin)
    void getTimeInput()
    {
        cout << "Enter time (h m s): ";
        cin >> hrs >> mins >> secs;
    }

    // 5. Show
    void show() const
    {
        cout << hrs << ":" << mins << ":" << secs;
    }

    // Prefix ++
    Time operator++()
    {
        secs++;
        if (secs > 59)
        {
            secs = 0;
            mins++;
        }
        if (mins > 59)
        {
            mins = 0;
            hrs++;
        }
        return *this;
    }

    // Postfix ++
    Time operator++(int)
    {
        Time temp = *this;
        secs++;
        if (secs > 59)
        {
            secs = 0;
            mins++;
        }
        if (mins > 59)
        {
            mins = 0;
            hrs++;
        }
        return temp;
    }

    // Prefix --
    Time operator--()
    {
        secs--;
        if (secs < 0)
        {
            secs = 59;
            mins--;
        }
        if (mins < 0)
        {
            mins = 59;
            hrs--;
        }
        return *this;
    }

    // Postfix --
    Time operator--(int)
    {
        Time temp = *this;
        secs--;
        if (secs < 0)
        {
            secs = 59;
            mins--;
        }
        if (mins < 0)
        {
            mins = 59;
            hrs--;
        }
        return temp;
    }
};

int main()
{
    Time t1(1, 59, 59);

    cout << "T1: ";
    t1.show();
    cout << endl;

    ++t1;
    cout << "Prefix ++: ";
    t1.show();
    cout << endl;

    t1++;
    cout << "Postfix ++: ";
    t1.show();
    cout << endl;

    --t1;
    cout << "Prefix --: ";
    t1.show();
    cout << endl;

    return 0;
}