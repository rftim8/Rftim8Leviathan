#include "rft_float.hh"

void printRftFloatMain()
{
    char scale[6] = "bytes";

    std::cout << "float:\t" << sizeof(float) << " " << scale << "\n";

    scale[0] = 'b';
    scale[1] = 'i';
    scale[2] = 't';
    scale[3] = 's';
    scale[4] = ' ';

    std::cout << "float:\t" << sizeof(float) * 8 << " " << scale << "\n";
}