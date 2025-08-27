#include "rft_reference.hh"

void printReference()
{
    int x = 20;
    int y = x;
    int &ref = x;

    ref = 30;
    std::cout << "x = " << x << "\n";

    x = 40;
    std::cout << "ref = " << ref << "\n";
    std::cout << y << "\n";
}