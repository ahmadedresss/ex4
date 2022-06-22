#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <string>
#include "utilities.h"
#include "Queue.h"
#include <deque>
#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
#include <functional>
#include <memory>

#include "Cards/Card.h"
#include "Cards/Battle.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"

#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"


using std::unique_ptr;
using std::ifstream;
using std::ofstream;

class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    std::deque<unique_ptr<Player>> m_PlayersDeck ;
    std::deque<unique_ptr<Card>> m_CardsDeck ;
    std::deque<unique_ptr<Player>> m_winners ;
    std::deque<unique_ptr<Player>> m_losers ;
    int m_playersNumber;
    int m_roundPlayed;

    void getNumOfPlayers(string &numInput, int &numOfPlayers);

    bool checkPlayerStatus(Player& player) const;
    bool checkPlayerSize(string& num) const;
    bool checkName(const std::string &name)const ;
    bool checkPlayerType(std::string &type) const;
    bool checkCardType(std::string &type) const;

    void fillCardsDeck(const std::string& fileName);
    void fillPlayerDeck(int &numOfPlayers);

    std::unique_ptr<Player> classifyPlayers(const string& name , const string& type);
    std::unique_ptr<Card> classifyCards(const string& name);


};



#endif /* MTMCHKIN_H_ */
