#include <iostream>
#include <string>
using namespace std;

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
    void show() { putData(); }
};

enum DiskType
{
    CD,
    DVD
};

class Disk : public Publication
{
private:
    DiskType type;

public:
    // 1. Constructor
    Disk() : type(CD) {}

    // 2. Destructor
    ~Disk() {}

    // 3. Setter
    void setDisk(DiskType t) { type = t; }

    // 4. Getter
    void getData()
    {
        Publication::getData();
        char choice;
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> choice;
        type = (choice == 'd' || choice == 'D') ? DVD : CD;
    }

    // 5. Show
    void putData() const
    {
        Publication::putData();
        cout << "\nDisk Type: " << (type == CD ? "CD" : "DVD");
    }
    void show() { putData(); }
};

int main()
{
    Disk d;
    d.getData();
    d.show();
    cout << endl;
    return 0;
}