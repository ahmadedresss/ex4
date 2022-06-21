
const static string NAME="Vampire";

class Vampire : public Battle
{
private:

    const static int HPONLOSS=10;
    const static int FORCE=10;
    const static int LOOT=2;

//////dont forget///////////////+1 force

public:
    Vampire();
    ~Vampire()=default;
    Vampire(Vampire& vampire)=default;
    Vampire& operator=(Vampire& vampire) =default;

    std::ostream& print_stats(ostream& out) const override;
    void applyEncounter(Player& player) const override;

};
