#ifndef NINJA_H
#define NINJA_H

#include <iostream>
#include "card.h"

using namespace std;

class Ninja : public Card {
    private:
    
    public:
    
    Ninja(void);
    virtual string render(int);
};

#endif
