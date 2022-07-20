#ifndef AXE_H
#define AXE_H

#include <iostream>
#include "card.h"

using namespace std;

class Axe : public Card {
    private:
    
    public:
    
    Axe(void);
    virtual string render(int);
};

#endif
