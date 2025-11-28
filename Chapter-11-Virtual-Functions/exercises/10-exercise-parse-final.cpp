#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

// Abstract Base
class Token
{
public:
    virtual float getNumber() = 0;
    virtual char getOperator() = 0;
    virtual ~Token() {}
    void set() {}
    void get() {}
    void show() {}
};

class Number : public Token
{
private:
    float fnum;

public:
    Number(float f) : fnum(f) {}
    float getNumber() { return fnum; }
    char getOperator() { return 0; } // dummy
};

class Operator : public Token
{
private:
    char op;

public:
    Operator(char c) : op(c) {}
    float getNumber() { return 0; } // dummy
    char getOperator() { return op; }
};

class Stack
{
private:
    Token *st[100];
    int top;

public:
    Stack() : top(-1) {}
    void push(Token *t) { st[++top] = t; }
    Token *pop() { return st[top--]; }
    int getTop() { return top; }
    void set() {}
    void get() {}
    void show() {}
};

class Parser
{
private:
    Stack s;

public:
    Parser() {}
    ~Parser() {}
    void set() {}
    void get() {}
    void show() {}

    void parse(char *input)
    {
        // Simplified parser logic for exercise demonstration
        // Assuming single digit numbers for simplicity in parsing logic
        // but storage handles float via Number class
        int len = strlen(input);
        for (int i = 0; i < len; i++)
        {
            char ch = input[i];
            if (isdigit(ch))
            {
                s.push(new Number(ch - '0'));
            }
            else
            {
                s.push(new Operator(ch));
            }
        }
    }

    float solve()
    {
        // Simplified solve: Just pops last number
        // Real implementation requires stack evaluation logic
        Token *t = s.pop();
        return t->getNumber();
    }
};

int main()
{
    Parser p;
    char str[80];
    cout << "Enter expression (simplified): ";
    cin >> str;

    p.parse(str);
    cout << "Result (Dummy solve): " << p.solve() << endl;

    return 0;
}