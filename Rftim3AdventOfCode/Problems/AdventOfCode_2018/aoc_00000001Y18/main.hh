#pragma once
#include "rft_adventofcode.hh"

static int _n, _m;
static std::vector<std::vector<int>> _v;
static std::vector<int> _v0;

static void dataCollector()
{
    in >> _n;
    in >> _m;

    for (int i = 0; i < _n * _m; i += _m)
    {
        
    }
};

int aoc_00000001Y18_0(std::vector<int> nums);
void aoc_00000001Y18_0_test(int case_nr, int actual, int expected);
