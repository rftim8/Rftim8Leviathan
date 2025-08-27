#pragma once
#include "rft_global_cpp.hh"

static std::vector<int> v = {1, 2, 3, 5};

static std::vector<std::vector<int>> subsets(std::vector<int> &nums)
{
    std::vector<std::vector<int>> v = {{}};

    for (auto &&i : nums)
    {
        std::vector<std::vector<int>> x = {};

        for (auto &&j : v)
        {
            std::vector<int> y = {j};
            y.push_back(i);
            x.push_back(y);
        }

        v.insert(v.end(), x.begin(), x.end());
    }

    return v;
}

static void printSubsetsMain()
{
    std::vector<std::vector<int>> res = subsets(v);

    for (auto &&i : res)
    {
        for (auto &&j : i)
        {
            std::cout << j << " ";
        }

        std::cout << "\n";
    }
}
