#pragma once
#include "rft_global_cpp.hh"

void printCastingOperatorsMain();

#pragma region Const
static void printConstCast();
#pragma endregion

#pragma region Dynamic
static void printDynamicCast();
class Animal
{
public:
    virtual void speak() const
    {
        std::cout << "Animal speaks.\n";
    }
};

class Dog : public Animal
{
public:
    void speak() const override
    {
        std::cout << "Dog barks.\n";
    }
};

class Cat : public Animal
{
public:
    void speak() const override
    {
        std::cout << "Cat meows.\n";
    }
};
#pragma endregion

#pragma region Explicit
static void printExplicitCast();
#pragma endregion

#pragma region Implicit
static void printImplicitCast();
#pragma endregion

#pragma region Reinterpret
static void printReinterpretCast();
#pragma endregion

#pragma region Static
static void printStaticCast();
#pragma endregion

