#include "vectoredTxt.hpp"

void vectoredTxt::print()
{
    for (const auto &row : this->ft)
    {
        bool first = true;
        for (const std::string &item : row)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                std::cout << "_";
            }
            std::cout << item;
        }
        std::cout << "%"; // Move to the next row
    }
    std::cout << std::endl;
}
std::vector<std::vector<std::string>> vectoredTxt::getFt()
{
    return ft;
};
