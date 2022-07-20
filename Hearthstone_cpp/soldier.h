#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "card.h"

using namespace std;

class Soldier : public Card {
    private:
    
    public:
    
    Soldier(void);
    virtual string render(int);
};


#endif

