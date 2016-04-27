/*
Alex Ray
Data Structures
Final Project--deck of cards simulation
*/

#include "DeckOfCards.h"
#include "Helper.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    DeckOfCards *deck = new DeckOfCards();
    Helper *helper = new Helper();

    // Getting user input
    int input;
    string inputStr;

    do {
        // Input checking
        while (true) {
            cout << "======Main Menu======" << endl;
            cout << "1. Print deck" << endl;
            cout << "2. Perfectly shuffle deck" << endl;
            cout << "3. Riffle shuffle" << endl;
            cout << "4. Overhand shuffle" << endl;
            cout << "5. Pick random card" << endl;
            cout << "6. Choose card from specified position" << endl;
            cout << "7. Get specified card from deck" << endl;
            cout << "8. Deal cards" << endl;
            cout << "9. Play some blackjack" << endl;
            cout << "10. Return deck to original state" << endl;
            cout << "11. Quit" << endl;
            getline(cin, inputStr);

            input = atoi(inputStr.c_str()); // String to int
            if (input > 0 && input < 12 && helper->isInt(inputStr))
                break;
        }

        if (input == 1) {
            deck->printDeck();
        }
        else if (input == 2) {
            deck->perfectShuffle();
        }
        else if (input == 3) {
            deck->riffleShuffle();
        }
        else if (input == 4) {
            deck->overhandShuffle();
        }
        else if (input == 5) {
            Card *tmp = deck->pickRandomCard();
            cout << "You got: " << tmp->name << " of " << tmp->suit << "s!" << endl;
        }
        else if (input == 6) {
            int pos;
            string posString;

            // Input checking
            while (true) {
                cout << "Please enter the position of the card in the deck (number between 1 and 52)" << endl;
                getline(cin, posString);

                pos = atoi(posString.c_str()); // String to int
                if (pos > 0 && pos < 53 && helper->isInt(posString))
                    break;
            }

            Card *tmp = deck->pickCardFromPosition(pos - 1);
            cout << "You picked: " << tmp->name << " of " << tmp->suit << "s!" << endl;
        }
        else if (input == 7) {
            string name;
            string suit;

            cout << "Please enter the name of the card" << endl;
            //cin.ignore();
            getline(cin, name);
            name = helper->toLowerCase(name); // making input string lower case
            name = helper->alphaToDigit(name); // Changing "one" to "1", etc

            cout << "Please enter the suit of the card" << endl;
            //cin.ignore();
            getline(cin, suit);
            suit = helper->toLowerCase(suit);
            suit = helper->suitPluralToSingular(suit);
            cout << name << endl;
            cout << suit << endl;

            Card *tmp = deck->getCard(name, suit);
            if (tmp != NULL)
                cout << tmp->name << " of " << tmp->suit << "s was found!" << endl;
            else
                cout << "Card not found!" << endl;
        }
        else if (input == 8) {
            int num;
            string numString;

            // Input checking
            while (true) {
                cout << "Please enter the number of cards you'd like to deal (number between 1 and 52)" << endl;
                cout << "Dealt cards will be pushed to the bottom of the deck" << endl;
                getline(cin, numString);

                num = atoi(numString.c_str()); // String to int
                if (num > 0 && num < 53 && helper->isInt(numString))
                    break;
            }

            queue<Card*> q = deck->dealCards(num);
            Card *tmp;
            int counter = 1;
            while (!q.empty()) {
                tmp = q.front();
                q.pop();
                cout << "Card number " << counter << " is " << tmp->name << " of " << tmp->suit << "s" << endl;
                counter++;
            }
        }
        else if (input == 9) {
            cout << "In this blackjack game, ace will only count as 11 (tough luck if you bust on the deal)" << endl;
            cout << "You (the player), starts with $200. Each round, you bet $10." << endl;
            cout << "If you win, you gain $10. If you lose, you lose $10. If you draw (push), you don't exchange any money" << endl;
            deck->blackjack();
        }
        else if (input == 10) {
            deck->rebuildDeck();
        }
        else {

        }
    }
    while (input != 11);
}

