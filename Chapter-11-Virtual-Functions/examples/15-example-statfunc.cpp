#include <iostream>
using namespace std;

class Gamma
{
private:
    static int total;
    int id;

public:
    Gamma()
    {
        total++;
        id = total;
    }
    ~Gamma()
    {
        total--;
        cout << "Destroying ID " << id << endl;
    }

    void setID(int i) { id = i; } // Setter
    void getIDInput()
    {
        cout << "Enter ID: ";
        cin >> id;
    }                                             // Getter
    void show() { cout << "ID: " << id << endl; } // Show

    static void showTotal()
    {
        cout << "Total is " << total << endl;
    }
};

int Gamma::total = 0;

int main()
{
    Gamma g1;
    Gamma::showTotal();

    Gamma g2, g3;
    Gamma::showTotal();

    g1.show();
    g2.show();
    g3.show();

    return 0;
}