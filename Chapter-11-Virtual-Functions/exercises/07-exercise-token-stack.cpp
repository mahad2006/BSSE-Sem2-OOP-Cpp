#include <iostream>
using namespace std;

// Abstract Base
class Token
{
public:
    virtual void show() = 0; // Pure virtual
    virtual ~Token() {}
    // Dummy required format functions
    void set() {}
    void get() {}
};

class Number : public Token
{
private:
    float fnum;

public:
    Number(float f) : fnum(f) {}
    void show() { cout << "Num: " << fnum << endl; }
};

class Operator : public Token
{
private:
    char op;

public:
    Operator(char c) : op(c) {}
    void show() { cout << "Op: " << op << endl; }
};

// Stack of Pointers
class Stack
{
private:
    Token *st[100];
    int top;

public:
    Stack() : top(-1) {}
    ~Stack() {}
    void push(Token *t) { st[++top] = t; }
    Token *pop() { return st[top--]; }

    void set() {}
    void get() {}
    void show() {}
};

int main()
{
    Stack s;
    s.push(new Number(10.5));
    s.push(new Operator('+'));
    s.push(new Number(20.0));

    s.pop()->show();
    s.pop()->show();
    s.pop()->show();

    return 0;
}