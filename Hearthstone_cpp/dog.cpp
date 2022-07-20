#include "dog.h"

Dog::Dog(void) : Card::Card("Dog", 4, 500, 400) {}

string Dog::render(int line){
    
 switch(line){
        case 0: return ".___________.";
        case 1: return "|    Dog    |";
        case 2: return "| ,-.___,-. |";
        case 3: return "| \_/_ _\_/ |";
        case 4: return "|   )O_O(   |";
        case 5: return "|  { (_) }  |";
        case 6: return "|   `-^-'   |";
        case 7: return "|__500/400__|";
        default:
            return " ";
    }
}


