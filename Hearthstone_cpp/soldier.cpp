#include "soldier.h"

Soldier::Soldier(void) : Card::Card("Soldier", 1, 300, 100) {}

string Soldier::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|1) Soldier    |";
        case 2: return "|    ^      |";
        case 3: return "|   ( ) /   |";
        case 4: return "|  (  |     |";
        case 5: return "|   \_|) \  |";
        case 6: return "|  300/100  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
