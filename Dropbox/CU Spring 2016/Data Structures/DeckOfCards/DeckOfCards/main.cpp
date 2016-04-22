/*
Alex Ray
Data Structures
Final Project--deck of cards simulation
*/

#include "DeckOfCards.h"
#include <iostream>

using namespace std;

int main() {
    DeckOfCards *deck = new DeckOfCards();

    Card *tmp = deck->pickRandomCard();
    cout << tmp->suit << "  " << tmp->name << endl;
}
