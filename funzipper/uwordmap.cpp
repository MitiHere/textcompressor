#include "uwordmap.hpp"
#include <iostream>

int calculateValueSize(int &maxValue)
{
    if (maxValue <= 0xFF)
    {
        return 1; // 1 byte for values up to 255
    }
    else if (maxValue <= 0xFFFF)
    {
        return 2; // 2 bytes for values up to 65535
    }
    else if (maxValue <= 0xFFFFFF)
    {
        return 3; // 3 bytes for values up to 16777215
    }
    else
    {
        return 4; // 4 bytes for values up to 4294967295
    }
}

void uwordmap::print()
{
    std::cout << "counter: " << this->counter << std::endl;
    for (const auto &pair : this->map)
    {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
}

void uwordmap::serialize(std::ostream &outStream)
{
    int size = calculateValueSize(counter);
    outStream.write(reinterpret_cast<const char *>(&size), sizeof(int)); // write the byte num needed to store the int
    outStream.write(reinterpret_cast<const char *>(&counter), size);     // write the byte num needed to store the int

    // Serialize the map size
    std::unordered_map<std::string, int>::size_type mapSize = map.size();
    outStream.write(reinterpret_cast<const char *>(&mapSize), sizeof(std::unordered_map<std::string, int>::size_type));

    // Serialize each key-value pair in the map
    for (const auto &entry : map)
    {
        size_t strLength = entry.first.size();                                               // get the length of the string
        outStream.write(reinterpret_cast<const char *>(&strLength), sizeof(size_t));         // write the length of the string
        outStream.write(entry.first.c_str(), strLength);                                     // write the c_string
        outStream.write(reinterpret_cast<const char *>(&entry.second), sizeof(char) * size); // write the fzInt
    }
}

void uwordmap::deserialize(std::istream &inStream)
{
    int size;
    inStream.read(reinterpret_cast<char *>(&size), sizeof(int));
    inStream.read(reinterpret_cast<char *>(&counter), size);
    // Deserialize the map size
    std::unordered_map<std::string, int>::size_type mapSize;
    inStream.read(reinterpret_cast<char *>(&mapSize), sizeof(std::unordered_map<std::string, int>::size_type));
    // Deserialize each key-value pair in the map
    for (int i = 0; i < mapSize; ++i)
    {
        size_t strLength;
        inStream.read(reinterpret_cast<char *>(&strLength), sizeof(size_t));
        char strBuffer[strLength];
        inStream.read(strBuffer, strLength);
        std::string str(strBuffer, strLength);

        int fzInt = 0;
        inStream.read(reinterpret_cast<char *>(&fzInt), size);

        map[str] = fzInt;
    }
}