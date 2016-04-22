#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H
#include <iostream>
#include <sstream>

using namespace std;

struct Card {
    int weight;
    string name;
    string suit;
    Card *next;
    Card *previous;

    Card() {
        next = NULL;
        previous = NULL;
    }
    Card (int num, string n, string s) {
        next = NULL;
        previous = NULL;
        weight = num;
        name = n;
        suit = s;
    }
    Card (int num, int n, string s) {
        stringstream ss;
        ss << n;

        next = NULL;
        previous = NULL;
        weight = num;
        name = ss.str();
        suit = s;
    }
};

class DeckOfCards {
    public:
        DeckOfCards();
        ~DeckOfCards();
        void printDeck();
    private:
        void buildDeck();
        Card* deck[52];
};

#endif // DECKOFCARDS_H
