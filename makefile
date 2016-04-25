OBJS = DeckOfCards.o Helper.o main.o 
CXX = g++
CXXFLAGS= -Wall -std=c++11

all: target

target: $(OBJS)
	$(CXX) $(OBJS) -o target

DeckOfCards.o: DeckOfCards.cpp DeckOfCards.h
	$(CXX) $(CXXFLAGS) -c DeckOfCards.cpp
	chmod ugo+rx DeckOfCards.o

main.o: main.cpp Helper.h DeckOfCards.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Helper.o: Helper.h
	$(CXX) $(CXXFLAGS) -c Helper.cpp

clean:
	rm *o target 
