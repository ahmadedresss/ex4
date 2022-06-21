
class Pitfall : public Card
        {
        public:
    Pitfall();
    ~Pitfall()= default;
    Pitfall(Pitfall& pitfall) = default;
    Pitfall &operator=(Pitfall const &treasure) = default;

    std::ostream& print_stats(std::ostream& os) const override;
    void applyEncounter(Player& player) const override;
    const static int DAMGE=10;
};
