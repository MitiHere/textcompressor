#include "filereader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    std::vector<std::vector<std::string>> fv = buildVectorFromFile("text.txt");
    wordMap map = buildTextMap(fv);
    // printVectorOfVector(fv);
    printTextMap(map);
    return 0;
}
std::vector<std::vector<std::string>> buildVectorFromFile(std::string filename)
{
    std::ifstream myfile;
    myfile.open(filename);
    std::string myline;
    std::vector<std::vector<std::string>> filevec;
    if (myfile.is_open())
    {
        while (std::getline(myfile, myline))
        {
            std::vector<std::string> linevec;
            std::istringstream iss(myline); // Create a string stream from the line
            std::string word;
            while (iss >> word)
            {
                linevec.push_back(word);
            }
            filevec.push_back(linevec);
        }
        myfile.close(); // Close the file when done
        // return filevec;
    }
    else
    {
        std::cout << "Couldn't open file\n";
    }
    return filevec;
}
void printVectorOfVector(const std::vector<std::vector<std::string>> &data)
{
    for (const auto &row : data)
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

void printTextMap(const wordMap &wm)
{
    std::cout << wm.counter << std::endl;
    for (const auto &pair : wm.map)
    {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
}

wordMap buildTextMap(const std::vector<std::vector<std::string>> &data)
{
    std::unordered_map<std::string, int> textMap;
    int counter = 0;
    for (const auto &row : data)
    {
        for (const std::string &item : row)
        {
            if (!(textMap.find(item) != textMap.end()))
            {
                textMap[item] = counter;
                counter++;
            }
        }
    }
    return wordMap(textMap, counter);
}