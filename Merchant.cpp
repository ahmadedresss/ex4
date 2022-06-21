
#include "ostream"
#include "Merchant.h"
using std::cout;
using std::cin;
#include "string"
#include "iostream"


////---Constructor---////
Merchant::Merchant() : Card("Merchant")
{}

////---PrintFunction---////
std::ostream& Merchant:: print_stats(ostream& out) const
{
    printCardDetails(out,"Merchant");
    printEndOfCardDetails(out);
    return out;
}

void Merchant::applyEncounter(Player &player) const
{
    std::string choice;
    printMerchantInitialMessageForInteractiveEncounter(cout,player.get_name(),player.get_coins());
    std::cin>>choice;
    while (!check_if_true(choice))
    {
        printInvalidInput();
        std::cin>>choice;
    }
    if(std::stoi(choice)==0)
    {
        printMerchantSummary(std::cout,player.get_name(),0,0);
    }
    if (std::stoi(choice)==HP)
    {
        if(!player.pay(5))
        {
            printMerchantInsufficientCoins(std::cout);
            return;
        }
        else
        {
            player.heal(1);
            printMerchantSummary(std::cout,player.get_name(),HP,5);
        }
    }
    if(std::stoi(choice)==FORCE)
    {
        if(!player.pay(10))
        {
            printMerchantInsufficientCoins(std::cout);
            return;
        }
        else
        {
            player.buff(1);
            printMerchantSummary(std::cout,player.get_name(),FORCE,10);
        }
    }
}

bool Merchant::check_if_true(std::string choice) const {
    if(std::stoi(choice)==HP || std::stoi(choice)==0 || std::stoi(choice)==FORCE)
    {
        return true;
    }
    return false;
}
