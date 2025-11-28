#include <iostream>
using namespace std;

class Array
{
private:
    int *ptr;
    int size;

public:
    // 1. Constructor
    Array(int s) : size(s)
    {
        ptr = new int[s];
        for (int i = 0; i < size; i++)
            ptr[i] = 0;
    }

    // Copy Constructor
    Array(const Array &A)
    {
        size = A.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
            ptr[i] = A.ptr[i];
        cout << "Copy Ctor called.\n";
    }

    // 2. Destructor
    ~Array() { delete[] ptr; }

    // 3. Setter (via subscript)
    int &operator[](int j) { return ptr[j]; }

    // 4. Getter (cin)
    void fill()
    {
        cout << "Filling array of size " << size << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Val " << i << ": ";
            cin >> ptr[i];
        }
    }

    // 5. Show
    void show()
    {
        for (int i = 0; i < size; i++)
            cout << ptr[i] << " ";
        cout << endl;
    }

    // Assignment Operator
    Array &operator=(const Array &A)
    {
        if (this == &A)
            return *this; // self-assignment
        delete[] ptr;
        size = A.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
            ptr[i] = A.ptr[i];
        cout << "Assignment Op called.\n";
        return *this;
    }
};

int main()
{
    Array a1(5);
    a1.fill();

    Array a2(a1); // Copy Ctor
    cout << "A2 (Copy of A1): ";
    a2.show();

    Array a3(5);
    a3 = a1; // Assignment
    cout << "A3 (Assigned A1): ";
    a3.show();

    return 0;
}