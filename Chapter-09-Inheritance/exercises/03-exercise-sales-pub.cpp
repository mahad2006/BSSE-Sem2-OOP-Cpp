#include <iostream>
#include <string>
using namespace std;

// Base 1
class Publication
{
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}
    ~Publication() {}
    void setData(string t, float p)
    {
        title = t;
        price = p;
    }
    void getData()
    {
        cout << "\nEnter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }
    void putData() const
    {
        cout << "\nTitle: " << title << "\nPrice: $" << price;
    }
    // Required Show
    void show() { putData(); }
};

// Base 2
class Sales
{
protected:
    enum
    {
        MONTHS = 3
    };
    float salesArr[MONTHS];

public:
    Sales()
    {
        for (int i = 0; i < MONTHS; i++)
            salesArr[i] = 0.0;
    }
    ~Sales() {}
    void setSales(float s1, float s2, float s3)
    {
        salesArr[0] = s1;
        salesArr[1] = s2;
        salesArr[2] = s3;
    }
    void getSales()
    {
        cout << "Enter sales for 3 months: ";
        for (int i = 0; i < MONTHS; i++)
            cin >> salesArr[i];
    }
    void putSales() const
    {
        for (int i = 0; i < MONTHS; i++)
            cout << "\nMonth " << i + 1 << " Sales: $" << salesArr[i];
    }
    void show() { putSales(); }
};

// Derived 1
class Book : public Publication, public Sales
{
private:
    int pages;

public:
    Book() : pages(0) {}
    ~Book() {}
    void setBook(int p) { pages = p; }
    void getData()
    {
        Publication::getData();
        cout << "Enter pages: ";
        cin >> pages;
        Sales::getSales();
    }
    void putData() const
    {
        Publication::putData();
        cout << "\nPages: " << pages;
        Sales::putSales();
    }
    void show() { putData(); }
};

// Derived 2
class Tape : public Publication, public Sales
{
private:
    float time;

public:
    Tape() : time(0.0) {}
    ~Tape() {}
    void setTape(float t) { time = t; }
    void getData()
    {
        Publication::getData();
        cout << "Enter time (mins): ";
        cin >> time;
        Sales::getSales();
    }
    void putData() const
    {
        Publication::putData();
        cout << "\nTime: " << time << " mins";
        Sales::putSales();
    }
    void show() { putData(); }
};

int main()
{
    Book b;
    Tape t;

    b.getData();
    t.getData();

    cout << "\n--- Book Info ---";
    b.show();
    cout << "\n\n--- Tape Info ---";
    t.show();
    cout << endl;

    return 0;
}