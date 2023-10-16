#include "funzipper.hpp"
#include <iostream>

void funzipper::print()
{
    wm.print();
    vt.print();
}
std::vector<std::vector<int>> funzipper::buildVectoredInt()
{
    std::vector<std::vector<int>> halfSer;
    for (const auto &row : this->vt.getFt())
    {
        std::vector<int> halfRow;
        for (const std::string &item : row)
        {
            halfRow.push_back(wm.at(item));
        }
        halfSer.push_back(halfRow);
    }
    return halfSer;
}
