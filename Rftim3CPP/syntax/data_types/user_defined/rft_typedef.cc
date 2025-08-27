#include "rft_typedef.hh"

void printTypedef()
{
    rftByte a, b;
    a = 'a';
    b = a + 2;
    std::cout << a << " " << b << "\n";

    ll x = 123456789;
    ll y = 987654321;
    std::cout << x * y << "\n";

    REP(i, 2, 20)
        std::cout << "Test" << "\n";
}