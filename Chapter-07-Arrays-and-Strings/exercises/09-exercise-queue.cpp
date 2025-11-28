#include <iostream>
using namespace std;

const int MAX = 10;

class Queue
{
private:
    int que[MAX];
    int head;
    int tail;
    int count;

public:
    // 1. Constructor
    Queue() : head(0), tail(0), count(0) {}

    // 2. Destructor
    ~Queue() {}

    // 3. Setter (Put)
    void put(int v)
    {
        if (count == MAX)
        {
            cout << "\nQueue Full";
            return;
        }
        que[tail] = v;
        tail++;
        if (tail == MAX)
            tail = 0; // Wrap around
        count++;
    }

    // 4. Getter (Get + cin)
    int getVal()
    {
        if (count == 0)
        {
            cout << "\nQueue Empty";
            return 0;
        }
        int temp = que[head];
        head++;
        if (head == MAX)
            head = 0; // Wrap around
        count--;
        return temp;
    }

    void getInput()
    {
        int v;
        cout << "Enter value to put: ";
        cin >> v;
        put(v);
    }

    // 5. Show
    void show()
    {
        cout << "Queue Count: " << count << endl;
    }
};

int main()
{
    Queue q;
    q.getInput();
    q.getInput();
    q.show();

    cout << "Removed: " << q.getVal() << endl;
    cout << "Removed: " << q.getVal() << endl;
    q.show();

    return 0;
}