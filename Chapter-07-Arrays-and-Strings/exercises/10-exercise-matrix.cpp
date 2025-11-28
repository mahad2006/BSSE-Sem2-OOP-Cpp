#include <iostream>
#include <cstdlib>
using namespace std;

class Matrix
{
private:
    static const int MAX = 10;
    int mat[MAX][MAX];
    int rows, cols;

public:
    // 1. Constructor
    Matrix(int r, int c) : rows(r), cols(c)
    {
        if (r > MAX || c > MAX)
        {
            cout << "Too large";
            exit(1);
        }
    }

    // 2. Destructor
    ~Matrix() {}

    // 3. Setter (putEl)
    void putEl(int r, int c, int val)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            cout << "Bounds Error";
            exit(1);
        }
        mat[r][c] = val;
    }

    // 4. Getter (getEl + cin wrapper)
    int getEl(int r, int c)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            cout << "Bounds Error";
            exit(1);
        }
        return mat[r][c];
    }

    void getInput()
    {
        int r, c, v;
        cout << "Enter row, col, value: ";
        cin >> r >> c >> v;
        putEl(r, c, v);
    }

    // 5. Show
    void show()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix m(3, 4); // 3x4 matrix
    m.putEl(1, 1, 99);
    m.getInput();
    m.show();
    return 0;
}