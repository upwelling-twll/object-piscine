#include <iostream>
#include "command.hpp"
#include "Article.hpp"
#include "Client.hpp"
#include "ThuesdayDiscountCommand.hpp"
#include "PackageReductionDiscountCommand.hpp"


int main()
{
    Date date = {9, 6, 2026};
    Client client(1, "Sauron");
    Article article(0, "One Ring", 1000000);
    Article article2(1, "Ring of Power", 100000);

    std::map<Article*, int> articles;


    articles.insert(std::make_pair(&article, 1));
    articles.insert(std::make_pair(&article2, 3));

    Command command(1, date, &client, articles);
    std::cout << "Total price: " << command.get_total_price() << std::endl;

    ThusedayDiscountCommand thuesday_command(2, date, &client, articles);
    try
    {
        std::cout << "Total price with thuesday discount: " << thuesday_command.get_total_price() << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    PackageReductionDiscountCommand package_command(3, date, &client, articles);
    try
    {
        std::cout << "Total price with package reduction discount: " << package_command.get_total_price() << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}