#include <iostream>
using namespace std;

const int MEMSIZE = 100;
float fmemory[MEMSIZE]; // Global float memory
int pmemory[MEMSIZE];   // Global pointer memory (stores indices)
int fmem_top = 0;
int pmem_top = 0;

class Float
{
private:
    int addr; // index in fmemory

public:
    // 1. Constructor
    Float(float val)
    {
        fmemory[fmem_top] = val;
        addr = fmem_top;
        fmem_top++;
    }

    // 2. Destructor
    ~Float() {}

    // 3. Setter (Update value in memory)
    void setVal(float val)
    {
        fmemory[addr] = val;
    }

    // 4. Getter (Address operator overload)
    int operator&() { return addr; }

    // Dummy getter for format
    void getInput()
    {
        float v;
        cout << "Enter Float val: ";
        cin >> v;
        setVal(v);
    }

    // 5. Show
    void show() { cout << fmemory[addr]; }
};

class ptrFloat
{
private:
    int p_addr; // index in pmemory, which holds index of fmemory

public:
    // 1. Constructor
    ptrFloat(int f_addr)
    {
        pmemory[pmem_top] = f_addr;
        p_addr = pmem_top;
        pmem_top++;
    }

    // 2. Destructor
    ~ptrFloat() {}

    // 3. Setter (Change what it points to)
    void setPtr(int f_addr)
    {
        pmemory[p_addr] = f_addr;
    }

    // 4. Getter (Dereference operator)
    float &operator*()
    {
        return fmemory[pmemory[p_addr]];
    }

    // Dummy getter
    void getDummy()
    {
        int x;
        cin >> x;
    }

    // 5. Show
    void show() { cout << "Ptr points to val: " << (*(*this)) << endl; }
};

int main()
{
    Float var1(1.234);
    Float var2(5.678);

    ptrFloat ptr1 = &var1; // &var1 returns index
    ptrFloat ptr2 = &var2;

    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    *ptr1 = 7.123; // Change value via pointer
    *ptr2 = 8.456;

    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    return 0;
}