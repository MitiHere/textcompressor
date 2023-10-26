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

void funzipper::buildFromVectoredInt(std::vector<std::vector<int>> &vint)
{
    std::vector<std::vector<std::string>> vector;
    std::unordered_map<int, std::string> flipedwm = wm.flip();
    for (const auto &row : vint)
    {
        std::vector<std::string> halfRow;
        for (const int &item : row)
        {
            halfRow.push_back(flipedwm.at(item));
        }
        vector.push_back(halfRow);
    }
    vt = vectoredTxt(vector);
}

void funzipper::serialize(std::ostream &outStream)
{
    wm.serialize(outStream);
    int size = wm.getCounterSize();
    std::vector<std::vector<int>> intvct = buildVectoredInt();
    std::vector<std::vector<int>>::size_type lineNbr = intvct.size();
    outStream.write(reinterpret_cast<const char *>(&lineNbr), sizeof(std::vector<std::vector<int>>::size_type));

    for (const std::vector<int> &row : intvct)
    {
        std::vector<int>::size_type wordNbr = row.size();
        outStream.write(reinterpret_cast<const char *>(&wordNbr), sizeof(std::vector<int>::size_type));
        for (const int &item : row)
        {
            outStream.write(reinterpret_cast<const char *>(&item), sizeof(char) * size);
        }
    }
}

void funzipper::deserialize(std::istream &inStream)
{
    wm = uwordmap(inStream); // Deserialize the word map
    int size = wm.getCounterSize();
    std::vector<std::vector<int>> intvct;
    // Deserialize the number of lines
    std::vector<std::vector<int>>::size_type lineNbr;
    inStream.read(reinterpret_cast<char *>(&lineNbr), sizeof(std::vector<std::vector<int>>::size_type));

    // Deserialize each line
    for (std::vector<std::vector<int>>::size_type i = 0; i < lineNbr; ++i)
    {
        std::vector<int> row;
        std::vector<int>::size_type wordNbr;
        inStream.read(reinterpret_cast<char *>(&wordNbr), sizeof(std::vector<int>::size_type));
        for (std::vector<int>::size_type j = 0; j < wordNbr; ++j)
        {
            int item = 0;
            inStream.read(reinterpret_cast<char *>(&item), sizeof(char) * size);
            row.push_back(item);
        }
        intvct.push_back(row);
    }
    buildFromVectoredInt(intvct);
}

void funzipper::saveToFile(std::string filename)
{
    std::ofstream outputFile(filename, std::ios::binary);

    if (outputFile.is_open())
    {
        serialize(outputFile);
        // Close the file
        outputFile.close();
    }
    else
    {
        std::cerr << "Error: Could not open the file for writing." << std::endl;
    }
}

void funzipper::readFromFile(std::string filename)
{
    std::ifstream inputFile(filename, std::ios::binary);
    if (inputFile.is_open())
    {
        deserialize(inputFile);
        inputFile.close();
    }
    else
    {
        std::cerr << "Error: Could not open the file for reading." << std::endl;
    }
}
void funzipper::exportToTxt(std::string filename)
{
    std::ofstream output_file(filename);

    if (output_file.is_open())
    {
        // Iterate through the vector of vectors and write each line to the file
        for (const std::vector<std::string> &line : vt.getFt())
        {
            for (const std::string &word : line)
            {
                output_file << word << " "; // Write each word separated by a space
            }
            output_file << "\n"; // Write a newline to separate lines
        }
        // Close the file stream
        output_file.close();
    }
}
