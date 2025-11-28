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

    // 2. Destructor (The Exercise Task)
    ~LinkedList()
    {
        Link *current = first;
        while (current != NULL)
        {
            Link *temp = current;
            current = current->next;
            cout << "Deleting link with data: " << temp->data << endl;
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

    // 4. Getter (User Input)
    void getUserInput()
    {
        int val;
        char ch;
        do
        {
            cout << "Enter integer to add: ";
            cin >> val;
            addItem(val);
            cout << "Add another (y/n)? ";
            cin >> ch;
        } while (ch == 'y');
    }

    // 5. Show
    void show() const
    {
        Link *current = first;
        cout << "List: ";
        while (current != NULL)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    // block scope to test destructor
    {
        LinkedList list;
        list.getUserInput();
        list.show();
        cout << "Exiting block..." << endl;
    }
    // Destructor called here
    cout << "Program End." << endl;
    return 0;
}