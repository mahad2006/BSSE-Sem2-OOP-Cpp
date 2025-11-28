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

    // Prefix increment
    Counter operator++()
    {
        return Counter(++count);
    }

    // Postfix increment
    Counter operator++(int)
    {
        return Counter(count++);
    }
};

int main()
{
    Counter c1, c2;

    cout << "Prefix test:\n";
    c2 = ++c1;
    c1.show();
    c2.show();

    cout << "\nPostfix test:\n";
    c2 = c1++;
    c1.show(); // Should be 2
    c2.show(); // Should be 1 (old value)

    return 0;
}