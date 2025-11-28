#include <iostream>
using namespace std;

struct Link
{
    int data;
    Link *next;
};

class LinkList
{
private:
    Link *first;

public:
    // 1. Constructor
    LinkList() { first = NULL; }

    // Copy Constructor (Deep Copy)
    LinkList(const LinkList &L)
    {
        first = NULL;
        copyFrom(L);
    }

    // 2. Destructor
    ~LinkList()
    {
        Link *current = first;
        while (current)
        {
            Link *temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Helper for deep copy
    void copyFrom(const LinkList &L)
    {
        if (L.first == NULL)
            return;

        // Copy first link
        first = new Link;
        first->data = L.first->data;
        first->next = NULL;

        Link *source = L.first->next;
        Link *dest = first;

        while (source)
        {
            Link *newLink = new Link;
            newLink->data = source->data;
            newLink->next = NULL;
            dest->next = newLink;
            dest = newLink;
            source = source->next;
        }
    }

    // 3. Setter (Add item)
    void add(int d)
    {
        Link *newLink = new Link;
        newLink->data = d;
        newLink->next = first;
        first = newLink;
    }

    // 4. Getter (cin)
    void get()
    {
        int v;
        cout << "Enter val: ";
        cin >> v;
        add(v);
    }

    // 5. Show
    void show()
    {
        Link *current = first;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Assignment Operator
    LinkList &operator=(const LinkList &L)
    {
        if (this == &L)
            return *this;
        // Delete old
        Link *current = first;
        while (current)
        {
            Link *temp = current;
            current = current->next;
            delete temp;
        }
        first = NULL;
        copyFrom(L);
        return *this;
    }
};

int main()
{
    LinkList l1;
    l1.add(10);
    l1.add(20);

    LinkList l2 = l1; // Copy Ctor
    cout << "L2 (Copy): ";
    l2.show();

    LinkList l3;
    l3 = l1; // Assignment
    cout << "L3 (Assign): ";
    l3.show();

    return 0;
}