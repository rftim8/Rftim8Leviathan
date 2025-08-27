#include "escape_sequence.hh"

void printEscapeSequencesMain()
{
    std::cout << "alarm / beep: \a\n";
    std::cout << "backspace:\btest\n";
    std::cout << "form feed:\ftest\n";
    std::cout << "carriage return:\rtest\n";
    std::cout << "horizontal tab: \ttest\n";
    std::cout << "vertical tab:\vtest\n";
    std::cout << "backslash:\\test\n";
    std::cout << "single quote:\'test\n";
    std::cout << "double quote:\"test\n";
    std::cout << "question mark:\?test\n";
    std::cout << "octal number: test\n";
    std::cout << "hexadecimal number: test\n";
    std::cout << "NULL: \0 test\n";
    std::cout << "space character: test\n";
    std::cout << "delete character: test\n";
}