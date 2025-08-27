#include "special_symbols.hh"

void printSpecialSymbols()
{
    std::vector<std::string> symbols = {
        "[]",
        "{}",
        "()",
        ",",
        ":",
        ".",
        ";",
        "*",
        "=",
        "#",
        "~"};

    for (auto &&i : symbols)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";
}