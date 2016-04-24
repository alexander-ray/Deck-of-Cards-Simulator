/*
Alex Ray
Data Structures
Final Project--deck of cards simulation
*/

#include "DeckOfCards.h"
#include <iostream>

using namespace std;

// Checking if a string is composed of digits
bool isInt (string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s.at(i))) // Checking if char is a digit
            return false;
    }
    return true;
}


int main() {
    DeckOfCards *deck = new DeckOfCards();

    // Getting user input
    int input;

    do {
        cout << "======Main Menu======" << endl;
        cout << "1. Print deck" << endl;
        cout << "2. Perfectly shuffle deck" << endl;
        cout << "3. Pick random card" << endl;
        cout << "4. Choose card from specified position" << endl;
        cout << "5. Return deck to original state" << endl;
        cout << "6. Quit" << endl;
        cin >> input;

        if (input == 1) {
            deck->printDeck();
        }
        else if (input == 2) {
            deck->perfectShuffle();
        }
        else if (input == 3) {
            Card *tmp = deck->pickRandomCard();
            cout << "You got: " << tmp->name << " of " << tmp->suit << "s!" << endl;
        }
        else if (input == 4) {
            int pos;
            string posString;
            cin.ignore();

            // Input checking
            while (true) {
                cout << "Please enter the position of the card in the deck (number between 1 and 52)" << endl;
                getline(cin, posString);

                pos = atoi(posString.c_str()); // String to int
                if (pos > 0 && pos < 53 && isInt(posString))
                    break;
            }

            Card *tmp = deck->pickCardFromPosition(pos - 1);
            cout << "You picked: " << tmp->name << " of " << tmp->suit << "s!" << endl;
        }
        else if (input == 5) {
            deck->rebuildDeck();
        }
        else
            cout << "Goodbye!" << endl;
    }
    while (input != 6);
}

