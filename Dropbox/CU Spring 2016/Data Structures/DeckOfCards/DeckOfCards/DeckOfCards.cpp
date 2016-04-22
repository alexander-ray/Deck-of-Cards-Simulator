#include "DeckOfCards.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <random>

using namespace std;

// Constructor
DeckOfCards::DeckOfCards(){
    buildDeck();
}

// Destructor
DeckOfCards::~DeckOfCards(){};

// Print deck
void DeckOfCards::printDeck() {
    for (int i = 0; i < 52; i++) {
        cout << deck[i]->suit << "  " << deck[i]->name << endl;
    }
}

// Pick random card
Card* DeckOfCards::pickRandomCard() {
    srand(time(NULL)); // Seeding rand()
    int randNum = rand()%(deckSize + 1); // Getting random number between 0 and 52
    return deck[randNum];
}

// Build ordered Deck
void DeckOfCards::buildDeck() {
    int currentIndex = 0;
    for (int i = 1; i < 14; i++) {
        if (i == 1)
            deck[currentIndex] = new Card(11, "ace", "spade");
        else if (i > 1 && i < 11)
            deck[currentIndex] = new Card(i, i, "spade");
        else if (i == 11)
            deck[currentIndex] = new Card(10, "jack", "spade");
        else if (i == 12)
            deck[currentIndex] = new Card(10, "queen", "spade");
        else
            deck[currentIndex] = new Card(10, "king", "spade");
        currentIndex++;
    }
    for (int i = 1; i < 14; i++) {
        if (i == 1)
            deck[currentIndex] = new Card(11, "ace", "club");
        else if (i > 1 && i < 11)
            deck[currentIndex] = new Card(i, i, "club");
        else if (i == 11)
            deck[currentIndex] = new Card(10, "jack", "club");
        else if (i == 12)
            deck[currentIndex] = new Card(10, "queen", "club");
        else
            deck[currentIndex] = new Card(10, "king", "club");
        currentIndex++;
    }
    for (int i = 1; i < 14; i++) {
        if (i == 1)
            deck[currentIndex] = new Card(11, "ace", "diamond");
        else if (i > 1 && i < 11)
            deck[currentIndex] = new Card(i, i, "diamond");
        else if (i == 11)
            deck[currentIndex] = new Card(10, "jack", "diamond");
        else if (i == 12)
            deck[currentIndex] = new Card(10, "queen", "diamond");
        else
            deck[currentIndex] = new Card(10, "king", "diamond");
        currentIndex++;
    }
    for (int i = 1; i < 14; i++) {
        if (i == 1)
            deck[currentIndex] = new Card(11, "ace", "heart");
        else if (i > 1 && i < 11)
            deck[currentIndex] = new Card(i, i, "heart");
        else if (i == 11)
            deck[currentIndex] = new Card(10, "jack", "heart");
        else if (i == 12)
            deck[currentIndex] = new Card(10, "queen", "heart");
        else
            deck[currentIndex] = new Card(10, "king", "heart");
        currentIndex++;
    }
}
