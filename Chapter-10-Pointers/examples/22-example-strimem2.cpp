#include <iostream>
#include <cstring>
using namespace std;

class StrCount
{
private:
    int count;
    char *str;
    friend class String;

    StrCount(char *s)
    {
        int length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
        count = 1;
    }
    ~StrCount() { delete[] str; }
};

class String
{
private:
    StrCount *psc;

public:
    String() { psc = new StrCount(""); }
    String(char *s) { psc = new StrCount(s); }
    String(String &S)
    {
        psc = S.psc;
        (psc->count)++;
    }
    ~String()
    {
        if (psc->count == 1)
            delete psc;
        else
            (psc->count)--;
    }
    void set() {}
    void get() {}
    void show() { cout << psc->str << " (addr=" << psc << ")"; }

    String &operator=(String &S)
    {
        if (this == &S)
            return *this; // Self-assignment check

        if (psc->count == 1)
            delete psc;
        else
            (psc->count)--;
        psc = S.psc;
        (psc->count)++;
        return *this;
    }
};

int main()
{
    String s3 = "Proverb";
    String s1, s2;
    s1 = s2 = s3;

    s1.show();
    cout << endl;
    s2.show();
    cout << endl;
    s3.show();
    cout << endl;
    return 0;
}