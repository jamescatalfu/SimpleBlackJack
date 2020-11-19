#ifndef Cards_hpp
#define Cards_hpp

#include <string>

using std::string;

class Cards
{
    private:
        string suit;
        string rank;
        int value;
        string card_name;
    
    public:
        Cards();
        void set_suit(string);
        void set_rank(string);
        void set_value(int);
        void set_card_name();
        int get_value();
        string get_card_name();
        
};

#endif
