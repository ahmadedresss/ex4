
#include "Card.h"
#include "../utilities.h"

#include <iostream>

using std::string;
using std::ostream;

class Battle : public Card
{
protected:
    int force;
    int loot;
    int hp_on_loss;

public:
    Battle()=default;
    Battle(int force,int loot ,int hp_on_loss , const string& type);
    virtual ~Battle();
    Battle(const Battle& copy)=default;
    Battle& operator=(const Battle& copy)=default;



};
