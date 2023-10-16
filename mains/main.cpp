/*#include "../funzipper/vectoredTxt.hpp"
#include "../funzipper/uwordmap.hpp"
*/
#include "../funzipper/funzipper.hpp"
int main()
{
    funzipper fz = funzipper("text.txt");
    /*
    vectoredTxt vt = vectoredTxt("text.txt");
    uwordmap um = uwordmap(vt);
    vt.print();
    um.print();
    */
    fz.print();
    return 0;
}