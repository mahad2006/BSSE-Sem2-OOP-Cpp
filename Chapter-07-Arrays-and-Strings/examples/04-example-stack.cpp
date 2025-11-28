#include <iostream>
using namespace std;

const int STACK_SIZE = 10;

class Stack
{
private:
    int st[STACK_SIZE]; // Array as private member
    int top;

public:
    // 1. Constructor
    Stack() : top(0) {}

    // 2. Destructor
    ~Stack() {}

    // 3. Setter (Push)
    void push(int var)
    {
        if (top < STACK_SIZE)
        {
            st[top++] = var;
        }
        else
        {
            cout << "Error: Stack is full." << endl;
        }
    }

    // 4. Getter (Pop)
    int pop()
    {
        if (top > 0)
        {
            return st[--top];
        }
        else
        {
            cout << "Error: Stack is empty. Returning 0." << endl;
            return 0;
        }
    }

    // 5. Show
    void show()
    {
        cout << "Current stack size: " << top << endl;
    }
};

class StackDemo
{
public:
    StackDemo() {}
    ~StackDemo() {}
    void set() {}
    void get() {}

    // 5. Show (Demonstration)
    void show()
    {
        Stack s1;
        s1.push(11);
        s1.push(22);

        cout << "\nPop 1: " << s1.pop() << endl;
        cout << "Pop 2: " << s1.pop() << endl;
        s1.show();
        s1.pop(); // Empty stack test
    }
};

int main()
{
    StackDemo sd;
    sd.show();
    return 0;
}