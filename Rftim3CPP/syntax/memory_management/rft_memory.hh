#pragma once
#include "rft_global_cpp.hh"

struct cust
{
    int p;
    cust(int q) : p(q) {}
    cust() = default;
};

void printRftMemory();

static void printBasicNewDelete();
static void printBlockMemory();
