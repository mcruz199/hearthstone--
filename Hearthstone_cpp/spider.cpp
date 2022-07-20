#include "spider.h"

Spider::Spider(void) : Card::Card("Spider", 1, 100, 300) {}

string Spider::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|   Spider  |";
        case 2: return "|     _     |";
        case 3: return "|  _\( )/_  |";
        case 4: return "|   /(O)\   |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|__100/300__|";
        default:
            return " ";
    }
}

 
