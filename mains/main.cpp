#include "../funzipper/funzipper.hpp"

void testSerializeWm()
{
    funzipper fz = funzipper("text.txt");
    // fz.print();
    std::stringstream ss;
    fz.getWm().serialize(ss);
    fz.getWm().print();
    // Create a new instance for deserialization
    uwordmap newMap;
    newMap.deserialize(ss);
    newMap.print(); // Assuming you have a print function in your class
}

void testHaldSer()
{
    funzipper fz = funzipper("text.txt");
    uwordmap uw = fz.getWm();
    std::vector<std::vector<int>> aa = fz.buildVectoredInt();
}

void testFullSerialize()
{
    funzipper fz = funzipper("text.txt");
    std::stringstream ss;
    fz.serialize(ss);
    fz.print();

    funzipper newz = funzipper(ss);
    newz.print();
}

void testWithFile()
{
    funzipper fz = funzipper("text.txt");
    fz.saveToFile("data.fz");
    // fz.print();

    funzipper newfz = funzipper();
    newfz.readFromFile("data.fz");
    // fz.print();
    fz.getWm().getCounterSize();
    std::cout << fz.getWm().getCounterSize() << std::endl;
}
int main()
{
    /*funzipper fz = funzipper("text.txt");
    fz.print();*/
    testWithFile();
    return 0;
}
