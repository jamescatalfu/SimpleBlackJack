#include "Cards.h"
#include <string>

using std::string;

Cards::Cards()
{
    suit = "";
    rank = "";
    value = 0;
    card_name = "";
}

void Cards::set_suit(string suit_p)
{
    suit = suit_p;
}

void Cards::set_rank(string rank_p)
{
    rank = rank_p;
}

void Cards::set_value(int value_p)
{
    value = value_p;
}

void Cards::set_card_name()
{
    card_name = rank + " of " + suit;
}

int Cards::get_value()
{
    return value;
}

string Cards::get_card_name()
{
    return card_name;
}
