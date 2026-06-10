#ifndef ARTICLE_HPP
#define ARTICLE_HPP

#include <iostream>

class Article
{
    private:
        int id;
        std::string name;
        int price;
    
    public:
        Article(int id, std::string name, int price) 
        {
            this->id = id;
            this->name = name;
            this->price = price;
        }

        int getPrice() const
        {
            return this->price;
        }

        int getId() const
        {
            return this->id;
        }
        std::string getName() const
        {
            return this->name;
        }
};

#endif