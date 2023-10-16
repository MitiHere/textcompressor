#ifndef VECTOREDTXT_HPP
#define VECTOREDTXT_HPP
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>

class vectoredTxt
{
public:
    std::vector<std::vector<std::string>> getFt();
    vectoredTxt(std::string filename)
    {
        std::ifstream myfile;
        myfile.open(filename);
        std::string myline;
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
                this->ft.push_back(linevec);
            }
            myfile.close(); // Close the file when done
        }
        else
        {
            std::cout << "Couldn't open file\n";
        }
    };
    void print();
    vectoredTxt(std::vector<std::vector<std::string>> vector) : ft(vector){};

    vectoredTxt();

protected:
    std::vector<std::vector<std::string>> ft;
};

#endif