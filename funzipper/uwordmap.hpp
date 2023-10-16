#ifndef UWORDMAP_HPP
#define UWORDMAP_HPP
#include <string>
#include <unordered_map>
#include "vectoredTxt.hpp"
class uwordmap
{
public:
    void print();
    uwordmap(vectoredTxt &ft)
    {
        std::vector<std::vector<std::string>> rft = ft.getFt();
        std::unordered_map<std::string, int> textMap;
        for (const auto &row : rft)
        {
            for (const std::string &item : row)
            {
                if (!(this->map.find(item) != this->map.end()))
                {
                    this->map[item] = this->counter;
                    this->counter++;
                }
            }
        }
    };

    uwordmap()
    {
        map = std::unordered_map<std::string, int>();
    }

private:
    std::unordered_map<std::string, int> map;
    int counter = 0;
};
#endif