#include <iostream>
using namespace std;

enum Suit
{
    clubs,
    diamonds,
    hearts,
    spades
};
const int MAX_CARDS = 52;

class Card
{
private:
    int number;
    Suit suit;

public:
    // 1. Constructor
    Card() : number(0), suit(clubs) {}
    Card(int n, Suit s) : number(n), suit(s) {}

    // 2. Destructor
    ~Card() {}

    // 3. Setter
    void set(int n, Suit s)
    {
        number = n;
        suit = s;
    }

    // 4. Getter (cin)
    void getInput()
    {
        int n, s;
        cout << "Enter number (2-14) and suit (0-3): ";
        cin >> n >> s;
        set(n, static_cast<Suit>(s));
    }

    // 5. Show
    void display() const
    {
        if (number >= 2 && number <= 10)
            cout << number;
        else if (number == 11)
            cout << "J";
        else if (number == 12)
            cout << "Q";
        else if (number == 13)
            cout << "K";
        else if (number == 14)
            cout << "A";

        cout << " of ";
        switch (suit)
        {
        case clubs:
            cout << "clubs";
            break;
        case diamonds:
            cout << "diamonds";
            break;
        case hearts:
            cout << "hearts";
            break;
        case spades:
            cout << "spades";
            break;
        }
    }
};

class Deck
{
private:
    Card deckArr[MAX_CARDS];
    int cardCount;

public:
    // 1. Constructor
    Deck() : cardCount(0)
    {
        // Initialize deck
        for (int s = 0; s <= spades; s++)
        {
            for (int n = 2; n <= 14; n++)
            {
                deckArr[cardCount++] = Card(n, static_cast<Suit>(s));
            }
        }
    }

    // 2. Destructor
    ~Deck() {}

    // 3. Setter (Shuffle simulation)
    void shuffle()
    {
        cout << "\nDeck shuffled (logic omitted).\n";
        // Actual shuffle logic would go here
    }

    // 4. Getter (cin)
    void getDummy()
    {
        int x;
        cout << "Dummy input: ";
        cin >> x;
    }

    // 5. Show (Display first few cards)
    void show()
    {
        cout << "\n--- First 4 Cards ---\n";
        for (int i = 0; i < 4; i++)
        {
            deckArr[i].display();
            cout << endl;
        }
    }
};

int main()
{
    Deck d;
    d.show();
    d.shuffle();
    d.show();
    return 0;
}