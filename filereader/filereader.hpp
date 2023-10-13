#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include <string>
#include <vector>
int main();
std::vector<std::vector<std::string>> buildVectorFromFile(std::string filename);
void printVectorOfVector(const std::vector<std::vector<std::string>> &data);
#endif
