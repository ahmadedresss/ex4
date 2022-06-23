//
// Created by momok on 6/19/2022.
//

#include "Mtmchkin.h"
#define SPACE " "

/*
 * :m_roundPlayed(1),m_winners(std::deque<unique_ptr<Player>>()),
m_losers(std::deque<unique_ptr<Player>>()),m_PlayersDeck(std::deque<unique_ptr<Player>>()),m_CardsDeck(std::deque<unique_ptr<Card>>())

 */

Mtmchkin::Mtmchkin(const std::string fileName):m_roundPlayed(0)
{
    printStartGameMessage();

    ifstream myFile(fileName,std::fstream::in);
    int cardsCounter=0;
    string type;
    if(!myFile)
    {
        throw DeckFileNotFound();
    }

    while(std::getline(myFile,type))
    {
        if(checkCardType(type))
        {
            m_CardsDeck.push_back(std::move(classifyCards(type)));
        }
        else
        {
            string tmp=std::to_string(cardsCounter);
            throw DeckFileFormatError(tmp);
        }
        cardsCounter++;
    }
    if( cardsCounter < 5 )
    {
        throw DeckFileInvalidSize();
    }


    printEnterTeamSizeMessage();

    int tmp=0;

    fillPlayerDeck(tmp);
    myFile.close();

}

///////////------Filling Queues------///////////
/*
void Mtmchkin::fillCardsDeck(const std::string& fileName)
{
    ifstream myFile(fileName,std::fstream::in);
    int cardsCounter=0;
    string type;
    if(!myFile)
    {
        throw DeckFileNotFound();
    }

    while(std::getline(myFile,type))
    {
        if(checkCardType(type))
        {
            m_CardsDeck.push_back(std::move(classifyCards(type)));
        }
        else
        {
            string tmp=std::to_string(cardsCounter);
            throw DeckFileFormatError(tmp);
        }
        cardsCounter++;
    }
    if( cardsCounter < 5 )
    {
        throw DeckFileInvalidSize();
    }
    myFile.close();
}

*/

void Mtmchkin::getNumOfPlayers(string &numInput, int &numOfPlayers){
    try {
        if (numInput != "" && numInput.find_first_not_of("0123456789") == std::string::npos) {
            numOfPlayers = std::stoi(numInput);
        }
    }
    catch(...)
    {

    }

    while(numOfPlayers < 2 || numOfPlayers > 6){
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        getline(std::cin, numInput);
        try {
            if (numInput != "" && numInput.find_first_not_of("0123456789") == std::string::npos) {
                numOfPlayers = std::stoi(numInput);
            }
        }
        catch(...)
        {

        }
    }
}

void Mtmchkin::fillPlayerDeck(int &numOfPlayers)
{
    string input;
    string name;
    string type;
    getline(std::cin,input);
    getNumOfPlayers(input,numOfPlayers);



    bool flag=true;
    for (int i = 0; i < numOfPlayers; ++i) {

        printInsertPlayerMessage();
        do{
            getline(std::cin, input);

            int cut=input.find(SPACE);
        if(cut<0)
          throw;
            name=input.substr(0,cut);
            type=input.substr(cut+1);

            flag=checkName(name) && checkPlayerType(type);
        }while(!flag);

        m_PlayersDeck.push_back(std::move(classifyPlayers(name,type)));
    }

}

//////////-----Classifing-----////////////

std::unique_ptr<Card> Mtmchkin::classifyCards(const string& name)
{
    if(name=="Barfight")
        return std::unique_ptr<Card>(new Barfight());

    if (name =="Vampire")
        return std::unique_ptr<Card>(new Vampire());

    if (name =="Pitfall")
        return std::unique_ptr<Card>(new Pitfall());

    if (name =="Merchant")
        return std::unique_ptr<Card>(new Merchant());

    if (name =="Goblin")
        return std::unique_ptr<Card>(new Goblin());

    if (name =="Treasure")
        return std::unique_ptr<Card>(new Treasure());

    if(name=="Dragon")
        return std::unique_ptr<Card>(new Dragon());

    if(name=="Fairy")
        return std::unique_ptr<Card>(new Fairy());

    return nullptr;
}

std::unique_ptr<Player> Mtmchkin::classifyPlayers(const string& name , const string& type)
{
    if(type=="Fighter")
        return std::unique_ptr<Player>(new Fighter(name,type));

    if(type=="Rogue")
        return std::unique_ptr<Player>(new Rogue(name,type));

    if(type=="Wizard")
        return std::unique_ptr<Player>(new Wizard(name,type));

    return nullptr;
}



///////////////////////////////////////////////////////////////////////////////////




//////////----- CheckingFunction-----//////////
bool Mtmchkin::checkCardType(std::string &type) const
{
    if(type=="Barfight" ||type=="Dragon" ||type=="Fairy" || type=="Goblin"||
       type=="Merchant" || type=="Pitfall" || type=="Treasure" || type=="Vampire")
    {
        return true;
    }
    return false;
}
bool Mtmchkin::checkName(const std::string &name) const
{

    int length=name.size();
    if(length>15||name.empty())
    {
        printInvalidName();
        return false;
    }

    for(int i=0;i<length;i++)
    {
        if(!isalpha(name[i]))
        {
            printInvalidName();
            return false;
        }
    }
    return true;
}

bool Mtmchkin::checkPlayerType(std::string &type) const
{
    if(type=="Wizard" ||type=="Rogue" ||type=="Fighter")
    {
        return true;
    }
    printInvalidClass();
    return false;
}
bool Mtmchkin::checkPlayerStatus(Player& player) const
{
    if(player.isKnockedOut() || player.getLevel()==10)
    {
        return true;
    }
    return false;

}

bool Mtmchkin::checkPlayerSize(string& num) const
{
    if(num.find_first_not_of("0123456789")==string::npos)
        return false;
    int numOfPlayers= std::stoi(num);
    if(numOfPlayers<2 || numOfPlayers>6)
        return false;
    return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mtmchkin::playRound()
{

    std::unique_ptr<Player> current_player;
    std::unique_ptr<Card> current_card;

    printRoundStartMessage(m_roundPlayed+1);
    int length=m_PlayersDeck.size();

    for (int i=0;i<length;i++)
    {
        current_player=std::move(m_PlayersDeck.front());
        m_PlayersDeck.pop_front();
        current_card=std::move(m_CardsDeck.front());
        m_CardsDeck.pop_front();



        printTurnStartMessage(current_player->get_name());

        current_card->applyEncounter(*current_player);

        m_CardsDeck.push_back(std::move(current_card));

        if(current_player->isKnockedOut())
        {
            m_losers.push_back(std::move(current_player));

        }
        else if(current_player->getLevel()==10)
        {
            m_winners.push_back(std::move(current_player));
        }
        else
        {
            m_PlayersDeck.push_back(std::move(current_player));
        }
    }
    if(isGameOver())
    {
        printGameEndMessage();
    }
    m_roundPlayed++;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_roundPlayed;
}

bool Mtmchkin::isGameOver() const
{
    if(m_PlayersDeck.size()==0)
    {
        return true;

    }
    return false;


}

void Mtmchkin::printLeaderBoard() const
{
    int ranking=1;
    printLeaderBoardStartMessage();

    if(!m_winners.empty())
    {
        for(unsigned int i=0;i<m_winners.size();++i)
        {
            printPlayerLeaderBoard(ranking,*m_winners[i]);
            ranking++;
        }
    }
    if(!m_PlayersDeck.empty())
    {
        for(unsigned int i=0;i<m_PlayersDeck.size();++i)
        {
            if(checkPlayerStatus(*m_PlayersDeck[i])){
                continue;
            }
            else
            {
                printPlayerLeaderBoard(ranking,*m_PlayersDeck[i]);
                ranking++;
            }
        }
    }

    if(!m_losers.empty())
    {
        for(unsigned int i=m_losers.size();i>0;--i)
        {
            printPlayerLeaderBoard(ranking,*m_losers[i-1]);
            ranking++;
        }
    }

}
