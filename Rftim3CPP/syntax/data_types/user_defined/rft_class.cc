#include "rft_class.hh"

thread_local int z = 10;
int RftClass::a = 52;

// auto storage class
void printClass()
{
    // thread_local storage class
    std::thread th1([]()
                    { std::cout << "Thread 1 z = " << (z += 1) << "\n"; });

    std::thread th2([]()
                    { std::cout << "Thread 2 z = " << (z += 2) << "\n"; });

    std::thread th3([]()
                    { std::cout << "Thread 3 z = " << (z += 3) << "\n"; });

    th1.join();
    th2.join();
    th3.join();

    RftClass::printStatic();

    // mutable storage class
    const RftClass x;
    x.c = 10;
    std::cout << x.c << "\n";
    std::cout << x.a << "\n";

    externStorageClass();

    std::cout << staticStorageClass() << "\n";
    std::cout << staticStorageClass() << "\n";
}

// extern storage class
static int y;
static void externStorageClass()
{
    extern int y;
    std::cout << y << "\n";

    y = 2;
    std::cout << y << "\n";
}

// static storage class
static int staticStorageClass()
{
    static int x = 0;
    x++;
 
    return x;
}
