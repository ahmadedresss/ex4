
using std::string;
using std::ostream;
class Card
{
public:
    /**
     * constructor
     * @param name
     */
    Card(const string name);

    Card()=default;

    /**
     * default destructor
     */
    ~Card()=default;

    /**
     * print function
     * @param out
     */
   // void Print(const ostream& out) const;

    /**
     * print operator.
     * @param out
     * @param card
     * @return
     */


    friend std::ostream& operator<<(ostream& out, Card& card) ;

    virtual std::ostream& print_stats(ostream& out) const ;

    virtual void applyEncounter(Player& player) const;


protected:
    string m_name;



};
