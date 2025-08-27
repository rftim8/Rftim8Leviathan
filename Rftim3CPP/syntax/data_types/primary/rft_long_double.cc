#include "rft_long_double.hh"

void printRftLongDoubleMain()
{
    long double a = 0.3 * 3 + 0.1;
    double a0 = 0.3 * 3 + 0.1;
    float a1 = 0.3 * 3 + 0.1;

    std::cout << "long double:\t" << sizeof(long double) << " bytes\n";
    std::cout << "long double:\t" << sizeof(long double) * 8 << " bits\n";

    printf("%.20Lf\n", a);
    printf("%.20f\n", a0);
    printf("%.20f\n", a1);
    // cout << ("%.9f", a) << "\n";
}