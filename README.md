# Ray_CSCI2270_FinalProject

## Initial project summary
I'm planning on simulating a deck of cards using an array. There will be methods to build the deck, shuffle the deck (possibly simulating different types of shuffling), print the deck, find a card, and pick a random card. Beyond that, I will implement a game of blackjack.

The reason for using an array is that the deck of cards itself is a static size (52 cards), so there's no need for the resizability of a linked list or vector. A more flexible data structure could be helpful for representing sets of cards with changing size (e.g. dealt cards), but an array is fine for keeping track of the entire deck.  

## Installation instructions
1. Fork Ray_CSCI2270_FinalProject into a directory on either your class VM or personal computer (Mac should work, any Linux distro should work, Windows *should* work with cygwin). This was developed on a Mac.
2. Make Ray_CSCI2270_FinalProject your working directory (`cd Path/To/Ray_CSCI2270_FinalProject`)
3. Enter `make`
4. Enter `./DeckOfCards`

*Before submitting a pull request enter `make clean`*

*Please let me know if you have any issues setting anything up*

## Known issues / Areas for improvement
+ Helper::alphaToDigit in Helper.cpp can be done more elegantly with case statements
+ Some functions (namely DeckOfCards::blackjack) are gigantic, so a code refactor would be ideal
+ It would be best if the card inputs would *only* allow names and suits of cards
+ Some lines are obnoxiously long
+ The "print deck" output is unwieldy, making it so everything fits on one page would be ideal
+ Allowing for the ace to be 1 or 11 in blackjack would be a great improvement
+ Build deck function is not ideal; building deck with an array of suits and an array of names would be much much better
