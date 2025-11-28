#include <iostream>
using namespace std;

class A
{
public:
    void func() { cout << "Function in A\n"; }
    // Required format fillers
    A() {}
    ~A() {}
    void set() {}
    void get() {}
    void show() {}
};

class B : public A
{
};
class C : public A
{
};

class D : public B, public C
{
public:
    // Ambiguity exists here because D inherits A twice (via B and C)
    D() {}
    ~D() {}
    void set() {}
    void get() {}
    void show() {}
};

int main()
{
    D objD;
    // objD.func(); // Error: Ambiguous

    // Resolution
    objD.B::func();
    objD.C::func();

    return 0;
}