class Fairy : public Card {
public:

    Fairy();
    ~Fairy() = default;
    Fairy(Fairy &fairy) = default;
    Fairy &operator=(Fairy const &fairy) = default;

    std::ostream& print_stats(std::ostream &os) const override;
    void applyEncounter(Player& player) const override;
    const static int HEAL=10;
};
