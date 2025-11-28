#include <iostream>
using namespace std;

class Parent {
protected:
    int basedata;
public:
    Parent() : basedata(0) {}
    ~Parent() {}
    void set(int b) { basedata = b; }
    void get() { cin >> basedata; }
    void show() { cout << basedata; }
};

// Virtual Inheritance
class Child1 : virtual public Parent {
public: Child1() {} ~Child1() {}
};

class Child2 : virtual public Parent {
public: Child2() {} ~Child2() {}
};

class Grandchild : public Child1, public Child2 {
public:
    Grandchild() {}
    ~Grandchild() {}
    
    int getData() {
        return basedata; // OK: Only one copy of Parent exists
    }
    
    void set() {} void get() {} void show() {}
};

int main() {
    Grandchild gc;
    // gc.set(10); // Works because of virtual inheritance
    cout << "Data: " << gc.getData() << endl;
    return 0;
}