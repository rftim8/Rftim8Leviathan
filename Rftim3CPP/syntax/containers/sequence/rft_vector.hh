#pragma once
#include "rft_global_cpp.hh"

class RftVector
{
private:
    void elementInVector();
    void enumerableVector();
    void minElementInVector();
    void sumOfVector();
    void vectorWithErasedElement();

public:
    void getElementInVector();
    void getEnumerableVector();
    void getMinElementInVector();
    void getSumOfVector();
    void getVectorWithErasedElement();
    RftVector();
    ~RftVector();
};
