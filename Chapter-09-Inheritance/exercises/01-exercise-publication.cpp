#include <iostream>
#include <string>
using namespace std;

// Base Class
class Publication
{
protected:
    string title;
    float price;

public:
    // 1. Constructor
    Publication() : title(""), price(0.0) {}

    // 2. Destructor
    ~Publication() {}

    // 3. Setter
    void setData(string t, float p)
    {
        title = t;
        price = p;
    }

    // 4. Getter (using cin)
    void getData()
    {
        cout << "\nEnter title: ";
        cin.ignore(); // clear buffer
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    // 5. Show
    void putData() const
    {
        cout << "\nTitle: " << title;
        cout << "\nPrice: $" << price;
    }
};

// Derived Class 1
class Book : public Publication
{
private:
    int pageCount;

public:
    // 1. Constructor
    Book() : Publication(), pageCount(0) {}

    // 2. Destructor
    ~Book() {}

    // 3. Setter
    void setBook(string t, float p, int pc)
    {
        setData(t, p);
        pageCount = pc;
    }

    // 4. Getter
    void getData()
    {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    // 5. Show
    void putData() const
    {
        Publication::putData();
        cout << "\nPages: " << pageCount;
    }
};

// Derived Class 2
class Tape : public Publication
{
private:
    float playingTime; // minutes

public:
    // 1. Constructor
    Tape() : Publication(), playingTime(0.0) {}

    // 2. Destructor
    ~Tape() {}

    // 3. Setter
    void setTape(string t, float p, float pt)
    {
        setData(t, p);
        playingTime = pt;
    }

    // 4. Getter
    void getData()
    {
        Publication::getData();
        cout << "Enter playing time (mins): ";
        cin >> playingTime;
    }

    // 5. Show
    void putData() const
    {
        Publication::putData();
        cout << "\nTime: " << playingTime << " mins";
    }
};

int main()
{
    Book b;
    Tape t;

    cout << "--- Enter Book Data ---";
    b.getData();

    cout << "\n--- Enter Tape Data ---";
    t.getData();

    cout << "\n--- Book Details ---";
    b.putData();

    cout << "\n\n--- Tape Details ---";
    t.putData();
    cout << endl;

    return 0;
}