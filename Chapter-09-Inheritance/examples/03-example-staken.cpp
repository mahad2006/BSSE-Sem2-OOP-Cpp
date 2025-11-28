#include <iostream>
#include <cstdlib> // for exit()
using namespace std;

// Base Class
class Stack
{
protected:
    enum
    {
        MAX = 3
    };
    int st[MAX];
    int top;

public:
    // 1. Constructor
    Stack() { top = -1; }

    // 2. Destructor
    ~Stack() {}

    // 3. Setter (Push)
    void push(int var) { st[++top] = var; }

    // 4. Getter (Pop - logic getter)
    int pop() { return st[top--]; }

    // Dummy cin getter for format
    void getInput()
    {
        int v;
        cout << "Enter val: ";
        cin >> v;
        push(v);
    }

    // 5. Show
    void show() { cout << "Top index: " << top << endl; }
};

// Derived Class
class Stack2 : public Stack
{
public:
    // 1. Constructor
    Stack2() : Stack() {}

    // 2. Destructor
    ~Stack2() {}

    // 3. Setter (Overriding push with safety check)
    void push(int var)
    {
        if (top >= MAX - 1)
        {
            cout << "\nError: stack is full";
            exit(1);
        }
        Stack::push(var); // Call base push
    }

    // 4. Getter (Overriding pop with safety check)
    int pop()
    {
        if (top < 0)
        {
            cout << "\nError: stack is empty\n";
            exit(1);
        }
        return Stack::pop(); // Call base pop
    }

    // 5. Show
    void display() { show(); }
};

int main()
{
    Stack2 s1;

    s1.push(11);
    s1.push(22);
    s1.push(33);

    cout << endl
         << s1.pop();
    cout << endl
         << s1.pop();
    cout << endl
         << s1.pop();

    // This will trigger error in Stack2
    cout << endl
         << s1.pop();

    return 0;
}