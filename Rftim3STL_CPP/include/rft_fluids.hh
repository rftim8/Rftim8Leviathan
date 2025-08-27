#pragma once
#include "rft_global_cpp.hh"

static void fillingATankWithTwoFaucets(int faucetTime1, int faucetTime2)
{
    int x, y, q1, q2;

    std::cout << "Time running faucet 1 = ";
    std::cin >> faucetTime1;
    std::cout << "Time running faucet 2 = ";
    std::cin >> faucetTime2;

    std::cout << "Liters after x hours: ";
    std::cin >> x;
    std::cout << "Liters after faucetTime1 + 1 hour and faucetTime2 - 1 hour: ";
    std::cin >> y;

    std::cout << "Quantity runned through first faucet: " << (q1 = (x - faucetTime1 * (y - x)) / (faucetTime2 + faucetTime1)) << "\n";
    std::cout << "Quantity runned through second faucet: " << (q2 = (y - x) + q1) << "\n";
}
