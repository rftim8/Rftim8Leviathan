#include "rft_vector.hh"

void RftVector::elementInVector()
{
    std::vector<int> x = {1, 2, 3, 3, 4};
    std::cout << (find(x.begin(), x.end(), 3) != x.end()) << "\n";
}

void RftVector::getElementInVector()
{
    elementInVector();
}

void RftVector::enumerableVector()
{
    std::vector<int> v(10);
    generate(v.begin(), v.end(), [a = 1]() mutable
             { return a++; });

    for (auto &&i : v)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::vector<int> v0(10);
    iota(v0.begin(), v0.end(), 1);

    for (auto &&i : v0)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void RftVector::getEnumerableVector()
{
    enumerableVector();
}

void RftVector::minElementInVector()
{
    std::vector<int> v = {12, 3, 3, 4, 5};
    std::cout << *min_element(v.begin(), v.end()) << "\n";
}

void RftVector::getMinElementInVector()
{
    minElementInVector();
}

void RftVector::sumOfVector()
{
    std::vector<int> v = {12, 3, 3, 4, 5};
    std::cout << accumulate(v.begin(), v.end(), 0) << "\n";
}

void RftVector::getSumOfVector()
{
    sumOfVector();
}

void RftVector::vectorWithErasedElement()
{
    std::vector<int> v = {12, 3, 3, 4, 5};
    v.erase(v.begin() + 2);

    for (auto &&i : v)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void RftVector::getVectorWithErasedElement()
{
    vectorWithErasedElement();
}

RftVector::RftVector()
{
}

RftVector::~RftVector()
{
}
