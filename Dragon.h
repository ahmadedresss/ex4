
const static int HPONLOSS=105;
const static int FORCE=25;
const static int LOOT=1000;
class Dragon : public Battle
{
private:


public:
    Dragon();
    ~Dragon()=default;
    Dragon(Dragon& dragon)=default;
    Dragon& operator=(Dragon& dragon) =default;

    std::ostream& print_stats(ostream& out) const override ;

    void applyEncounter(Player& player) const override;


};
