#include <iostream>
using namespace std;

int main()
{
    cout << "Chapter 10 Review Question Solutions:\n";
    cout << "-------------------------------------\n";
    cout << "1.  cout << &testvar;\n";
    cout << "2.  the size of the type (e.g., 4 bytes for float)\n";
    cout << "3.  c. a variable for storing addresses.\n";
    cout << "4.  a. &var  b. *var  c. var&  d. char*\n";
    cout << "5.  constant, variable\n";
    cout << "6.  float* fptr;\n";
    cout << "7.  name\n";
    cout << "8.  *testptr\n";
    cout << "9.  pointer to, contents of (dereference)\n";
    cout << "10. c. dereference test. (or d. refer to value)\n";
    cout << "11. No. intptr is uninitialized (wild pointer).\n";
    cout << "12. any data type\n";
    cout << "13. No difference (array notation vs pointer notation).\n";
    cout << "14. for(int i=0; i<77; i++) cout << *(intarr+i);\n";
    cout << "15. Because intarr is a pointer constant (array name), not a variable.\n";
    cout << "16. reference, pointer\n";
    cout << "17. d. the compiler can perform arithmetic correctly...\n";
    cout << "18. void func(char*);\n";
    cout << "19. while(*s1) *s2++ = *s1++;\n";
    cout << "20. b. the first character in the string.\n";
    cout << "21. char* revstr(char*);\n";
    cout << "22. char* numptrs[3] = {\"One\", \"Two\", \"Three\"};\n";
    cout << "23. c. obtains memory for a new variable.\n";
    cout << "24. wasted (or fragmented)\n";
    cout << "25. memory\n";
    cout << "26. p->exclu();\n";
    cout << "27. objarr[7].exclu();\n";
    cout << "28. a. each link contains a pointer to the next link.\n";
    cout << "29. float* arr[8];\n";
    cout << "30. b. place pointers to them in an array and sort the array.\n";
    cout << "31. 0..9, 3..*\n";
    cout << "32. b. circumstances in which an object finds itself.\n";
    cout << "33. False (transitions are momentary)\n";
    cout << "34. a. a constraint on when a transition can occur.\n";
    return 0;
}