#ifndef WASP_H
#define WASP_H

#include <iostream>
#include "card.h"

using namespace std;

class Wasp : public Card {
    private:
    
    public:
    
    Wasp(void);
    virtual string render(int);
};

#endif
