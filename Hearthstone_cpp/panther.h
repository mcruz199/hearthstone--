#ifndef PANTHER_H
#define PANTHER_H

#include <iostream>
#include "card.h"

using namespace std;

class Panther : public Card {
    private:
    
    public:
    
    Panther(void);
    virtual string render(int);
};

#endif
