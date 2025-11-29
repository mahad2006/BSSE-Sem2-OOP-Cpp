#include <iostream>
using namespace std;

class Serial
{
private:
    static int count; // Static variable to count objects
    int serialNumber; // Instance variable

public:
    // 1. Constructor
    Serial()
    {
        count++;
        serialNumber = count;
    }

    // 2. Destructor
    ~Serial() {}

    // 3. Setter (Not typically used for auto-generated serials, but included for format)
    void setSerial(int s)
    {
        serialNumber = s;
    }

    // 4. Getter (Dummy, input not needed for auto-serial)
    void getSerial()
    {
        // Automatically handled by constructor, but function kept for format
        cout << "Serial generated automatically." << endl;
    }

    // 5. Show
    void show() const
    {
        cout << "I am object number " << serialNumber << endl;
    }
};

// Initialize static member
int Serial::count = 0;

int main()
{
    Serial s1, s2, s3;

    s1.show();
    s2.show();
    s3.show();

    return 0;
}