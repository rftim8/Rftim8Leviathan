#include "rft_function.hh"

void printFunction()
{
    printInlineFunction();
}

/**
 * advantages: for small functions by storing the instruction address in CPU memory
 */
static void printInlineFunction()
{
    std::cout << "Program using inline function\n";

    operation s;
    s.get();
    s.sum();
    s.difference();
    s.product();
    s.division();
}