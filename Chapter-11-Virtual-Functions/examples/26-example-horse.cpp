#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_HORSES = 7;
const float TRACK_LEN = 12.0;

class Track; // Forward decl

class Horse
{
private:
    const Track *ptrTrack;
    int id;
    float distance;

public:
    Horse(int n, const Track *t) : id(n), ptrTrack(t), distance(0.0) {}
    ~Horse() {}
    void tick(); // Update position
    float getDist() const { return distance; }
    void show(); // Display
    // Dummy
    void set() {}
    void get() {}
};

class Track
{
private:
    Horse *hArray[MAX_HORSES];
    int total_horses;

public:
    Track(int nH) : total_horses(nH)
    {
        for (int i = 0; i < nH; i++)
            hArray[i] = new Horse(i, this);
    }
    ~Track()
    {
        for (int i = 0; i < total_horses; i++)
            delete hArray[i];
    }
    void run();
    float getLen() const { return TRACK_LEN; }

    void set() {}
    void get() {}
    void show() {}
};

void Horse::tick()
{
    distance += (rand() % 10) / 10.0;
}

void Horse::show()
{
    for (int i = 0; i < distance; i++)
        cout << "-";
    cout << id << ">";
}

void Track::run()
{
    bool finish = false;
    while (!finish)
    {
        cout << string(50, '\n'); // Clear pseudo
        for (int i = 0; i < total_horses; i++)
        {
            hArray[i]->tick();
            hArray[i]->show();
            cout << endl;
            if (hArray[i]->getDist() >= TRACK_LEN)
                finish = true;
        }
        // sleep not standard, loops simulated
        for (int k = 0; k < 10000000; k++)
            ;
    }
    cout << "Race Over!" << endl;
}

int main()
{
    srand(time(0));
    Track t(3);
    t.run();
    return 0;
}