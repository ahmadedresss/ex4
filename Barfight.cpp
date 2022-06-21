//
// Created by Ahmad Idris on 6/15/22.
//

#include "Barfight.h"


////---Constructor---////
Barfight::Barfight() : Card("Barfight")
{}



////---PrintFunction---////
std::ostream& Barfight:: print_stats(ostream& out) const
{
    printCardDetails(out,"Barfight");
    printEndOfCardDetails(out);
    return out;
}

void Barfight::applyEncounter(Player &player) const
{

    if(player.check_type("Fighter"))
    {
        printBarfightMessage(true);
        return;
    }
    else
    {
        printBarfightMessage(false);
        player.damage(DAMGE);
    }
}
