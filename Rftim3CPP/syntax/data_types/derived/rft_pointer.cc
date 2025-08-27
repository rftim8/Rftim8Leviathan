#include "rft_pointer.hh"

void printPointer()
{
    int x = 5;
    int *p = &x;

    std::cout << x << "\n";
    std::cout << &x << "\n";
    std::cout << p << "\n";
    std::cout << *p << "\n";
    std::cout << &p << "\n";
}