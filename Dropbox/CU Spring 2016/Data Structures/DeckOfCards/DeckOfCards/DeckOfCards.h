#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

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
};

class DeckOfCards {
    public:
        DeckOfCards();
        ~DeckOfCards();

};

#endif // DECKOFCARDS_H
