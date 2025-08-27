#pragma once
#include "rft_global_cpp.hh"

class RftClass
{
private:
public:
    static int a; // static variable
    int b;        // instance variable
    mutable int c;

    static void printStatic();
    void localTest();

    RftClass();
};

inline void RftClass::printStatic()
{
    std::cout << "From static function in class\n";
}

inline void RftClass::localTest()
{
    int c; // local variable
}

inline RftClass::RftClass()
{
}

void printClass();
static void externStorageClass();
static int staticStorageClass();