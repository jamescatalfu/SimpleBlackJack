/*
 * Author: James Catalfu
 * Purpose: This is a simplified blackjack game
 */

#include "Cards.h"
#include "Person.h"
#include "Dealer.h"
#include "Player.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

Dealer d;
Player p;

int take_turn(Person& p)
{
    return p.take_turn(d, p);
}

void display_scoreboard(Dealer& d, Player& p)
{
    for(int i = 0; i < 7; i++)
    {
        cout << endl;
        if(i == 1)
        {
            cout << "|" << setw(13) << "Dealer" << setw(8) << "|" << setw(12) << "Player" << setw(8) << "|";
        }
        if(i == 3)
        {
            cout << "|" << setw(11) << d.calculate_current_score() << setw(10) << "|" << setw(10) << p.calculate_current_score() << setw(10) << "|";
        }
        if(i == 5)
        {
            cout << "|" << setw(19) << d.get_num_wins() << " - " << p.get_num_wins() << setw(18) << "|";
        }
        for(int j = 0; j < 40; j++)
        {
            if(i == 0 || i == 6)
            {
                if(j == 0)
                    cout << " ";
                
                cout << "-";
            }
            
            if (i == 2)
            {
                if(j == 0 || j == 20 || j == 39)
                    cout << "|";
                if(j < 39)
                    cout << "-";
            }
            if(i == 4)
            {
                if(j == 0)
                    cout << "|";
                if(j== 39)
                    cout << "-|";
                if(j < 39)
                    cout << "-";
            }
        }
    }
    cout << endl << endl;
}

int main()
{
    char play_again;
    
    ifstream input;
    input.open("BlackJack.txt");
    if(input)
    {
        string line;
        while(getline(input, line))
        {
            cout << line << endl;
        }
        input.close();
    }
    cout << endl << endl;
    
    while(true)
    {
        d.create_deck();
        d.shuffle_deck();
        deal_cards(d, p);
        
        cout << setw(23) << "Game # " << Person::get_games_played();
        display_scoreboard(d, p);
        
        cout <<"Player's Turn!"<< endl << endl;
    
        take_turn(p);
        display_scoreboard(d, p);
        if(p.calculate_current_score() > 21)
        {
            check_for_win(d, p);
        }
        else
        {
            cout <<"Dealer's Turn!"<< endl << endl;
    
            take_turn(d);
            check_for_win(d,p);
            display_scoreboard(d, p);
        }
        cout << "Would you like to play again? (y/n): ";
        cin >> play_again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if(tolower(play_again == 'y'))
        {
            cout << endl;
            continue;
        }
        else
        {
            break;
        }
    }
    
    return 0;
}
