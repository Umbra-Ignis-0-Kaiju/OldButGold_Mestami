#include <iostream>
#include <cstdlib>          //for srand(), rand()
#include <ctime>           //for time for srand()
#include <string>
#include <clocale>
#include <iomanip>
using namespace std;

enum Suit { clubs, diamonds, hearts, spades };
//from 2 to 10 are integers without names 
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
////////////////////////////////////////////////////////////////
class card
{
private:
    int number;        //2 to 10, jack, queen, king, ace
    Suit suit;         //clubs, diamonds, hearts, spades
public:
    card()                      //constructor
    { }
    void set(int n, Suit s)     //set card
    {
        suit = s; number = n;
    }
    void display();             //display card
};
//--------------------------------------------------------------
void card::display()              //display the card
{
    if (number >= 2 && number <= 10)
        cout << number;
    else
        switch (number)
        {
        case jack:  cout << "J"; break;
        case queen: cout << "Q"; break;
        case king:  cout << "K"; break;
        case ace:   cout << "A"; break;
        }
    switch (suit)
    {
    case clubs:    cout << static_cast<char>(5); break;
    case diamonds: cout << static_cast<char>(4); break;
    case hearts:   cout << static_cast<char>(3); break;
    case spades:   cout << static_cast<char>(6); break;
    }
}
////////////////////////////////////////////////////////////////
int main()
{
    card deck[52], first[13], second[13], third[13], fourth[13];
    int j;
    cout << endl;
    for (j = 0; j < 52; j++)         //make an ordered deck
    {
        int num = (j % 13) + 2;  //cycles through 2 to 14, 4 times
        Suit su = Suit(j / 13);  //cycles through 0 to 3, 13 times
        deck[j].set(num, su);    //set card
    }
    cout << "\nOrdered deck:\n";
    for (j = 0; j < 52; j++)         //display ordered deck
    {
        deck[j].display();
        cout << "  ";
        if (!((j + 1) % 13))     //newline every 13 cards
            cout << endl;
    }
    srand(time(NULL));        //seed random numbers with time
    for (j = 0; j < 52; j++)         //for each card in the deck,
    {
        int k = rand() % 52;     //pick another card at random
        card temp = deck[j];     //and swap them
        deck[j] = deck[k];
        deck[k] = temp;
    }
    for (j = 0; j < 52; j++)         //for each card in the deck,
    {
        if (((j + 1) % 4) == 1)
        {
            first[j / 4] = deck[j];
        }
        if (((j + 1) % 4) == 2)
        {
            second[j / 4] = deck[j];
        }
        if (((j + 1) % 4) == 3)
        {
            third[j / 4] = deck[j];
        }
        if (((j + 1) % 4) == 0)
        {
            fourth[j / 4] = deck[j];
        }
    }
    cout << "\nPlayers hands:\n. 1 .... 2 .... 3 .... 4 .\n";
    for (j = 0; j < 13; j++)         //display shuffled deck
    {
        cout << setfill('.') << setw(3);
        first[j].display();
        cout << setfill('.') << setw(6);
        second[j].display();
        cout << setfill('.') << setw(6);
        third[j].display();
        cout << setfill('.') << setw(6);
        fourth[j].display();
        cout << ".";
        cout << endl;
    }
    return 0;
}