#include "rft_string.hh"

void printString()
{
    splitStringSpace();
    RFT_SEPARATOR

    printRepeatedChar();
    RFT_SEPARATOR

    printStringByChar();
    RFT_SEPARATOR

    findCharInString('t');
    RFT_SEPARATOR

    replaceCharInString();
    RFT_SEPARATOR

    removeCharInString("tester", 'e');
    RFT_SEPARATOR

    reverseString("test");
    RFT_SEPARATOR

    stringToVectorChar("test");
    RFT_SEPARATOR
}

static void splitStringSpace()
{
    std::string s = "Test tes te";
    std::stringstream ss(s);
    std::string t;
    while (ss >> t)
    {
        std::cout << t << "\n";
    }
}

static void printRepeatedChar()
{
    std::string s(5, 'w');
    std::cout << s << "\n";
}

static void printStringByChar()
{
    std::string s = "Halloween";

    char *p = &s[0];

    while (*p != '\0')
    {
        std::cout << *p << "\n";
        p++;
    }
}

static void findCharInString(char c)
{
    std::vector<std::string> v = {
        "ewrwerwe rw er wet",
        "ewerwerw er wet",
        "ewerwererwet",
        "ew rerwet",
        "ewrwrwerwet",
        "ewrw rer wet",
        "ewrwerwererwet",
        "qweqwrer"};

    for (auto &&i : v)
    {
        int j = i.find(c);
        if (j != std::string::npos)
            std::cout << j << "\n";
        else
            std::cout << "Not found\n";
    }
}

static void replaceCharInString()
{
    std::string s = "qwrwenureqierere";
    replace(s.begin(), s.end(), 'e', ' ');

    std::cout << s << "\n";
}

static void removeCharInString(std::string s, char c)
{
    s.erase(remove(s.begin(), s.end(), c), s.end());

    std::cout << s << "\n";
}

static void reverseString(std::string s)
{
    reverse(s.begin(), s.end());
    std::string t(s.rbegin(), s.rend());

    std::cout << s << "\n";
    std::cout << t << "\n";
}

static void stringToVectorChar(std::string s)
{
    std::vector<char> res(s.begin(), s.end());
    for (auto &&i : res)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}
