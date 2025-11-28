#include <iostream>
using namespace std;

int main()
{
    cout << "Chapter 8 Review Question Solutions:\n";
    cout << "------------------------------------\n";
    cout << "1.  c. giving new meanings to existing C++ operators.\n";
    cout << "2.  x3 = x1 - x2;\n";
    cout << "3.  x3 = x1.operator-(x2);\n";
    cout << "4.  True\n";
    cout << "5.  void operator -- () { --count; }\n";
    cout << "6.  None (for unary member functions)\n";
    cout << "7.  a. take two arguments (if friend), d. use object member (if member)\n";
    cout << "    Correct context usually implies member: d. use the object... as operand\n";
    cout << "8.  Distance operator ++ () { ++feet; return *this; }\n";
    cout << "9.  Distance operator ++ (int) { Distance t=*this; ++feet; return t; }\n";
    cout << "10. Prefix increments before value usage; Postfix increments after.\n";
    cout << "11. function name matches c. operator (+)\n";
    cout << "    return value matches d. return value (type String)\n";
    cout << "    first argument matches b. object of which operator is a member\n";
    cout << "    second argument matches a. argument (s)\n";
    cout << "12. True\n";
    cout << "13. c. goes in the object of which the operator is a member.\n";
    cout << "14. String operator ++ () { for(int i=0; i<strlen(str); i++) str[i]=toupper(str[i]); return *this; }\n";
    cout << "15. d. a conversion operator that's a member of the class.\n";
    cout << "16. True (unless assignment operator is overloaded/handled)\n";
    cout << "17. b. a one-argument constructor.\n";
    cout << "18. True\n";
    cout << "19. A conversion operator in class B (operator A()).\n";
    cout << "20. True (but it's bad practice)\n";
    cout << "21. d. one class calls a member function in the other class.\n";
    cout << "22. attributes, operations\n";
    cout << "23. False (they are rectangles)\n";
    cout << "24. a. an object of class A can call an operation in an object of class B.\n";
    return 0;
}