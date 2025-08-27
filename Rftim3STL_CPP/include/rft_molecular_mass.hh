#pragma once
#include "rft_global_cpp.hh"

static void MolecularMass()
{
    unsigned nC, nO, nH, m;

    std::cout << "Enter number of carbon atoms: ";
    std::cin >> nC;
    std::cout << "Enter number of oxigen atoms: ";
    std::cin >> nO;
    std::cout << "Enter number of hidrogen atoms: ";
    std::cin >> nH;

    std::cout << "Molecular mass of the compund = " << 12 * nC + 16 * nO + nH << "\n";
}
