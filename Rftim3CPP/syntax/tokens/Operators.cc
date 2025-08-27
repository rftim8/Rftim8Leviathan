#include "operators.hh"
/** Operator            Description                                     Associativity
 *
 *  ()                  parentheses (function call)                     left-to-right
 *  []                  brackets (array subscript)
 *  .                   member selection via object name
 *  ->                  member selection via a pointer
 *  ++/--               postfix increment / decrement
 *
 *  ++/--               prefix increment / decrement                    right-to-left
 *  +/-                 unary plus / minus
 *  !~                  logical negation / bitwise complement
 *  (type)              cast
 *  *                   dereference
 *  &                   address (of operand)
 *  (sizeof)            determine size in bytes
 *
 *  *,/,%               multiplication / division / modulus             left-to-right
 *
 *  +/-                 addition / subtraction                          -||-
 *
 *  <<,>>               bitwise shift left, right                       -||-
 *
 *  <,<=                relational less / less than or equal to         -||-
 *  >,>=                relational greater                              -||-
 *
 *  ==,!=               relational equal                                -||-
 *
 *  &                   bitwise AND                                     -||-
 *
 *  ^                   bitwise exclusive XOR                           -||-
 *
 *  |                   bitwise inclusive OR                            -||-
 *
 *  &&                  logical AND                                     -||-
 *
 *  ||                  logical OR                                      -||-
 *
 *  ?:                  ternary conditional                             right-to-left
 *
 *  =                   assignment                                      right-to-left
 *  +=,-=               addition,subtraction
 *  *=,/=               multiplication, division
 *  %=,&=               modulus / bitwise AND
 *  ^=,!=               bitwise exclusive / inclusive OR
 *  <>=                 bitwise shift left / right
 *  ,                   expression separator                            left-to-right
 */
void printOperators()
{
    // printArithmeticOperstors();
    // printAssignmentOperstors();
    printBitwiseOperstors();
    // printLogicalOperstors();
    // printMiscellaneousOperators();
    // printRelationalOperstors();
    // printScopeResolutionOperator();
    // printTernaryOperstors();
    // printUnaryOperators();
}

// + - * / %
static void printArithmeticOperstors()
{
}

// = += -= *= /= %=
static void printAssignmentOperstors()
{
}

// & | << >> ~ ^
static void printBitwiseOperstors()
{
    int a = 2;
    int b = 3;

    std::cout << (a & b) << "\n";  // Binary AND - conjunction
    std::cout << (a | b) << "\n";  // Binary OR - disjunction
    std::cout << (a ^ b) << "\n";  // Binary XOR - disjunction exclusive
    std::cout << (a <= b) << "\n"; // Binary XOR - implication
    std::cout << (a == b) << "\n"; // Binary XOR - equivalence
    std::cout << (a << b) << "\n"; // Left Shift
    std::cout << (a >> b) << "\n"; // Right Shift
    std::cout << ~a << "\n";       // One's Complement - negation
    std::cout << ~b << "\n";       // One's Complement - negation

    std::vector<int> x = {0, 0, 1, 1};
    std::vector<int> y = {0, 1, 0, 1};

    for (int i = 0; i < 4; i++)
    {
        std::cout << (!x[i]) << " ";
        std::cout << (!y[i]) << " ";
        std::cout << (x[i] & y[i]) << " ";
        std::cout << (x[i] | y[i]) << " ";
        std::cout << (x[i] ^ y[i]) << " ";
        std::cout << (x[i] <= y[i]) << " ";
        std::cout << (x[i] == y[i]) << " ";

        std::cout << "\n";
    }
}

// && || !
static void printLogicalOperstors()
{
}

/**
 * ,
 * -> (variables of class / structs)
 * . (members of class obj / structs variables)
 * * (indirection operator)
 * & (memory operator)
 * << (insertion operator)
 * >> (extraction operator)
 */
static void printMiscellaneousOperators()
{
}

// < <= > >= == !=
static void printRelationalOperstors()
{
}

static int x = 10;
// ::
static void printScopeResolutionOperator()
{
    int x = 25;
    std::cout << ::x << "\n";
}

// ?:
static void printTernaryOperstors()
{
}

// ++ -- sizeof (cast)
static void printUnaryOperators()
{
}