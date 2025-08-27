#include "rft_union.hh"

void printUnion()
{
    union rftUnion u;

    u.x = 2;
    std::cout << u.x << " " << u.y << "\n";
    u.y = 10;
    std::cout << u.x << " " << u.y << "\n";
}