/*
FILE: 00-mcq-and-questions.cpp
DESCRIPTION: Answers to Chapter 6 Review Questions

1. Purpose of class: To specify the blueprint for objects (data + functions).
2. A "class" has the same relation to an "object" that a basic data type has to a variable.
3. c. to member functions of that class.
4.
   class leverage {
   private:
       int crowbar;
   public:
       void pry();
   };
5. False (they are usually private, but can be public).
6. leverage lever1;
7. d. A class object and a member of that class.
8. lever1.pry();
9. inline
10. int getcrow() { return crowbar; }
11. created (instantiated).
12. the class.
13. leverage() : crowbar(0) {}
14. True (overloading).
15. c. in any object of the class of which it is a member.
16. int getcrow();
17. int leverage::getcrow() { return crowbar; }
18. in a class members are private by default; in a struct they are public.
19. Data items: 3 sets. Member functions: 1 set.
20. calling a member function.
21. d. can closely model objects in the real world.
22. False.
23. d. can modify neither const nor non-const member data.
24. True.
25. void aFunc(const float jerry) const;
*/