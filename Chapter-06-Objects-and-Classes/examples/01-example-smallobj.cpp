#include <iostream>
using namespace std;
class SmallObj
{
private:
    int someData; // Class data

public:
    // 1. Constructor
    SmallObj()
    {
        someData = 0;
    }
    // 2. Destructor
    ~SmallObj()
    {
        // Cleanup if necessary
    }

    // 3. Setter function
    void setData(int d)
    {
        someData = d;
    }

    // 4. Getter function (using cin as requested)
    void getData()
    {
        cout << "Enter value for someData: ";
        cin >> someData;
    }

    // 5. Show function
    void show() const
    {
        cout << "Data is: " << someData << endl;
    }
};

int main()
{
    SmallObj s1, s2;

    // Using setter
    s1.setData(1066);
    s2.setData(1776);

    // Displaying
    s1.show();
    s2.show();

    // Using getter (cin)
    s1.getData();
    s1.show();

    return 0;
}