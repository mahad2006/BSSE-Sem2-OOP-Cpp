#include <iostream>
using namespace std;

const int MAX = 4; // Max array size

class SmallObj
{
private:
    int someData;

public:
    // 1. Constructor
    SmallObj() : someData(0) {}

    // 2. Destructor
    ~SmallObj() {}

    // 3. Setter
    void setData(int d)
    {
        someData = d;
    }

    // 4. Getter (using cin)
    void getData()
    {
        cout << "Enter value: ";
        cin >> someData;
    }

    // 5. Show
    void showData() const
    {
        cout << "Data: " << someData << endl;
    }
};

class ArrayOfObjectsDemo
{
private:
    SmallObj objArr[MAX];

public:
    ArrayOfObjectsDemo() {}
    ~ArrayOfObjectsDemo() {}

    // 3. Setter
    void setAll()
    {
        for (int i = 0; i < MAX; i++)
        {
            objArr[i].setData((i + 1) * 10);
        }
    }

    // 4. Getter (cin)
    void getOne()
    {
        int index;
        cout << "Enter index (0-3): ";
        cin >> index;
        if (index >= 0 && index < MAX)
        {
            objArr[index].getData();
        }
    }

    // 5. Show
    void showAll()
    {
        cout << "\n--- Array Contents ---\n";
        for (int i = 0; i < MAX; i++)
        {
            cout << "Element " << i << ": ";
            objArr[i].showData();
        }
    }
};

int main()
{
    ArrayOfObjectsDemo demo;
    demo.setAll();
    demo.showAll();
    return 0;
}