#include "rft_int.hh"

void printRftIntMain()
{
    char scale[6] = "bytes";

    std::cout << "int:\t" << sizeof(int) << " " << scale << "\n";

    scale[0] = 'b';
    scale[1] = 'i';
    scale[2] = 't';
    scale[3] = 's';
    scale[4] = ' ';

    std::cout << "int:\t" << sizeof(int) * 8 << " " << scale << "\n";
}