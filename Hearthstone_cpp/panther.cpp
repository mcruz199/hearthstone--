#include "panther.h"


Panther::Panther(void) : Card::Card("Panther", 4, 600, 200) {}

string Panther::render(int line){
    
 switch(line){
        case 0: return ".___________.";
        case 1: return "|  Panther  |";
        case 2: return "|  |\---/|  |";
        case 3: return "|  | o_o |  |";
        case 4: return "|   \_^_/   |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|__600/200__|";
        default:
            return " ";
    }
}


