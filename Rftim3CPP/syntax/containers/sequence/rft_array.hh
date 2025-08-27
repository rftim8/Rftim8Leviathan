#pragma once
#include "rft_global_cpp.hh"

void printArray();

static void initializeInt1DArray(int n, int *p);
static void printInt1DArrayByPointer(int n, int *p);
static void printInt1DArrayByRef(int n, int (&arr)[]);
static void printInt2DArrayByPointer(int rows, int columns, int (*p)[5]);
static void printInt2DArrayByRef(int rows, int columns, int (&arr)[][5]);
static void print1DArrayByPointer(int n, int[]);

