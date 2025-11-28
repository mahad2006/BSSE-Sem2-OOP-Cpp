#include <iostream>
using namespace std;

class Counter
{
private:
    unsigned int count;

public:
    // 1. Constructor
    Counter() : count(0) {}
    Counter(int c) : count(c) {}

    // 2. Destructor
    ~Counter() {}

    // 3. Setter
    void setCount(int c) { count = c; }

    // 4. Getter (using cin)
    void getCountInput()
    {
        cout << "Enter count: ";
        cin >> count;
    }

    // 5. Show
    void show() const
    {
        cout << "Count: " << count << endl;
    }

    // Overloaded ++ (nameless temporary)
    Counter operator++()
    {
        ++count;
        return Counter(count);
    }
};

int main()
{
    Counter c1, c2;
    ++c1;
    c2 = ++c1;

    cout << "c1: ";
    c1.show();
    cout << "c2: ";
    c2.show();
    return 0;
}