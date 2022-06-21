#include "Dragon.h"


////---Constructor---////
Dragon::Dragon() : Battle(FORCE,LOOT,HPONLOSS,"Dragon")
{}

////---Printing Function---////
std::ostream& Dragon::print_stats(ostream& out) const
{
    printCardDetails(out,"Dragon");
    printMonsterDetails(out,FORCE,HPONLOSS,LOOT, true);
}


void Dragon::applyEncounter(Player &player) const {
    if(player.getLevel()>=FORCE)
    {
        player.addCoins(LOOT);
        player.levelUp();
        printWinBattle(player.get_name(),"Dragon");
    }
    else
    {
        player.damage(HPONLOSS);
        printLossBattle(player.get_name(),"Dragon");
    }
}
