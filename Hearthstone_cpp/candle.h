#ifndef CANDLE_H
#define CANDLE_H

#include <iostream>
#include "card.h"

using namespace std;

class Candle : public Card {
    private:
    
    public:
    
    Candle(void);
    virtual string render(int);
};

#endif
