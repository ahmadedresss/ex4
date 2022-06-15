//
// Created by momok on 6/14/2022.
//

#include "Battle.h"
/*
Battle::Battle() :card() ,force(0),loot(0),hp_on_loss(0),type(" ")
{

}
*/
Battle::Battle(int force,int loot ,int hp_on_loss, string& type):card("Battle"),force(force),loot(loot),
hp_on_loss(hp_on_loss),type(type)
{

}

