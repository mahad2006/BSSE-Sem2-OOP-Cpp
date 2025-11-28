#include <iostream>
using namespace std;

class Counter {
private:
    unsigned int count;

public:
    // 1. Constructor (Initializer list)
    Counter() : count(0) {}

    // 2. Destructor
    ~Counter() {}

    // 3. Setter (Increment)
    void inc_count() { count++; }

    // 4. Getter (using cin)
    void getInput() {
        cout << "Enter initial count: ";
        cin >> count;
    }
    
    int get_count() { return count; }

    // 5. Show
    void show() {
        cout << "Count: " << count << endl;
    }
};

int main() {
    Counter c1, c2;

    cout << "\nc1=" << c1.get_count();
    cout << "\nc2=" << c2.get_count();

    c1.inc_count();
    c2.inc_count();
    c2.inc_count();

    cout << "\nc1=" << c1.get_count();
    cout << "\nc2=" << c2.get_count();
    cout << endl;

    return 0;
}