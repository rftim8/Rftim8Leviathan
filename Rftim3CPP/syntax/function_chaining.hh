#pragma once
#include "rft_global_cpp.hh"

class Tester
{
private:
    /* data */
public:
    Tester &Talk();
    Tester &Smile();
};

inline Tester &Tester::Talk()
{
    std::cout << "Talk test\n";
    return *this;
}

inline Tester &Tester::Smile()
{
    std::cout << "Now smile\n";
    return *this;
}

void printFunctionChainExample();
