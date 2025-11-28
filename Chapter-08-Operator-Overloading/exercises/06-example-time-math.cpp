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
    void show() const { cout << hrs << ":" << mins << ":" << secs; }

    // Subtraction
    Time operator-(Time t2) const
    {
        long totSec1 = hrs * 3600 + mins * 60 + secs;
        long totSec2 = t2.hrs * 3600 + t2.mins * 60 + t2.secs;
        long diff = totSec1 - totSec2;

        int h = diff / 3600;
        int m = (diff % 3600) / 60;
        int s = diff % 60;
        return Time(h, m, s);
    }

    // Multiplication by float
    Time operator*(float factor) const
    {
        long totSec = hrs * 3600 + mins * 60 + secs;
        long newSec = totSec * factor;

        int h = newSec / 3600;
        int m = (newSec % 3600) / 60;
        int s = newSec % 60;
        return Time(h, m, s);
    }
};

int main()
{
    Time t1(2, 30, 0); // 2.5 hours
    Time t2(1, 15, 0); // 1.25 hours
    Time t3;

    cout << "T1: ";
    t1.show();
    cout << endl;
    cout << "T2: ";
    t2.show();
    cout << endl;

    t3 = t1 - t2;
    cout << "T1 - T2: ";
    t3.show();
    cout << endl;

    t3 = t1 * 2.0;
    cout << "T1 * 2.0: ";
    t3.show();
    cout << endl;

    return 0;
}