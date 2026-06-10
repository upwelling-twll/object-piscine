#ifndef THUSDAYDISCOUNTCOMMAND_HPP
#define THUSDAYDISCOUNTCOMMAND_HPP

#include <ctime>

class ThusedayDiscountCommand : public Command
{
    public:
        ThusedayDiscountCommand(int id, Date date, Client* client, std::map<Article*, int> articles = std::map<Article*, int>())
        : Command(id, date, client, articles) {};

        ~ThusedayDiscountCommand() {};

        int get_total_price()
        {
            int total_price = Command::get_total_price();
            Date date = this->date;
            std::tm time_in = {0, 0, 0, date.day, date.month, date.year - 1900};
            std::time_t time_temp = std::mktime(&time_in);
            const std::tm * time_out = std::localtime(&time_temp);
            if (time_out->tm_wday == 4) // Thursday is represented by 4 in tm structure
                return total_price * 0.9; // 10% discount
            else
                throw std::runtime_error("The command must be made on a Thursday to apply the discount");
            return total_price;
        }
};

#endif