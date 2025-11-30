#include <iostream>
using namespace std;

class Sorter
{
private:
    enum
    {
        N = 10
    };
    int arr[N];

public:
    // 1. Constructor
    Sorter()
    {
        int temp[] = {37, 84, 62, 91, 11, 65, 57, 28, 19, 49};
        for (int i = 0; i < N; i++)
            arr[i] = temp[i];
    }

    // 2. Destructor
    ~Sorter() {}

    // 3. Setter (Order helper)
    void order(int *numb1, int *numb2)
    {
        if (*numb1 > *numb2)
        {
            int temp = *numb1;
            *numb1 = *numb2;
            *numb2 = temp;
        }
    }

    // Sort function using pointer arithmetic
    void bsort(int *ptr, int n)
    {
        for (int j = 0; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
                order(ptr + j, ptr + k);
    }

    // 4. Getter
    void getDummy()
    {
        int x;
        cin >> x;
    }

    // 5. Show
    void show()
    {
        bsort(arr, N);
        for (int j = 0; j < N; j++)
            cout << arr[j] << " ";
        cout << endl;
    }
};

int main()
{
    Sorter s;
    s.show();
    return 0;
}