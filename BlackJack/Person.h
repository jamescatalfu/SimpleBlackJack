#ifndef Person_hpp
#define Person_hpp

#include "Cards.h"
#include <vector>

class Dealer;

using std::vector;

class Person
{
    protected:
        vector<Cards> hand;
        int current_score;
        int final_score;
        int num_wins;

        static int games_played;
    
    public:
        Person();
        bool operator> (const Person& p);
        bool operator== (const Person& p);
        vector<Cards> operator+= (const Cards& c);
        virtual int take_turn(Dealer&, Person&);
    
        void clear_hand();
        void display_current_stats();
        void add_win();
        int calculate_current_score();
        int get_final_score();
        int get_num_wins();
    
        friend void check_for_win(Person& d, Person& p);
    
        static int get_games_played();
    
    
};

#endif
