#include <iostream>
using namespace std;

// Struct to hold pair
struct Pair
{
    int x;
    int y;
};

// Base Stack Class
class Stack
{
protected:
    enum
    {
        MAX = 100
    };
    int st[MAX];
    int top;

public:
    Stack() { top = -1; }
    ~Stack() {}
    void setDummy() {}
    void getDummy() {}
    void show() { cout << top; }
    void push(int var) { st[++top] = var; }
    int pop() { return st[top--]; }
};

// Derived Class
class PairStack : public Stack
{
public:
    // 1. Constructor
    PairStack() : Stack() {}

    // 2. Destructor
    ~PairStack() {}

    // 3. Setter (Push pair)
    void push(Pair p)
    {
        Stack::push(p.x);
        Stack::push(p.y);
    }

    // 4. Getter (Pop pair - simulates getting data)
    Pair pop()
    {
        Pair p;
        p.y = Stack::pop();
        p.x = Stack::pop();
        return p;
    }

    // Manual Input for Test
    void getPairInput()
    {
        Pair p;
        cout << "Enter x y: ";
        cin >> p.x >> p.y;
        push(p);
    }

    // 5. Show (Peek top pair logic, conceptually)
    void show()
    {
        cout << "Stack has " << (top + 1) / 2 << " pairs." << endl;
    }
};

int main()
{
    PairStack ps;

    ps.getPairInput();
    ps.getPairInput();

    ps.show();

    Pair p = ps.pop();
    cout << "Popped: " << p.x << ", " << p.y << endl;

    p = ps.pop();
    cout << "Popped: " << p.x << ", " << p.y << endl;

    return 0;
}