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
    uwordmap getWm()
    {
        return wm;
    };
    vectoredTxt getVt()
    {
        return vt;
    };
    std::vector<std::vector<int>> buildVectoredInt();
    void serialize(std::ostream &outStream);
    void deserialize(std::istream &inStream);
    void buildFromVectoredInt(std::vector<std::vector<int>> &vint);
    void saveToFile(std::string filename);
    void readFromFile(std::string filename);
    void exportToTxt(std::string filename);
    funzipper(std::istream &inStream)
    {
        deserialize(inStream);
    };
    funzipper(){};

private:
    uwordmap wm;
    vectoredTxt vt;
    const int WM_MIN_COUNTER = 1;
};
#endif