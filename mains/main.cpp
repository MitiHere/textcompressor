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

int main()
{
    funzipper fz = funzipper("text.txt");
    fz.print();
    return 0;
}
