
#include "Fairy.h"


////---Constructor---////
Fairy :: Fairy() : Card("Fairy")
{
}

////---PrintingFunction---////
std::ostream& Fairy:: print_stats(ostream& out) const
{
    printCardDetails(out,"Fairy");
    printEndOfCardDetails(out);
    return out;
}

void Fairy::applyEncounter(Player &player) const {
    if(player.check_type("Fairy"))
    {
        printFairyMessage(true);
        player.heal(HEAL);
    }
    else
    {
        printFairyMessage(false);
    }

}
