#include <iostream>
using namespace std;

class Foo
{
private:
    static int count; // Static data

public:
    // 1. Constructor
    Foo() { count++; }

    // 2. Destructor
    ~Foo() {}

    // 3. Setter (Dummy, static data usually managed internally)
    void setDummy() {}

    // 4. Getter (cin)
    void getDummy()
    {
        int x;
        cin >> x;
    }

    // 5. Show (returns count)
    int getCount() { return count; }
};

// Definition of static member
int Foo::count = 0;

int main()
{
    Foo f1, f2, f3;

    cout << "count is " << f1.getCount() << endl;
    cout << "count is " << f2.getCount() << endl;
    cout << "count is " << f3.getCount() << endl;

    return 0;
}