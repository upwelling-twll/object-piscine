#ifndef COMMAND_HPP
#define COMMAND_HPP

#incldue <map>

struct Date
{
    int day;
    int month;
    int year;
};

class Command
{
    private:
        int                     id;
        Date                    date;
        Client                  client;
        std::map<Article, int>  articles;

    public:

        int get_total_price() const;

};

#endif
