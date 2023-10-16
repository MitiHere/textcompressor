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
        wm = uwordmap(vt, WM_MIN_COUNTER);
    };

private:
    uwordmap wm;
    vectoredTxt vt;

    const int WM_START = 1;
    const int WM_END = 2;
    const int TXT_START = 3;
    const int TXT_END = 4;
    const int WM_MIN_COUNTER = 5;
};
#endif