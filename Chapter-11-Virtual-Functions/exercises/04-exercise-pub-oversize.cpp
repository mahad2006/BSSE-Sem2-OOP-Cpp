#include <iostream>
#include <string>
using namespace std;

class Publication
{
protected:
    string title;

public:
    virtual void getData() = 0;
    virtual void putData() = 0;
    virtual bool isOversize() = 0; // New pure virtual
    virtual ~Publication() {}
    void set() {}
    void get() {}
    void show() {}
};

class Book : public Publication
{
private:
    int pages;

public:
    void getData()
    {
        cout << "Book Title: ";
        cin >> title;
        cout << "Pages: ";
        cin >> pages;
    }
    void putData()
    {
        cout << "Book: " << title << ", " << pages << " pages.";
    }
    bool isOversize() { return (pages > 800); }
};

class Tape : public Publication
{
private:
    float minutes;

public:
    void getData()
    {
        cout << "Tape Title: ";
        cin >> title;
        cout << "Minutes: ";
        cin >> minutes;
    }
    void putData()
    {
        cout << "Tape: " << title << ", " << minutes << " mins.";
    }
    bool isOversize() { return (minutes > 90.0); }
};

int main()
{
    Publication *list[10];
    int n = 0;
    char ch;
    do
    {
        cout << "Book or Tape (b/t)? ";
        cin >> ch;
        if (ch == 'b')
            list[n] = new Book;
        else
            list[n] = new Tape;
        list[n++]->getData();
        cout << "More? (y/n): ";
        cin >> ch;
    } while (ch == 'y');

    for (int i = 0; i < n; i++)
    {
        list[i]->putData();
        if (list[i]->isOversize())
            cout << " (Oversize!)";
        cout << endl;
    }
    return 0;
}