#include "macros.hh"

void printMacrosMain()
{
    RFT_TITLE("Macros")
    std::cout << COMPARE(1, 2) << "\n";
    std::cout << COMPARE("a", "b") << "\n";
    std::cout << FAHR_TO_CELSIUS(102) << "\n";
    std::cout << CELSIUS_TO_FAHR(23) << "\n";
    RFT_SEPARATOR
}