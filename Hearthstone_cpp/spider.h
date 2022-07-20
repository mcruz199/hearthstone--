#ifndef SPIDER_H
#define SPIDER_H

#include <iostream>
#include "card.h"

using namespace std;

class Spider : public Card {
    private:
    
    public:
    
    Spider(void);
    virtual string render(int);
};


#endif
