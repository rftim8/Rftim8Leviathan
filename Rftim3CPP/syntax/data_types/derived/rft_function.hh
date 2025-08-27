#pragma once
#include "rft_global_cpp.hh"

void printFunction();

#pragma region Inline
static void printInlineFunction();

class operation
{
    int a, b, add, sub, mul;
    float div;

public:
    void get();
    void sum();
    void difference();
    void product();
    void division();
};

inline void operation::get()
{
    std::cout << "Enter first value: ";
    std::cin >> a;
    std::cout << "Enter second value: ";
    std::cin >> b;
}

inline void operation::sum()
{
    add = a + b;
    std::cout << "Addition of two numbers: " << a + b << "\n";
}

inline void operation::difference()
{
    sub = a - b;
    std::cout << "Difference of two numbers: " << a - b << "\n";
}

inline void operation::product()
{
    mul = a * b;
    std::cout << "Product of two numbers: " << a * b << "\n";
}

inline void operation::division()
{
    div = a / b;
    std::cout << "Division of two numbers: " << a / b << "\n";
}
#pragma endregion
