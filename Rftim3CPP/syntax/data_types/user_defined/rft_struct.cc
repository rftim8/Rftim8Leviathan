#include "rft_struct.hh"

void printStruct()
{
    std::vector<rftStruct> z(10, {10, 20});

    struct rftStruct arr[10];
    arr[0].x = 10;
    arr[0].y = 20;

    for (auto &&i : z)
    {
        std::cout << i.x << " " << i.y << "\n";
    }
    std::cout << "\n";
}