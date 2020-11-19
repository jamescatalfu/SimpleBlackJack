#include "Person.h"
#include "Dealer.h"
#include "Player.h"
#include "Cards.h"
#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;

Person::Person()
{
    hand = {};
    current_score = 0;
    final_score = 0;
    num_wins = 0;
}

bool Person::operator > (const Person& p)
{
    return (final_score > p.final_score);
}

bool Person::operator == (const Person& p)
{
    return (final_score == p.final_score);
}

vector<Cards> Person::operator += (const Cards& c)
{
    hand.push_back(c);
    return hand;
}

int Person::take_turn(Dealer& d, Person&p)
{
    if(p.calculate_current_score() == 21)
    {
        p.display_current_stats();
        cout << "Blackjack!" << endl;
        return get_final_score();
    }
    else
    {
        char choice;
        
        while(true)
        {
            p.display_current_stats();
            
            
            cout << "Would you like to hit or stay? (h/s): ";
            cin >> choice;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << endl;
            
            if(choice == tolower('h'))
            {
                d.hit(p);
                
                if(p.calculate_current_score() > 21)
                {
                    p.display_current_stats();
                    cout << "Bust!" << endl;
                    return p.get_final_score();
                }
                else
                    continue;
            }
            else if(choice == tolower('s'))
            {
                return p.get_final_score();
            }
        }
    }
}

void Person::clear_hand()
{
    hand.clear();
}

void Person::display_current_stats()
{
    cout << "Here are your cards:\n";
    
    for(int i = 0; i < hand.size(); i++)
    {
        cout << hand[i].get_card_name() << endl;
    }
    
    cout << "\nYour current score is " << calculate_current_score() << endl << endl;
}

void Person::add_win()
{
    num_wins++;
}

int Person::calculate_current_score()
{
    current_score = 0;
    for(int i = 0; i < hand.size(); i++)
    {
        current_score += hand[i].get_value();
    }
    
    return current_score;
}

int Person::get_final_score()
{
    final_score = current_score;
    return final_score;
}

int Person::get_num_wins()
{
    return num_wins;
}

void check_for_win(Person& d, Person& p)
{
    
    if((d > p && d.get_final_score() <= 21) || p.get_final_score() > 21)
    {
        cout << "Dealer wins!" << endl;
        d.add_win();
    }
    else if(d == p)
        cout << "Draw!" << endl;
    else if((p > d && p.get_final_score() <= 21) || d.get_final_score() > 21)
    {
        cout << "You win!" << endl;
        p.add_win();
    }
}

int Person::get_games_played()
{
    return games_played;
}
