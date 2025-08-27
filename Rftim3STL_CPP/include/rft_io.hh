#pragma once
#include "rft_global_cpp.hh"

static std::ifstream in;
static std::ifstream in_sec;
static std::ofstream out;

static void closeIOStreams()
{
    if (in.is_open())
        in.close();

    if (in_sec.is_open())
        in_sec.close();

    if (out.is_open())
        out.close();
}
