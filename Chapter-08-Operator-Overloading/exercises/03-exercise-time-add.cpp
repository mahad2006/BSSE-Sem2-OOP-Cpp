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

    // Overloaded + operator
    Time operator+(Time t2) const
    {
        int s = secs + t2.secs;
        int m = mins + t2.mins;
        int h = hrs + t2.hrs;

        if (s > 59)
        {
            s -= 60;
            m++;
        }
        if (m > 59)
        {
            m -= 60;
            h++;
        }

        return Time(h, m, s);
    }
};

int main()
{
    Time t1(2, 55, 40);
    Time t2(5, 20, 30);
    Time t3;

    cout << "T1: ";
    t1.show();
    cout << endl;
    cout << "T2: ";
    t2.show();
    cout << endl;

    t3 = t1 + t2;

    cout << "T3 (T1 + T2): ";
    t3.show();
    cout << endl;

    return 0;
}