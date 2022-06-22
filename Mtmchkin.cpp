//
// Created by momok on 6/19/2022.
//

#include "Mtmchkin.h"
#define SPACE " "

/*
 * :m_roundPlayed(1),m_winners(std::deque<unique_ptr<Player>>()),
m_losers(std::deque<unique_ptr<Player>>()),m_PlayersDeck(std::deque<unique_ptr<Player>>()),m_CardsDeck(std::deque<unique_ptr<Card>>())

 */
Mtmchkin::Mtmchkin(const std::string fileName)
{
    printStartGameMessage();

    ifstream myFile(fileName);
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


    printEnterTeamSizeMessage();
    int tmp=0;
    fillPlayerDeck(tmp);
    m_playersNumber=tmp;
}

///////////------Filling Queues------///////////

void Mtmchkin::fillCardsDeck(const std::string& fileName)
{
    ifstream myFile(fileName);
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



void Mtmchkin::getNumOfPlayers(string &numInput, int &numOfPlayers){
    if( numInput != "" && numInput.find_first_not_of("0123456789") == std::string::npos){
        numOfPlayers = std::stoi(numInput);
    }

    while(numOfPlayers < 2 || numOfPlayers > 6){
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        getline(std::cin, numInput);
        if(numInput != "" && numInput.find_first_not_of("0123456789") == std::string::npos){
            numOfPlayers = std::stoi(numInput);
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
    int tmp=numOfPlayers;
    printInsertPlayerMessage();

    while(getline(std::cin, input) && tmp>0)
    {
        std::cin>>input;
        int cut=input.find(SPACE);

        name=input.substr(0,cut);
        type=input.substr(cut+1);

        if(checkName(name) && checkPlayerType(type))
        {
            m_PlayersDeck.push_back(std::move(classifyPlayers(name,type)));
            tmp--;
        }
        else
        {
            if(!checkName(name))
            {
                printInvalidName();
            }
            else
            {
                printInvalidClass();
            }

        }
        printInsertPlayerMessage();

    }
}

/*
 * while(!checkName(name)|| !checkPlayerType(type))
            {
                std::cin>>input;
                int cut=input.find(SPACE);

                name=input.substr(0,cut);
                type=input.substr(cut+1);
            }
 */
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

    if(type=="Rouge")
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
        return false;


    for(int i=0;i<length;i++)
    {
        if(!isalpha(name[i]))
        {
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

    printRoundStartMessage(m_roundPlayed);
    int length=m_PlayersDeck.size();
    for (int i=0;i<length;i++)
    {
        if(checkPlayerStatus(*m_PlayersDeck.front()))
        {
            continue;
        }
        printTurnStartMessage(m_PlayersDeck.front()->get_name());
        Card current_card=*m_CardsDeck.front();
        current_card.applyEncounter(*m_PlayersDeck.front());

        m_CardsDeck.push_back(std::move(m_CardsDeck.front()));
        m_CardsDeck.pop_front();
        if(m_PlayersDeck.front()->isKnockedOut())
        {
            m_losers.push_back(std::move(m_PlayersDeck.front()));
        }
        if(m_PlayersDeck.front()->getLevel()==10)
        {
            m_winners.push_back(std::move(m_PlayersDeck.front()));
        }

    }
    if(isGameOver())
    {
        printGameEndMessage();
//        printLeaderBoard();
    }

    m_roundPlayed++;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_roundPlayed;
}

bool Mtmchkin::isGameOver() const
{
    if(m_winners.size()+m_losers.size()==m_PlayersDeck.size())
    {
        return true;

    }
    return false;


}

void Mtmchkin::printLeaderBoard() const
{
    int ranking=1;
    printLeaderBoardStartMessage();
    for(auto ptr=m_winners.begin();ptr!=m_winners.end();++ptr)
    {
        printPlayerLeaderBoard(ranking,*(*ptr));
        ranking++;
    }
    for(auto ptr=m_PlayersDeck.begin();ptr!=m_PlayersDeck.end();++ptr)
    {
        if(checkPlayerStatus(*(*ptr))){
            continue;
        }
        else
        {
            printPlayerLeaderBoard(ranking,*(*ptr));
            ranking++;
        }
    }

    for(auto ptr=m_losers.rbegin();ptr!=m_losers.rend();++ptr)
    {
        printPlayerLeaderBoard(ranking,*(*ptr));
        ranking++;
    }
}


