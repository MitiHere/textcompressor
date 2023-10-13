#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include <string>
#include <vector>
#include <unordered_map>

class wordMap
{
public:
    std::unordered_map<std::string, int> map;
    int counter;

    wordMap(const std::unordered_map<std::string, int> imap, int integer)
        : map(imap), counter(integer) {}
};

int main();
std::vector<std::vector<std::string>> buildVectorFromFile(std::string filename);
void printVectorOfVector(const std::vector<std::vector<std::string>> &data);
wordMap buildTextMap(const std::vector<std::vector<std::string>> &data);
void printTextMap(const wordMap &wm);
#endif
