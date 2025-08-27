#include "rft_raii.hh"

std::mutex m;
static bool f() { return true; }
static bool everything_ok() { return true; }

void rftRAIIMain()
{
}

static void bad()
{
    m.lock(); // acquire mutex
    f();      // if f() throws an exception, the mutex is never released
    if (!everything_ok())
        return; // early return, the mutex is never released

    m.unlock(); // if bad() reaches this statement, the mutex is released
}

static void good()
{
    std::lock_guard<std::mutex> lk(m); // RAII class: mutex acquisition is initialization
    f();                               // if f() throws an exception, the mutex is released
    if (!everything_ok())              // early return, the mutex is released
        return;                        // if good() returns normally, the mutex is released
}
