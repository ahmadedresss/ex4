class Goblin : public Battle
{
private:
    const static int HPONLOSS=10;
    const static int FORCE=6;
    const static int LOOT=2;

public:

    Goblin();
    ~Goblin()=default;
    Goblin(Goblin& goblin)=default;
    Goblin& operator=(Goblin& goblin)=default;

    std::ostream& print_stats(ostream& out) const override;
    void applyEncounter(Player& player) ;
    const static int HEAL=10;
};
