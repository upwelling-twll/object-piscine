#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <map>
#include "Article.hpp"

class Client;

struct Date
{
    int day;
    int month;
    int year;
};

class Command
{
    protected:
        int                     id;
        Date                    date;
        Client*                 client;
        std::map<Article*, int>  articles;

    public:

        virtual int get_total_price()
        {
            int total_price = 0;
            for (auto& article : this->articles)
            {
                total_price += (article.first)->getPrice() * article.second;
            }
            return total_price;
        }

        Command(int id, Date date, Client* client, std::map<Article*, int> articles = std::map<Article*, int>())
        {
            this->id = id;
            this->date = date;
            this->client = client;
            this->articles = articles;
        };

        ~Command() {};

};

#endif
