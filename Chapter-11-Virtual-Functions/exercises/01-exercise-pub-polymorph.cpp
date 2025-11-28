#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Publication
{
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}
    virtual ~Publication() {}

    // Pure Virtual Functions
    virtual void getData() = 0;
    virtual void putData() = 0;

    // Format helpers
    void set(string t, float p)
    {
        title = t;
        price = p;
    }
    void show() { putData(); } // Generic show calls virtual
};

class Book : public Publication
{
private:
    int pages;

public:
    Book() : pages(0) {}
    ~Book() {}

    void getData()
    {
        cout << "\nEnter Book Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Pages: ";
        cin >> pages;
    }

    void putData()
    {
        cout << "\nType: Book\nTitle: " << title
             << "\nPrice: $" << price
             << "\nPages: " << pages << endl;
    }

    // Required format
    void setB(int p) { pages = p; }
    void get() { getData(); }
};

class Tape : public Publication
{
private:
    float minutes;

public:
    Tape() : minutes(0.0) {}
    ~Tape() {}

    void getData()
    {
        cout << "\nEnter Tape Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Minutes: ";
        cin >> minutes;
    }

    void putData()
    {
        cout << "\nType: Tape\nTitle: " << title
             << "\nPrice: $" << price
             << "\nMinutes: " << minutes << endl;
    }

    void setT(float m) { minutes = m; }
    void get() { getData(); }
};

int main()
{
    Publication *pubArr[100];
    int n = 0;
    char choice;

    do
    {
        cout << "Enter Book or Tape (b/t): ";
        cin >> choice;
        if (choice == 'b')
            pubArr[n] = new Book;
        else
            pubArr[n] = new Tape;

        pubArr[n++]->getData();

        cout << "Enter another (y/n)? ";
        cin >> choice;
    } while (choice == 'y');

    cout << "\n--- Publication List ---\n";
    for (int i = 0; i < n; i++)
        pubArr[i]->putData(); // Polymorphic call

    return 0;
}