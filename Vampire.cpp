
#include "Vampire.h"

using std::string;
using std::ostream;

////---Constructor---////
Vampire::Vampire() : Battle(FORCE,LOOT,HPONLOSS,NAME)
{
}

////---Print Function---////
std::ostream& Vampire::print_stats(ostream& out) const
{
    printCardDetails(out,NAME);
    printMonsterDetails(out,FORCE,HPONLOSS,LOOT,false);
}



void Vampire::applyEncounter(Player &player) const {
    if(player.getLevel()>=FORCE)
    {
        player.addCoins(LOOT);
        player.levelUp();
        player.buff(1);
        printWinBattle(player.get_name(),"Vampire");
    }
    else
    {
        player.damage(HPONLOSS);
        printLossBattle(player.get_name(),"Vampire");
    }

}
