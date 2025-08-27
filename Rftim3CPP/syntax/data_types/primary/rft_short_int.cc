#include "rft_short_int.hh"

void printRftShortMain()
{
    char scale[6] = "bytes";
    short x = 0;
    short int x0 = 0;

    std::cout << "short:\t" << sizeof(short) << " " << scale << "\n";

    scale[0] = 'b';
    scale[1] = 'i';
    scale[2] = 't';
    scale[3] = 's';
    scale[4] = ' ';

    std::cout << "short:\t" << sizeof(short) * 8 << " " << scale << "\n";
}