#include <iostream>
using namespace std;

class StringDisplay {
private:
    const char* str;

public:
    // 1. Constructor
    StringDisplay() : str("Idle people have the least leisure.") {}

    // 2. Destructor
    ~StringDisplay() {}

    // 3. Setter
    void setStr(const char* s) { str = s; }

    // 4. Getter
    void getDummy() { int x; cin >> x; }

    // 5. Show
    void show() {
        dispstr(str);
    }

    // Helper using pointer arithmetic
    void dispstr(const char* ps) {
        while(*ps) cout << *ps++;
        cout << endl;
    }
};

int main() {
    StringDisplay sd;
    sd.show();
    return 0;
}