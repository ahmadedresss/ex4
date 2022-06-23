//
// Created by momok on 6/21/2022.
//

#include "Merchant.h"

////---Constructor---////
Merchant::Merchant() : Card("Merchant")
{}

////---PrintFunction---////
void Merchant:: print_stats(ostream& out) const
{
    printCardDetails(out,"Merchant");
    printEndOfCardDetails(out);
}

void Merchant::applyEncounter(Player &player) const
{
    std::string choice;
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.get_name(),player.get_coins());
    std::cin>>choice;
    while (!check_if_true(choice))
    {
        printInvalidInput();
        std::cin>>choice;
    }
    try {
        if (std::stoi(choice) == 0) {
            printMerchantSummary(std::cout, player.get_name(), 0, 0);
        }
    }
    catch(...)
    {

        throw;
    }
    try {
        if (std::stoi(choice) == HP) {
            if (!player.pay(5)) {
                printMerchantInsufficientCoins(std::cout);
                return;
            } else {
                player.heal(1);
                printMerchantSummary(std::cout, player.get_name(), HP, 5);
            }
        }
    }
    catch(...)
    {

        throw;
    }
    try {
        if (std::stoi(choice) == FORCE) {
            if (!player.pay(10)) {
                printMerchantInsufficientCoins(std::cout);
                return;
            } else {
                player.buff(1);
                printMerchantSummary(std::cout, player.get_name(), FORCE, 10);
            }
        }
    }
    catch(...)
    {

        throw;
    }
}

bool Merchant::check_if_true(std::string choice) const {
    try {
        if (std::stoi(choice) == HP || std::stoi(choice) == 0 || std::stoi(choice) == FORCE) {
            return true;
        }
    }
    catch(...)
    {
        throw;
    }
    return false;
}
