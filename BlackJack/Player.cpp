#include "Player.h"
#include "Dealer.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Player::Player()
{
    hand = {};
    current_score = 0;
    final_score = 0;    
}
