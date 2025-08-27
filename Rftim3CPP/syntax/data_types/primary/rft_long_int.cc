#include "rft_long_int.hh"

void printRftLongMain()
{
    char scale[6] = "bytes";

    long int x;
    long x0;

    std::cout << "long:\t" << sizeof(long) << " " << scale << "\n";

    scale[0] = 'b';
    scale[1] = 'i';
    scale[2] = 't';
    scale[3] = 's';
    scale[4] = ' ';

    std::cout << "long:\t" << sizeof(long) * 8 << " " << scale << "\n";
}