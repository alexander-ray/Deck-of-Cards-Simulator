#include "DeckOfCards.h"
#include "Helper.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

Helper *helper = new Helper();

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

// Pick card from specified position
Card* DeckOfCards::pickCardFromPosition(int pos) {
    Card *tmp = deck[pos];
    shiftDeckFromPosition(pos); // Put chosen card at back of deck
    return tmp;
}

// Pick random card from the deck
Card* DeckOfCards::pickRandomCard() {
    srand(time(NULL)); // Seeding rand()
    int randNum = rand()%(deckSize + 1); // Getting random number between 0 and 51

    Card *tmp = deck[randNum];
    shiftDeckFromPosition(randNum); // Put chosen card at bottom of deck
    return tmp;
}

// Find card with specified name and suit
Card* DeckOfCards::getCard(string n, string s) {
    Card *tmp;
    bool found = false;
    int i;
    for (i = 0; i < deckSize; i++) { // Iterating through deck
        if (deck[i]->name == n && deck[i]->suit == s) { // If both name and suit match
            found = true;
            tmp = deck[i];
            break;
        }
    }
    // Return null if not found
    if (!found)
        return NULL;
    else {
        shiftDeckFromPosition(i);
        return tmp;
    }
}

// Shuffle deck perfectly (non-realistic)
void DeckOfCards::perfectShuffle() {
    srand(time(NULL)); // Seeding rand() with time
    random_shuffle(deck, deck+52); // Shuffle the deck
}

// Simulates the classic riffle shuffle
// Mixing top half of deck with bottom half of deck
// A perfect riffle shuffle needs to have an unordered deck as a starting point to ensure that resulting order isn't predictable
void DeckOfCards::riffleShuffle() {
    Card *tmp[deckSize];
    int counter = 0;
    for (int i = 0; i < deckSize / 2; i++) {    
        tmp[counter] = deck[i];
        tmp[counter+1] = deck[i + 26];
        counter = counter + 2;
    }

    // Copying tmp to deck
    for (int i = 0; i < deckSize; i++)
        deck[i] = tmp[i];
}

// Shuffles in a general "front of deck goes to back of deck"
// Needs an unordered deck as starting point to ensure resulting order isn't predictable
void DeckOfCards::overhandShuffle() {
    std::vector<Card*> v; // Vector to hold cards
    int top = 26; // Top must be big to see switches from front to back
    int cardRemainder = deckSize - top;
    while (top > 0) {
        while (cardRemainder > 0) {
            // Copy back of deck to front of v
            for (int i = 0; i < cardRemainder; i++) { 
                v.push_back(deck[i + top]); 
            }
            // Copy front of deck to back of v
            for (int i = 0; i < top; i++) 
                v.push_back(deck[i]);
            // Copy v to deck
            for (int j = 0; j < v.size(); j++) {
                deck[j] = v.at(j);
            }
            v.clear();
            cardRemainder = cardRemainder - top;
        }
        top--;
        cardRemainder = deckSize - top;
    }
}

// First element of deck becomes last element
// Deck shifts forward by 1
void DeckOfCards::shiftDeck() {
    Card *tmp[deckSize];
    for (int i = 0; i < deckSize - 1; i++) {
        tmp[i] = deck[i+1];
    }
    tmp[deckSize - 1] = deck[0];
    for (int i = 0; i < deckSize; i++)
        deck[i] = tmp[i];
}

// Same as shiftDeck(), except deck[0] is replaced by deck[pos]
void DeckOfCards::shiftDeckFromPosition(int pos) {
    Card *tmp[deckSize];
    // Copying deck up to position
    for (int i = 0; i < pos; i++) 
        tmp[i] = deck[i];
    
    // Copying deck except deck[pos]
    for (int i = pos; i < deckSize - 1; i++) 
        tmp[i] = deck[i+1];

    tmp[deckSize - 1] = deck[pos];
    // Copying tmp to deck
    for (int i = 0; i < deckSize; i++)
        deck[i] = tmp[i];
}

// Deal specified number of cards from deck
// Returns queue of cards
queue<Card*> DeckOfCards::dealCards(int numCards) {
    queue<Card*> tmp; // Queue to ensure order of cards stays
    for (int i = 0; i < numCards; i++) {
        tmp.push(deck[0]);
        shiftDeck();
    }
    return tmp;
}

// Full blackjack game
void DeckOfCards::blackjack() {
    int bet = 200;
    int keepPlaying = true;
    //cin.ignore();

    // While there is still money && you want to continue playing
    while (bet > 0 && keepPlaying) {
        // Vectors to hold hands
        std::vector<Card*> playerHand; 
        std::vector<Card*> dealerHand;
        int currentIndex = 0;
        bool playerBlackjack = false;
        bool playerBusted = false;
        
        // Dealing 2 cards to the player and the dealer
        while (currentIndex < 4) {
            if (currentIndex % 2 == 0)
                playerHand.push_back(deck[currentIndex]);
            else
                dealerHand.push_back(deck[currentIndex]);
            currentIndex++;
        }

        // Showing player the deal
        cout << "Dealer cards: " << dealerHand.at(1)->name << " of " << dealerHand.at(1)->suit << "s | UNKNOWN CARD" << endl;
        cout << "Player cards: " << playerHand.at(0)->name << " of " << playerHand.at(0)->suit << "s | ";
        cout << playerHand.at(1)->name << " of " << playerHand.at(1)->suit << "s" << endl;

        // Seeing if anyone has 21 or greater, dealing with it
        int playerCardWeight = 0;
        int dealerCardWeight = 0;
        for (int i = 0; i < playerHand.size(); i++)
            playerCardWeight += playerHand.at(i)->weight;
        for (int i = 0; i < dealerHand.size(); i++)
            dealerCardWeight += dealerHand.at(i)->weight;

        if (playerCardWeight > 21 && dealerCardWeight > 21) {
            cout << "Both player and dealer bust, the hand is a push" << endl;
        }
        else if (playerCardWeight == 21 && dealerCardWeight != 21) {
            cout << "Player has a blackjack, player wins the hand" << endl;
            bet += 10;
        }

        // Letting player build hand
        int input;
        do {
            // Input checking
            string inputStr;
            while (true) {
                cout << "1. Hit" << endl;
                cout << "2. Stand" << endl;
                getline(cin, inputStr);

                input = atoi(inputStr.c_str()); // String to int
                if (input > 0 && input < 3 && helper->isInt(inputStr))
                    break;
            }

            if (input == 1) {
                playerHand.push_back(deck[currentIndex]);
                currentIndex++;
                cout << "Player got: " << playerHand.at(playerHand.size()-1)->name << " of " << playerHand.at(playerHand.size()-1)->suit << "s" << endl;
                cout << "Player's hand is now: ";
                for (int i = 0; i < playerHand.size() - 1; i++)
                    cout << playerHand.at(i)->name << " of " << playerHand.at(i)->suit << "s | ";
                cout << playerHand.at(playerHand.size() - 1)->name << " of " << playerHand.at(playerHand.size() - 1)->suit << "s" << endl;
                playerCardWeight += playerHand.at(playerHand.size() - 1)->weight;
                
                // Checking if player busted or got blackjack
                if (playerCardWeight > 21) {
                    playerBusted = true;
                    cout << "Player busted, dealer wins" << endl;
                    bet -= 10;
                    break;
                }
                // If blackjack, don't continue with options
                else if (playerCardWeight == 21) {
                    playerBlackjack = true;                
                    break;
                }
            }
        }
        while(input != 2);

        // If player's cards aren't above 21
        if (!playerBusted) {
            // Revealing dealer's hand
            cout << "Dealer cards: " << dealerHand.at(0)->name << " of " << dealerHand.at(0)->suit << "s | ";
            cout << dealerHand.at(1)->name << " of " << dealerHand.at(1)->suit << "s" << endl;

            if (dealerCardWeight == 21 && !playerBlackjack) {
                cout << "Dealer has a blackjack, dealer wins the round" << endl;
                bet -= 10;
            }
            else if (playerBlackjack && dealerCardWeight == 21) {
                cout << "Both players have a blackjack, the round is a push" << endl;
            }

            // Letting dealer build hand
            // Dealer builds hand according to normal casino rules
            while (dealerCardWeight < 17) {
                cout << "Dealer chose to hit" << endl;
                dealerHand.push_back(deck[currentIndex]);
                dealerCardWeight += deck[currentIndex]->weight;
                currentIndex++;

                // Printing dealer cards
                cout << "Dealer got: " << dealerHand.at(dealerHand.size()-1)->name << " of " << dealerHand.at(dealerHand.size()-1)->suit << "s" << endl;
                cout << "Dealer's hand is now: ";
                for (int i = 0; i < dealerHand.size() - 1; i++)
                    cout << dealerHand.at(i)->name << " of " << dealerHand.at(i)->suit << "s | ";
                cout << dealerHand.at(dealerHand.size() - 1)->name << " of " << dealerHand.at(dealerHand.size() - 1)->suit << "s" << endl;
            }

            // Checking dealer cards vs player cards
            if (dealerCardWeight > 21) {
                cout << "Dealer busted, player wins" << endl;
                bet += 10;
            }
            else if (dealerCardWeight == 21 && playerBlackjack) {
                cout << "Player and dealer got blackjack, round is a push" << endl;
            }
            else if (playerBlackjack && dealerCardWeight < 21) {
                cout << "Player wins" << endl;
                bet += 10;
            }
            else if (playerCardWeight == dealerCardWeight) {
                cout << "Hands are equal, round is a push" << endl;
            }
            else if (playerCardWeight > dealerCardWeight) {
                cout << "Player has better hand, player wins" << endl;
                bet += 10;
            }
            else if (dealerCardWeight > playerCardWeight) {
                cout << "Dealer has better hand, dealer wins" << endl;
                bet -= 10;
            }
        }

        if (bet <= 0) {
            cout << "You're out of money, thanks for playing" << endl;
            return;
        }

        // Checking to see if player wants to continue
        do {
            // Input checking
            string inputStr;
            while (true) {
                cout << "1. I would like to continue" << endl;
                cout << "2. I would like to end the game" << endl;
                getline(cin, inputStr);

                input = atoi(inputStr.c_str()); // String to int
                if (input > 0 && input < 3 && helper->isInt(inputStr))
                    break;
            }

            if (input == 1) {
                cout << "You have $" << bet << " going into the next round" << endl;
                perfectShuffle();
            }
            else if (input == 2) {
                keepPlaying = false;
                cout << "You ended with: $" << bet << endl;
                cout << "Thanks for playing" << endl;
            }
        }
        while(input != 2 && input != 1);
    }
}

// Return deck to original state
void DeckOfCards::rebuildDeck() {
    // Delete everything in deck
    for (int i = 0; i < deckSize; i++)
        delete deck[i];
    buildDeck(); // Rebuild
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
