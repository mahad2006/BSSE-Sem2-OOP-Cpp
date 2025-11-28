#include <iostream>
using namespace std;

class What
{
private:
    int alpha;

public:
    What() : alpha(0) {}
    ~What() {}

    void set(int a) { this->alpha = a; }
    void get() { cin >> this->alpha; }

    void show()
    {
        cout << this->alpha << endl;
    }
};

int main()
{
    What w;
    w.set(11);
    w.show();
    return 0;
}