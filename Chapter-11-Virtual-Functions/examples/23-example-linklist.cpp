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

    // 2. Destructor
    ~LinkList()
    {
        Link *current = first;
        while (current != NULL)
        {
            Link *temp = current;
            current = current->next;
            delete temp;
        }
    }

    // 3. Setter (AddItem)
    void addItem(int d)
    {
        Link *newLink = new Link;
        newLink->data = d;
        newLink->next = first;
        first = newLink;
    }

    // 4. Getter
    void getDummy()
    {
        int x;
        cin >> x;
    }

    // 5. Show
    void display()
    {
        Link *current = first;
        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
    void show() { display(); }
};

int main()
{
    LinkList li;
    li.addItem(25);
    li.addItem(36);
    li.addItem(49);
    li.addItem(64);

    li.display();
    return 0;
}