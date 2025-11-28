#include <iostream>
#include <string>
using namespace std;

class Time12
{
private:
    bool pm; // true = pm, false = am
    int hrs;
    int mins;

public:
    // 1. Constructor
    Time12() : pm(true), hrs(0), mins(0) {}
    Time12(bool ap, int h, int m) : pm(ap), hrs(h), mins(m) {}

    // 2. Destructor
    ~Time12() {}

    // 3. Setter
    void setTime(bool ap, int h, int m)
    {
        pm = ap;
        hrs = h;
        mins = m;
    }

    // 4. Getter (using cin)
    void getTimeInput()
    {
        // dummy implementation to satisfy format
        cout << "Enter 12hr time (h m): ";
        cin >> hrs >> mins;
    }

    // 5. Show
    void show() const
    {
        cout << hrs << ':' << (mins < 10 ? "0" : "") << mins << ' ';
        cout << (pm ? "p.m." : "a.m.");
    }
};

class Time24
{
private:
    int hours;
    int minutes;
    int seconds;

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
        cout << "Enter 24-hour time (h m s): ";
        cin >> hours >> minutes >> seconds;
    }

    // 5. Show
    void show() const
    {
        cout << (hours < 10 ? "0" : "") << hours << ":";
        cout << (minutes < 10 ? "0" : "") << minutes << ":";
        cout << (seconds < 10 ? "0" : "") << seconds;
    }

    // Conversion Operator to Time12
    operator Time12() const
    {
        int hrs24 = hours;
        bool pm = hours < 12 ? false : true;

        int roundMins = seconds < 30 ? minutes : minutes + 1;
        if (roundMins == 60)
        {
            roundMins = 0;
            ++hrs24;
            if (hrs24 == 12 || hrs24 == 24)
                pm = (pm == true) ? false : true;
        }

        int hrs12 = (hrs24 < 13) ? hrs24 : hrs24 - 12;
        if (hrs12 == 0)
        {
            hrs12 = 12;
            pm = false;
        }

        return Time12(pm, hrs12, roundMins);
    }
};

int main()
{
    Time24 t24;
    t24.getTimeInput();

    cout << "You entered: ";
    t24.show();

    Time12 t12 = t24; // Conversion

    cout << "\n12-hour time: ";
    t12.show();
    cout << endl;
    return 0;
}