#include "Card.h"
#include "ostream"
using std::ostream;

////---Constructor---////
Card::Card(const string name) :m_name(name)
{}

////---Printing-Operator---////
std::ostream& operator<<(ostream& out,Card& card)
{
    card.print_stats(out);
    return (out);
}
std::ostream& print_stats(ostream& out)  {

}

std::ostream &Card::print_stats(ostream &out) const {
}

void Card::applyEncounter(Player &player) const {

}
