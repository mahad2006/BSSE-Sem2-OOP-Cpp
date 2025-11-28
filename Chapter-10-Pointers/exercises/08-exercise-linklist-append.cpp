#include <iostream>
using namespace std;

struct Link
{
    int data;
    Link *next;
};

class LinkedList
{
private:
    Link *first;

public:
    // 1. Constructor
    LinkedList() { first = NULL; }

    // 2. Destructor
    ~LinkedList()
    {
        Link *current = first;
        while (current)
        {
            Link *temp = current;
            current = current->next;
            delete temp;
        }
    }

    // 3. Setter (Add item at END)
    void addItem(int d)
    {
        Link *newLink = new Link;
        newLink->data = d;
        newLink->next = NULL;

        if (first == NULL)
        {
            first = newLink;
        }
        else
        {
            Link *current = first;
            while (current->next != NULL)
            {
                current = current->next; // Move to end
            }
            current->next = newLink; // Append
        }
    }

    // 4. Getter
    void getUserInput()
    {
        cout << "Enter value to append: ";
        int val;
        cin >> val;
        addItem(val);
    }

    // 5. Show
    void show() const
    {
        Link *current = first;
        while (current)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList ll;
    ll.getUserInput(); // 1st
    ll.getUserInput(); // 2nd
    ll.getUserInput(); // 3rd

    cout << "List should be in order of entry:\n";
    ll.show();
    return 0;
}