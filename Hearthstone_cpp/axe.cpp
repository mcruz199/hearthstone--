#include "axe.h"

Axe::Axe(void) : Card::Card("Iron Golem", 3, 400, 400) {}

string Axe::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|    Axe    |";
        case 2: return "|       ) \ |";
        case 3: return "|  <=()=>  )|";
        case 4: return "|    || )_/ |";
        case 5: return "|    ||     |";
        case 6: return "|    ||     |";
        case 7: return "|__400/400__|";
        default:
            return " ";
    }
}


     
