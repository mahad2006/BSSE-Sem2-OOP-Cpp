#include <iostream>
#include <string>
using namespace std;

class Time24
{
private:
    int hours, minutes, seconds;

public:
    // 1. Constructor
    Time24() : hours(0), minutes(0), seconds(0) {}
    Time24(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // 2. Destructor
    ~Time24() {}

    // 3. Setter
    void setTime(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }

    // 4. Getter (using cin)
    void getTimeInput()
    {
        cout << "Enter 24h time (h m s): ";
        cin >> hours >> minutes >> seconds;
    }

    // 5. Show
    void show() const
    {
        cout << hours << ":" << minutes << ":" << seconds;
    }

    // Helper getters for conversion
    int getHrs() const { return hours; }
    int getMins() const { return minutes; }
    int getSecs() const { return seconds; }
};

class Time12
{
private:
    bool pm;
    int hrs;
    int mins;

public:
    // 1. Constructor
    Time12() : pm(true), hrs(0), mins(0) {}
    Time12(bool ap, int h, int m) : pm(ap), hrs(h), mins(m) {}

    // Conversion Constructor (from Time24)
    Time12(Time24 t24)
    {
        int hrs24 = t24.getHrs();
        pm = t24.getHrs() < 12 ? false : true;

        mins = (t24.getSecs() < 30) ? t24.getMins() : t24.getMins() + 1;
        if (mins == 60)
        {
            mins = 0;
            ++hrs24;
            if (hrs24 == 12 || hrs24 == 24)
                pm = (pm == true) ? false : true;
        }

        hrs = (hrs24 < 13) ? hrs24 : hrs24 - 12;
        if (hrs == 0)
        {
            hrs = 12;
            pm = false;
        }
    }

    // 2. Destructor
    ~Time12() {}

    // 3. Setter
    void setTime(bool ap, int h, int m)
    {
        pm = ap;
        hrs = h;
        mins = m;
    }

    // 4. Getter
    void getTimeInput()
    {
        cout << "Enter 12h time: ";
        cin >> hrs >> mins;
    }

    // 5. Show
    void show() const
    {
        cout << hrs << ":" << mins << " " << (pm ? "p.m." : "a.m.");
    }
};

int main()
{
    Time24 t24;
    t24.getTimeInput();

    Time12 t12 = t24; // Uses constructor in Time12

    cout << "12-hour time: ";
    t12.show();
    cout << endl;
    return 0;
}