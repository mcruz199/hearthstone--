#include "ninja.h"


Ninja::Ninja(void) : Card::Card("Ninja", 3, 500, 200) {}

string Ninja::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|   Ninja   |";
        case 2: return "|   _____   |";
        case 3: return "|  |_____|  |";
        case 4: return "|  | o o |  |";
        case 5: return "|  -------  |";
        case 6: return "|  \_____/  |";
        case 7: return "|__500/200__|";
        default:
            return " ";
    }
}

  
