#ifndef Dealer_h
#define Dealer_h

#include "Person.h"
#include <vector>

class Player;

using std::vector;

class Dealer : public Person
{
    private:
        vector<Cards> deck;
    
    public:
        Dealer();
        void create_deck();
        void remove_card();
        void shuffle_deck();
        void hit(Person&);
        vector<Cards> get_deck();
        int take_turn(Dealer&, Person&);
    
        friend void deal_cards(Dealer&, Player&);
};

#endif
