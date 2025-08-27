#include "rft_pair.hh"

void printRftPairMain()
{
    std::vector<std::pair<int, int>> v = {
        {1, 2},
        {1, 22},
        {1, 5},
        {1, 32},
        {1, 8}};

    for (auto &&i : v)
    {
        i.first = 5;
    }

    v.push_back(std::make_pair(8, 33));

    // sort(
    //     v.begin(),
    //     v.end(),
    //     [](std::pair<int, int> &a, std::pair<int, int> &b)
    //     {
    //         return a.second < b.second;
    //     });

    sort(
        v.begin(),
        v.end(),
        std::greater<std::pair<int, int>>());

    for (auto &&i : v)
    {
        std::cout << i.first << " " << i.second << "\n";
    }

    std::cout << "\n";
}