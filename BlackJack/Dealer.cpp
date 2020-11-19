#include "Dealer.h"
#include "Player.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int Person::games_played = 0;

Dealer::Dealer()
{
    hand = {};
    current_score = 0;
    final_score = 0;
    deck = {};
}

void Dealer::create_deck()
{
    Cards c;
    deck.clear();
    ++games_played;
    
    for(int i = 0; i < 4; i++)
    {
            if(i == 0)
            {
                c.set_suit("Spades");
            }
            else if(i == 1)
            {
                c.set_suit("Hearts");
            }
            else if(i == 2)
            {
                c.set_suit("Clubs");
            }
            else if(i == 3)
            {
                c.set_suit("Diamonds");
            }
        
        
        for(int j = 0; j < 13; j++)
        {
            if(j == 9)
            {
                c.set_rank("Jack");
                c.set_value(10);
            }
            else if(j == 10)
            {
                c.set_rank("Queen");
                c.set_value(10);
            }
            else if(j == 11)
            {
                c.set_rank("King");
                c.set_value(10);
            }
            else if(j == 12)
            {
                c.set_rank("Ace");
                c.set_value(11);
            }
            else
            {
                c.set_rank(std::to_string(j + 2));
                c.set_value(j + 2);
            }
            
            c.set_card_name();
            deck.push_back(c);
        }
    }
}

void Dealer::remove_card()
{
    deck.erase(deck.begin());
}

void Dealer::shuffle_deck()
{
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(time(nullptr)));
}

void Dealer::hit(Person& p)
{
    p += deck[0];
    remove_card();
}

vector<Cards> Dealer::get_deck()
{
    return deck;
}

int Dealer::take_turn(Dealer& d, Person& p)
{    
    if(d.calculate_current_score() == 21)
    {
        d.display_current_stats();
        cout << "Blackjack!" << endl;
        return d.get_final_score();
    }
    else
    {
        while(true)
        {
            d.display_current_stats();
            
            if(calculate_current_score() >= 16)
            {
                break;
                
            }
            
            cout << "The dealer hits..." << endl << endl;
            
            d.hit(d);
            
            if(d.calculate_current_score() > 21)
            {
                d.display_current_stats();
                cout << "Bust!" << endl;
                break;
            }
          
        }
        
        return d.get_final_score();
    }
}

void deal_cards(Dealer& d, Player& p)
{
    p.clear_hand();
    d.clear_hand();
    
    for(int i = 0; i < 2; i ++)
    {
        p += d.get_deck()[0];
        d.remove_card();
        d += d.get_deck()[0];
        d.remove_card();
    }
}
