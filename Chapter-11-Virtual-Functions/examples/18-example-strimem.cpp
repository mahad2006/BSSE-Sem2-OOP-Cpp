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
    // 1. Constructor
    String() { psc = new StrCount(""); }
    String(char *s) { psc = new StrCount(s); }

    // Copy Constructor
    String(String &S)
    {
        psc = S.psc;
        (psc->count)++;
    }

    // 2. Destructor
    ~String()
    {
        if (psc->count == 1)
            delete psc;
        else
            (psc->count)--;
    }

    // 3. Setter
    void setStr(char *s)
    {
        // Complex logic simplified: replace current
        if (psc->count == 1)
            delete psc;
        else
            (psc->count)--;
        psc = new StrCount(s);
    }

    // 4. Getter (cin)
    void getStr()
    {
        char temp[100];
        cout << "Enter string: ";
        cin >> temp;
        setStr(temp);
    }

    // 5. Show
    void show()
    {
        cout << psc->str << " (addr=" << psc << ")";
    }

    void operator=(String &S)
    {
        if (psc->count == 1)
            delete psc;
        else
            (psc->count)--;
        psc = S.psc;
        (psc->count)++;
    }
};

int main()
{
    String s3 = "Hello";
    cout << "s3=";
    s3.show();
    cout << endl;

    String s1;
    s1 = s3;
    cout << "s1=";
    s1.show();
    cout << endl;

    String s2(s3);
    cout << "s2=";
    s2.show();
    cout << endl;

    return 0;
}