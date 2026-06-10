#ifndef PACKAGEREDUCTIONDISCOUNTCOMMAND_HPP
#define PACKAGEREDUCTIONDISCOUNTCOMMAND_HPP

class PackageReductionDiscountCommand : public Command
{
    public:
        PackageReductionDiscountCommand(int id, Date date, Client* client, std::map<Article*, int> articles = std::map<Article*, int>())
        : Command(id, date, client, articles) {};

        ~PackageReductionDiscountCommand() {};

        int get_total_price()
        {
            int total_price = Command::get_total_price();
            if (total_price > 150)
                return (total_price - 10);
            else
                throw std::runtime_error("Total price must be greater than 150 to apply the discount");
            return total_price;
        }

};

#endif