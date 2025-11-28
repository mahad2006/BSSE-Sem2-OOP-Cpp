#include <iostream>
#include <cstdlib> // srand, rand
#include <ctime>   // time
using namespace std;

enum Suit
{
    clubs,
    diamonds,
    hearts,
    spades
};
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class Card
{
private:
    int number;
    Suit suit;

public:
    // 1. Constructor
    Card() : number(0), suit(clubs) {}

    // 2. Destructor
    ~Card() {}

    // 3. Setter
    void set(int n, Suit s)
    {
        number = n;
        suit = s;
    }

    // 4. Getter (Dummy)
    void getDummy()
    {
        int x;
        cin >> x;
    }

    // 5. Show
    void display() const
    {
        if (number >= 2 && number <= 10)
            cout << number;
        else
        {
            switch (number)
            {
            case jack:
                cout << "J";
                break;
            case queen:
                cout << "Q";
                break;
            case king:
                cout << "K";
                break;
            case ace:
                cout << "A";
                break;
            }
        }
        switch (suit)
        {
        case clubs:
            cout << static_cast<char>(5);
            break; // Club char
        case diamonds:
            cout << static_cast<char>(4);
            break; // Diamond char
        case hearts:
            cout << static_cast<char>(3);
            break; // Heart char
        case spades:
            cout << static_cast<char>(6);
            break; // Spade char
        }
    }
};

class Dealer
{
private:
    Card deck[52];
    Card hands[4][13];

public:
    // 1. Constructor
    Dealer()
    {
        for (int j = 0; j < 52; j++)
        {
            int num = (j % 13) + 2;
            Suit su = Suit(j / 13);
            deck[j].set(num, su);
        }
        srand(time(NULL));
    }

    // 2. Destructor
    ~Dealer() {}

    // 3. Setter (Shuffle & Deal)
    void shuffleAndDeal()
    {
        // Shuffle
        for (int j = 0; j < 52; j++)
        {
            int k = rand() % 52;
            Card temp = deck[j];
            deck[j] = deck[k];
            deck[k] = temp;
        }
        // Deal
        int cardIdx = 0;
        for (int hand = 0; hand < 4; hand++)
        {
            for (int card = 0; card < 13; card++)
            {
                hands[hand][card] = deck[cardIdx++];
            }
        }
    }

    // 4. Getter (Trigger)
    void getInput()
    {
        cout << "Press Enter to deal cards...";
        cin.get();
    }

    // 5. Show
    void showHands()
    {
        for (int h = 0; h < 4; h++)
        {
            cout << "\nPlayer " << h + 1 << ":\n";
            for (int c = 0; c < 13; c++)
            {
                hands[h][c].display();
                cout << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Dealer d;
    d.getInput();
    d.shuffleAndDeal();
    d.showHands();
    return 0;
}