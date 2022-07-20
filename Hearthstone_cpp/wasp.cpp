#include "wasp.h"

Wasp::Wasp(void) : Card::Card("Wasp", 5, 500, 500) {}

string Wasp::render(int line){
    
 switch(line){
        case 0: return ".___________.";
        case 1: return "|5) Wasp    |";
        case 2: return "|      U    |";
        case 3: return "|     \o/   |";
        case 4: return "|     /o\   |";
        case 5: return "|      V    |";
        case 6: return "|  500/500  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
