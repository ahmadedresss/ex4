
class Barfight : public Card
{
public:

    Barfight();
    ~Barfight() = default;
    Barfight(Barfight &barfight) = default;
    Barfight &operator=(Barfight const &barfight) = default;

    std::ostream& print_stats(std::ostream& os) const override;
    void applyEncounter(Player& player) const override;
    static const int DAMGE=10;


};
