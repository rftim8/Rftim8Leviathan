#include "rft_char.hh"

void printRftCharMain()
{
    char scale[6] = "bytes";

    std::cout << "char:\t" << sizeof(char) << " " << scale << "\n";

    scale[0] = 'b';
    scale[1] = 'i';
    scale[2] = 't';
    scale[3] = 's';
    scale[4] = ' ';

    std::cout << "char:\t" << sizeof(char) * 8 << " " << scale << "\n";
}