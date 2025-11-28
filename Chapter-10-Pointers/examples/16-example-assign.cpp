#include <iostream>
using namespace std;

class Alpha
{
private:
    int data;

public:
    Alpha() : data(0) {}
    Alpha(int d) : data(d) {}
    ~Alpha() {}

    void setData(int d) { data = d; }
    void getData() { cin >> data; }
    void show() { cout << data; }

    Alpha operator=(Alpha &a)
    {
        data = a.data;
        cout << "\nAssignment operator invoked";
        return Alpha(data);
    }
};

int main()
{
    Alpha a1(37);
    Alpha a2;

    a2 = a1; // Overloaded =
    cout << "\na2=";
    a2.show();

    Alpha a3 = a2; // Copy initialization, not assignment
    cout << "\na3=";
    a3.show();
    cout << endl;
    return 0;
}