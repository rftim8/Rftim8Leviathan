#pragma once
#include "rft_global_cpp.hh"

static float convertFahrenheitToCelsius(int fahr)
{
    float celsius;
    celsius = 5 * (fahr - 32) / 9;

    return celsius;
}