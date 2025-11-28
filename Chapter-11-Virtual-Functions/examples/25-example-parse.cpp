#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAX = 40;

class Stack
{
private:
    char st[MAX];
    int top;

public:
    Stack() { top = 0; }
    ~Stack() {}
    void push(char var) { st[++top] = var; }
    char pop() { return st[top--]; }
    int getTop() { return top; }

    // Required dummy
    void set() {}
    void get() {}
    void show() {}
};

class Express
{
private:
    Stack s;
    char *pStr;
    int len;

public:
    // 1. Constructor
    Express(char *ptr)
    {
        pStr = ptr;
        len = strlen(pStr);
    }

    // 2. Destructor
    ~Express() {}

    // 3. Setter
    void parse()
    {
        char ch;
        char lastval, lastop;

        for (int j = 0; j < len; j++)
        {
            ch = pStr[j];
            if (ch >= '0' && ch <= '9')
                s.push(ch - '0');
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                if (s.getTop() == 1)
                    s.push(ch);
                else
                {
                    lastval = s.pop();
                    lastop = s.pop();
                    if ((ch == '*' || ch == '/') && (lastop == '+' || lastop == '-'))
                    {
                        s.push(lastop);
                        s.push(lastval);
                    }
                    else
                    {
                        switch (lastop)
                        {
                        case '+':
                            s.push(s.pop() + lastval);
                            break;
                        case '-':
                            s.push(s.pop() - lastval);
                            break;
                        case '*':
                            s.push(s.pop() * lastval);
                            break;
                        case '/':
                            s.push(s.pop() / lastval);
                            break;
                        }
                    }
                    s.push(ch);
                }
            }
        }
    }

    // 4. Getter (Solve)
    int solve()
    {
        char lastval;
        while (s.getTop() > 1)
        {
            lastval = s.pop();
            switch (s.pop())
            {
            case '+':
                s.push(s.pop() + lastval);
                break;
            case '-':
                s.push(s.pop() - lastval);
                break;
            case '*':
                s.push(s.pop() * lastval);
                break;
            case '/':
                s.push(s.pop() / lastval);
                break;
            }
        }
        return int(s.pop());
    }

    // 5. Show
    void show() { cout << "Expression parsed." << endl; }
};

int main()
{
    char ans;
    char str[80];

    do
    {
        cout << "Enter expression: ";
        cin >> str;
        Express *eptr = new Express(str);
        eptr->parse();
        cout << "Value: " << eptr->solve() << endl;
        delete eptr;
        cout << "Do another? ";
        cin >> ans;
    } while (ans == 'y');

    return 0;
}