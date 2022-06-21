
#include "Pitfall.h"
#include "../utilities.h"

////---Constructor---////
Pitfall::Pitfall() : Card("Pitfall")
{}

////---PrintFunction---////
std::ostream& Pitfall:: print_stats(ostream& out) const
{
    printCardDetails(out,"Pitfall");
    printEndOfCardDetails(out);
    return out;
}

////---Apply-Encounter---////
void Pitfall::applyEncounter(Player &player) const {
    if(player.check_type("Rogue"))
    {
        printPitfallMessage(false);
        return;
    }
    else {
        printPitfallMessage(true);
        player.damage(DAMGE);
    }
}
