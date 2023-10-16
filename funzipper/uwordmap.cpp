#include "uwordmap.hpp"
#include <iostream>

void uwordmap::print()
{
    std::cout << this->counter << std::endl;
    for (const auto &pair : this->map)
    {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
}
