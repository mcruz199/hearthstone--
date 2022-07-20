#include "candle.h"

Candle::Candle(void) : Card::Card("Candle", 4, 300, 500) {}

string Candle::render(int line){
    
 switch(line){
        case 0: return ".___________.";
        case 1: return "|  Candle   |";
        case 2: return "|   ./\ .   |";
        case 3: return "|  . \/  .  |";
        case 4: return "|    ||     |";
        case 5: return "| ___||__(~\|";
        case 6: return "| \______/  |";
        case 7: return "|__300/500__|";
        default:
            return " ";
    }
}

            
