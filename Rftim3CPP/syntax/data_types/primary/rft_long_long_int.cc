#include "rft_long_long_int.hh"

void printRftLongLongMain()
{
    long long res = 24353245325345;
    int a = sizeof(long long);

    std::cout << "long long:\t" << a << " bytes\nlong long:\t" << a * 8 << " bits\n";
}