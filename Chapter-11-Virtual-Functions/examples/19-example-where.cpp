#include <iostream>
using namespace std;

class Where
{
private:
    char charray[10];

public:
    Where() {}
    ~Where() {}
    void set() {}
    void get() {}

    void show()
    {
        cout << "My object's address is " << this << endl;
    }
};

int main()
{
    Where w1, w2, w3;
    w1.show();
    w2.show();
    w3.show();
    return 0;
}