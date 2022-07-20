#include "snake.h"

Snake::Snake(void) : Card::Card("Snake", 3, 400, 400) {}

string Snake::render(int line){
    
 switch(line){
        case 0: return ".___________.";
        case 1: return "|3) Snake   |";
        case 2: return "|     |     |";
        case 3: return "|     |     |";
        case 4: return "|     |     |";
        case 5: return "|     |     |";
        case 6: return "|  400/400  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
