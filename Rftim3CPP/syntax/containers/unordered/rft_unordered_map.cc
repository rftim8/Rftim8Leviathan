#include "rft_unordered_map.hh"

void printRftUnorderedMap()
{
    std::unordered_map<int, int> um = {};

    for (int i = 0; i < 10; i++)
    {
        um[i] = i * 2;
    }

    for (auto &&i : um)
    {
        std::cout << i.first << " " << i.second << "\n";
    }
    std::cout << "\n";
}