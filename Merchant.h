
class Merchant : public Card {
public:

    const int static HP=1;
    const int static FORCE=2;

    Merchant();
    ~Merchant() = default;
    Merchant(Merchant &merchant) = default;
    Merchant &operator=(Merchant const &merchant) = default;

    std::ostream& print_stats(std::ostream& out) const override;
    void applyEncounter(Player& player) const override;
    bool check_if_true(std::string choice) const;

};
