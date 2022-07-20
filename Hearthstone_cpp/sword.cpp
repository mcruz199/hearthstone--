#include "sword.h"

Sword::Sword(void) : Card::Card("Sword", 2, 300, 200) {}

string Sword::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|2) SWORD   |";
        case 2: return "|     ^^    |";
        case 3: return "|     ||    |";
        case 4: return "|    _||_   |";
        case 5: return "|     ||    |";
        case 6: return "|     \/    |";
        case 7: return "|__300/200__|";
        default:
            return " ";
    }
}
