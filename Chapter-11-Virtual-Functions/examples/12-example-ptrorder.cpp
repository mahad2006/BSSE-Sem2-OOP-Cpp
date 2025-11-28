#include <iostream>
using namespace std;

class Orderer
{
private:
    int n1, n2, n3, n4;

public:
    // 1. Constructor
    Orderer() : n1(99), n2(11), n3(22), n4(88) {}

    // 2. Destructor
    ~Orderer() {}

    // 3. Setter (Order logic)
    void order(int *numb1, int *numb2)
    {
        if (*numb1 > *numb2)
        {
            int temp = *numb1;
            *numb1 = *numb2;
            *numb2 = temp;
        }
    }

    // 4. Getter
    void getInput() { cin >> n1 >> n2; }

    // 5. Show
    void show()
    {
        order(&n1, &n2);
        order(&n3, &n4);
        cout << "n1=" << n1 << "\nn2=" << n2 << endl;
        cout << "n3=" << n3 << "\nn4=" << n4 << endl;
    }
};

int main()
{
    Orderer ord;
    ord.show();
    return 0;
}