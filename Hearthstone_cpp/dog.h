#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "card.h"

using namespace std;

class Dog : public Card {
    private:
    
    public:
    
    Dog(void);
    virtual string render(int);
};

#endif
