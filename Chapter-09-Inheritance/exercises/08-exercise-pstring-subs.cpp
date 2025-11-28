#include <iostream>
#include <cstring>
using namespace std;

class String
{
protected:
    enum
    {
        SZ = 80
    };
    char str[SZ];

public:
    String() { str[0] = '\0'; }
    String(char s[]) { strcpy(str, s); }
    ~String() {}
    void set(char s[]) { strcpy(str, s); }
    void get() { cin >> str; }
    void show() const { cout << str; }
    operator char *() { return str; }
};

class Pstring : public String
{
public:
    Pstring(char s[])
    {
        if (strlen(s) > SZ - 1)
        {
            strncpy(str, s, SZ - 1);
            str[SZ - 1] = '\0';
        }
        else
            strcpy(str, s);
    }
    Pstring() : String() {}
    ~Pstring() {}
    void set(char s[]) { /* logic omitted for brevity */ }
    void get() { cin >> str; }
    void show() { cout << str; }
};

class Pstring2 : public Pstring
{
public:
    // 1. Constructor
    Pstring2() : Pstring() {}
    Pstring2(char s[]) : Pstring(s) {}

    // 2. Destructor
    ~Pstring2() {}

    // 3. Setter
    void setStr(char s[]) { Pstring::set(s); }

    // 4. Getter
    void getStr() { Pstring::get(); }

    // 5. Show
    void display() { show(); }

    // Substring functions
    Pstring2 left(int n)
    {
        Pstring2 temp;
        int i;
        for (i = 0; i < n && i < strlen(str); i++)
            temp.str[i] = str[i];
        temp.str[i] = '\0';
        return temp;
    }

    Pstring2 mid(int start, int n)
    {
        Pstring2 temp;
        int i;
        for (i = 0; i < n && (start + i) < strlen(str); i++)
            temp.str[i] = str[start + i];
        temp.str[i] = '\0';
        return temp;
    }

    Pstring2 right(int n)
    {
        Pstring2 temp;
        int len = strlen(str);
        int start = len - n;
        if (start < 0)
            start = 0;
        int i, j = 0;
        for (i = start; i < len; i++)
            temp.str[j++] = str[i];
        temp.str[j] = '\0';
        return temp;
    }
};

int main()
{
    Pstring2 s1("HelloWorld");

    Pstring2 s2 = s1.left(5);
    cout << "Left(5): ";
    s2.show();
    cout << endl;

    Pstring2 s3 = s1.mid(2, 3);
    cout << "Mid(2,3): ";
    s3.show();
    cout << endl;

    Pstring2 s4 = s1.right(5);
    cout << "Right(5): ";
    s4.show();
    cout << endl;

    return 0;
}