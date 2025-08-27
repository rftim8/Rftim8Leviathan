#include "casting_operators.hh"

void printCastingOperatorsMain()
{
    // printConstCast(); // modify const or volatile qualifier
    // printDynamicCast(); // downcasting, convert pointer of a base class to a derived class
    printExplicitCast();
    printImplicitCast();
    // printReinterpretCast(); // convert pointer to any other type of pointer
    // printStaticCast(); // compile-time explicit conversion
}

static void printConstCast()
{
    const int number = 5;
    const int *ptr = &number;

    int *nonConstPtr = const_cast<int *>(ptr);
    *nonConstPtr = 10;

    std::cout << "Modified number: " << *nonConstPtr << "\n";
    std::cout << number << "\n";
}

static void printDynamicCast()
{
    Animal *animalPtr = new Dog();

    // downcasting
    Dog *dogPtr = dynamic_cast<Dog *>(animalPtr);
    if (dogPtr)
        dogPtr->speak();
    else
        std::cout << "Failed to cast to Dog.\n";

    // Fail to cast to cat because animal pointer has already been cast to dog
    Cat *catPtr = dynamic_cast<Cat *>(animalPtr);
    if (catPtr)
        catPtr->speak();
    else
        std::cout << "Failed to cast to Cat.\n";

    delete animalPtr;
}

static void printExplicitCast()
{
    int x = 65;
    std::cout << (char)x << "\n";
}

static void printImplicitCast()
{
    // bool -> char -> short int -> int ->
    // unsigned int -> long -> unsigned ->
    // long long -> float -> double -> long double
    int x = 10;
    char y = 'a';

    std::cout << x + y << "\n";
}

static void printReinterpretCast()
{
    int number = 10;
    int *numberPointer = &number;

    char *charPointer = reinterpret_cast<char *>(numberPointer);

    std::cout << "Integer Address: " << numberPointer << "\n";
    std::cout << "Char Address: " << reinterpret_cast<void *>(charPointer) << "\n";
}

static void printStaticCast()
{
    int num = 10;

    // converting int to double
    double d = static_cast<double>(num);

    // print data type
    std::cout << typeid(num).name() << "\n";

    // typecasting
    std::cout << typeid(static_cast<double>(num)).name() << "\n";

    // print double type t
    std::cout << typeid(d).name() << "\n";
}
