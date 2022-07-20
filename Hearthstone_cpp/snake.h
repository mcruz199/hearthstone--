#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include "card.h"

using namespace std;

class Snake : public Card {
    private:
    
    public:
    
    Snake(void);
    virtual string render(int);
};

#endif
