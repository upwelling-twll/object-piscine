#ifndef CLIENT_HPP
#define CLIENT_HPP

class Client
{
    private:
        int id;
        std::string name;

    public:
        Client(int id, std::string name)
        {
            this->id = id;
            this->name = name;
        }

        ~Client() {};

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
