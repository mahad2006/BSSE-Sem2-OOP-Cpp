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
    void setCount(int c)
    {
        count = c;
    }

    // 4. Getter (using cin)
    void getCountInput()
    {
        cout << "Enter count value: ";
        cin >> count;
    }

    // 5. Show
    void show() const
    {
        cout << "Count: " << count << endl;
    }

    // Overloaded ++ operator (prefix)
    void operator++()
    {
        ++count;
    }
};

int main()
{
    Counter c1, c2;

    cout << "Initial values:\n";
    c1.show();
    c2.show();

    ++c1;
    ++c2;
    ++c2;

    cout << "\nAfter incrementing:\n";
    c1.show();
    c2.show();

    return 0;
}