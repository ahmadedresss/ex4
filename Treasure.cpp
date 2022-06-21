#include "Treasure.h"

////---Constructor---////
Treasure::Treasure() : Card("Treasure")
{}



////---PrintFunction---////
std::ostream& Treasure:: print_stats(ostream& out) const
{
    printCardDetails(out,"Treasure");
    printEndOfCardDetails(out);
    return out;
}

void Treasure::applyEncounter(Player &player) const
{

    printTreasureMessage();
    player.addCoins(LOOT);
}
