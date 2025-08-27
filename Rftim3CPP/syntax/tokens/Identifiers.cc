#include "identifiers.hh"
/**
 * naming variables, functions, arrays
 */

// #include <iostream> // lower snake
// #define FAHR_TO_CELSIUS(x) 5 * (x - 32) / 9 // upper snake

int max_size = 200;       // lower snake
// const int MAX_SIZE = 200;       // upper snake
enum Widths
{
    LARGE,
    MEDIUM,
    SMALL
}; // upper snake

struct NamingConvention0 // pascal
{
    /* data */
};

class NamingConvention // pascal, no underscores
{
private:
    /* data */
public:
    NamingConvention(/* args */);
    ~NamingConvention();

    int calculateMaxSize(); // camel, first word is a verb
};

NamingConvention::NamingConvention(/* args */)
{
}

NamingConvention::~NamingConvention()
{
}

int NamingConvention::calculateMaxSize()
{
    return 0;
}

/*
    File name:
    - only '_' and '-' allowed
    - do not use filenames that already exist in /user/include or any predefined header file name

    Class name:
    - class name should be a noun
    - class name no underscores
    - class name pascal

    Method/Function:
    - function variables are also called automatic variables
    - method / function name should begin with a verb
    - method / function camel

    External variables:
    - can be defined even inside functions
    - are globally available
    - must be defined only once

    Variables:
    - the variable name should begin with an alphabet
    - digits at the end
    - underscores

    Constants:
    !- global constants upper snake separated with '_'

    - the private attributte name in class should be prepended with the character 'm'
    - after prepending 'm' the same rules apply for the name as that for the class name
    - character 'm' also precedes other name modifiers also. For example 'p' pointers
    - pointer variables should be prepended with 'p' and place the asterisk close to the variable name instead of the pointer type
    - referenece variables should be prepended with 'r'. This helps to differentiate between the method returning a modifiable object and the same method returning a non-modifiable object
    - static variables should be prepended with 's'
*/
