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

void constitution()
{
    funzipper fz = funzipper("constitution.txt");
    fz.saveToFile("constitution.fz");
}
void tartuffe()
{
    funzipper fz = funzipper("tartuffe.txt");
    fz.saveToFile("tartuffe.fz");
    // fz.print();

    funzipper newfz = funzipper();
    newfz.readFromFile("tartuffe.fz");
    std::cout << fz.getWm().getCounterSize() << std::endl;
}
void miserable()
{
    funzipper fz = funzipper("miserable.txt");
    fz.saveToFile("miserable.fz");
}
int main()
{
    /*funzipper fz = funzipper("text.txt");
    fz.print();*/
    constitution();
    tartuffe();
    miserable();
    return 0;
}
