#include <iostream>
#include <cstring>
using namespace std;

class DaySorter
{
private:
    const char **arr; // Pointer to array of pointers
    int size;

public:
    // 1. Constructor
    DaySorter(const char *days[], int s) : size(s)
    {
        // Allocate array of pointers
        arr = new const char *[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = days[i];
        }
    }

    // 2. Destructor
    ~DaySorter()
    {
        delete[] arr;
    }

    // 3. Setter (Sort logic)
    void sort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                // Compare strings using pointers
                if (strcmp(*(arr + i), *(arr + j)) > 0)
                {
                    const char *temp = *(arr + i);
                    *(arr + i) = *(arr + j);
                    *(arr + j) = temp;
                }
            }
        }
    }

    // 4. Getter (Dummy for format)
    void getDummy()
    {
        cout << "Sorting array of pointers..." << endl;
    }

    // 5. Show
    void show() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << *(arr + i) << endl;
        }
    }
};

int main()
{
    const char *days[7] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"};

    DaySorter ds(days, 7);

    cout << "--- Unsorted ---\n";
    ds.show();

    ds.sort();

    cout << "\n--- Sorted ---\n";
    ds.show();

    return 0;
}