//
// Created by momok on 6/14/2022.
//

#ifndef HW4_BATTLE_H
#define HW4_BATTLE_H

#include "Card.h"
#include <iostream>
#include "utilities.h"
using std::string;
using std::ostream;

class Battle : public Card
{
protected:
    Card card;
    int force;
    int loot;
    int hp_on_loss;
    string type;

public:
    Battle()=default;
    Battle(int force,int loot ,int hp_on_loss , string& type);

    virtual ~Battle();
    Battle(const Battle& copy)=default;
    Battle& operator=(const Battle& copy)=default;


};



#endif //HW4_BATTLE_H
