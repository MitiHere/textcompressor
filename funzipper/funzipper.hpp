#ifndef FUNZIPPER_HPP
#define FUNZIPPER_HPP
#include "vectoredTxt.hpp"
#include "uwordmap.hpp"

class funzipper
{
public:
    void print();

    funzipper(std::string filename) : vt(filename)
    {
        wm = uwordmap(vt);
    };

private:
    uwordmap wm;
    vectoredTxt vt;
};
#endif