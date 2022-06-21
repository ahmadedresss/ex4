class Treasure : public Card {
public:

    Treasure();
    ~Treasure() = default;
    Treasure(Treasure &treasure) = default;
    Treasure &operator=(Treasure const &treasure) = default;

    std::ostream& print_stats(std::ostream& os) const override;
    void applyEncounter(Player& player) const override;
    const static int LOOT=10;

};
