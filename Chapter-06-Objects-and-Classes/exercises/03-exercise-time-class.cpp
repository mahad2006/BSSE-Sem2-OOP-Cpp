// 03-exercise-time-class.cpp
#include <iostream>
using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    // 1. Constructor
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // 2. Destructor
    ~Time() {}

    // 3. Setter
    void setTime(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }

    // 4. Getter (using cin)
    void getTime()
    {
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;
    }

    // 5. Show
    void show() const
    {
        cout << hours << ":" << minutes << ":" << seconds;
    }

    // Logic to add times
    void add_time(Time t1, Time t2)
    {
        seconds = t1.seconds + t2.seconds;
        if (seconds > 59)
        {
            seconds -= 60;
            minutes++;
        }
        minutes += t1.minutes + t2.minutes;
        if (minutes > 59)
        {
            minutes -= 60;
            hours++;
        }
        hours += t1.hours + t2.hours;
    }
};

int main()
{
    Time t1(1, 45, 30);
    Time t2(2, 20, 40);
    Time t3;

    cout << "Time 1: ";
    t1.show();
    cout << endl;
    cout << "Time 2: ";
    t2.show();
    cout << endl;

    t3.add_time(t1, t2);
    cout << "Time 3 (sum): ";
    t3.show();
    cout << endl;

    return 0;
}