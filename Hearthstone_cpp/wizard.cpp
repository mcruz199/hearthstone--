#include "wizard.h"


Wizard::Wizard(void) : Card::Card("Wizard", 4, 500, 400) {}

string Wizard::render(int line){
    
 switch(line){
        case 0: return ".___________.";
        case 1: return "|   Wizard  |";
        case 2: return "|     /\    |";
        case 3: return "|    / +\   |";
        case 4: return "|   /+   \  |";
        case 5: return "|  (____+_) |";
        case 6: return "|           |";
        case 7: return "|__500/400__|";
        default:
            return " ";
    }
}
