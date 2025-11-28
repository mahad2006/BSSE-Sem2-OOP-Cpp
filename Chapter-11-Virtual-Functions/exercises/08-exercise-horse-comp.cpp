#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Simplified console graphics stub
void cursor(int x, int y) { /* stub */ }

class Horse
{
protected:
    int dist;

public:
    Horse() : dist(0) {}
    virtual ~Horse() {}
    virtual void tick() { dist += rand() % 2; } // Standard speed
    int getDist() const { return dist; }

    void set() {}
    void get() {}
    void show()
    {
        for (int i = 0; i < dist; i++)
            cout << "-";
        cout << ">" << endl;
    }
};

class ComHorse : public Horse
{
public:
    ComHorse() {}
    void tick()
    {
        // Competitive logic: runs faster
        dist += (rand() % 2) + 1;
    }
};

int main()
{
    srand(time(0));
    Horse *h1 = new Horse;
    Horse *h2 = new ComHorse;

    for (int i = 0; i < 10; i++)
    {
        h1->tick();
        h2->tick();
        cout << "H1: ";
        h1->show();
        cout << "H2: ";
        h2->show();
        cout << endl;
    }
    return 0;
}