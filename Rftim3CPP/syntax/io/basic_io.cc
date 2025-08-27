#include "basic_io.hh"

void printBasicIO()
{
    // printCinGet();
    // printCinRead();

    // printCoutWrite();
    printGetline();
}

static void printCinGet()
{
    int c;
    std::cin >> c;
    std::cin.get();

    std::cout << c << "\n";
    std::cerr << "Error log: " << "\n";

    std::cout << "Enter string: \n";
    char ch[30];
    std::cin.get(ch, 25);

    std::cout << ch << "\n";
}

static void printCinRead()
{
    char gfg[20];

    std::cin.read(gfg, 10);
    std::cin.get(gfg, 1);
    std::cout << gfg << std::endl;
}

static void printCoutWrite()
{
    char gfg[] = "testing write";
    char ch = 'q';

    std::cout.write(gfg, 6);
    std::cout.put(ch);

    std::cout << "\n";

    double pi = 3.14159783;
    std::cout.precision(5);

    std::cout << pi << "\n";
}

static void printGetline()
{
    std::istringstream str("     Programmer");
    std::string line;
    getline(str >> std::ws, line);

    std::cout << line << "\n";

    str.clear();
    str.str("tes1,test2, tes3, tes3");
    std::string t;
    while (getline(str, t, ','))
    {
        std::cout << t << "\n";
    }
}
