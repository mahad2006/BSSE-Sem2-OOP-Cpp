#include <iostream>
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
    Card(int n, Suit s) : number(n), suit(s) {}

    // 2. Destructor
    ~Card() {}

    // 3. Setter
    void setCard(int n, Suit s)
    {
        number = n;
        suit = s;
    }

    // 4. Getter (Simulated input)
    void getCardInput()
    {
        int n;
        int s;
        cout << "Enter number (2-14) and suit (0-3): ";
        cin >> n >> s;
        number = n;
        suit = static_cast<Suit>(s);
    }

    // 5. Show
    void display()
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
            cout << " of clubs";
            break;
        case diamonds:
            cout << " of diamonds";
            break;
        case hearts:
            cout << " of hearts";
            break;
        case spades:
            cout << " of spades";
            break;
        }
    }

    bool isEqual(Card c2)
    {
        return (number == c2.number && suit == c2.suit);
    }
};

int main()
{
    Card temp, chosen, prize;
    int position;

    Card card1(7, clubs);
    cout << "\nCard 1 is ";
    card1.display();

    Card card2(jack, hearts);
    cout << "\nCard 2 is ";
    card2.display();

    Card card3(ace, spades);
    cout << "\nCard 3 is ";
    card3.display();

    prize = card3;

    cout << "\nI'm swapping cards...";
    // Swap logic simulated
    temp = card3;
    card3 = card1;
    card1 = temp;
    temp = card3;
    card3 = card2;
    card2 = temp;
    temp = card2;
    card2 = card1;
    card1 = temp;

    cout << "\nWhere (1, 2, or 3) is the ";
    prize.display();
    cout << "? ";
    cin >> position;

    switch (position)
    {
    case 1:
        chosen = card1;
        break;
    case 2:
        chosen = card2;
        break;
    case 3:
        chosen = card3;
        break;
    }

    if (chosen.isEqual(prize))
        cout << "That's right! You win!";
    else
        cout << "Sorry. You lose.";

    cout << " You chose ";
    chosen.display();
    cout << endl;

    return 0;
}