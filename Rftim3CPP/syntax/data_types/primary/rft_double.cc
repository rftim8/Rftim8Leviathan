#include "rft_double.hh"

void printRftDoubleMain()
{
    char scale[6] = "bytes";

    std::cout << "double:\t" << sizeof(double) << " " << scale << "\n";

    scale[0] = 'b';
    scale[1] = 'i';
    scale[2] = 't';
    scale[3] = 's';
    scale[4] = ' ';

    std::cout << "double:\t" << sizeof(double) * 8 << " " << scale << "\n";

    castStringToDouble();
    printAccuracyError();
}

static void castStringToDouble()
{
    std::string s = "3.2500";
    std::cout << stod(s) << "\n";
}

static void printAccuracyError()
{
    double x = 0.3 * 3 + 0.1;

    std::cout.precision(20);
    std::cout.fixed;
    std::cout << x << "\n";

    std::cout << std::fixed << std::setprecision(10) << x << "\n";
}
