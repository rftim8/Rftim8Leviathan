#pragma once
#include "rft_global_cpp.hh"

static void unitTest(std::ofstream &out, int case_nr, int actual, int expected)
{
    out << "Testcase: " << case_nr << "\n";
    bool test = actual == expected;

    if (test)
        out << "PASS\n";
    else
    {
        out << "Actual: " << actual << "\n";
        out << "Expected: " << expected << "\n";
    }

    out << "\n";
}

static void unitTest(std::ofstream &out, int case_nr, std::string actual, std::string expected)
{
    out << "Testcase: " << case_nr << "\n";
    bool test = actual == expected;

    if (test)
        out << "PASS\n";
    else
    {
        out << "Actual: " << actual << "\n";
        out << "Expected: " << expected << "\n";
    }

    out << "\n";
}

static void unitTest(std::ofstream &out, int case_nr, std::vector<int> actual, std::vector<int> expected)
{
    out << "Testcase: " << case_nr << "\n";
    std::vector<int> result = actual;
    bool test = result == expected;

    if (test)
        out << "PASS\n";
    else
    {
        out << "Actual: ";
        for (int j = 0; j < result.size(); j++)
        {
            out << result[j] << " ";
        }
        out << "\n";

        out << "Expected: ";
        for (int j = 0; j < expected.size(); j++)
        {
            out << expected[j] << " ";
        }
        out << "\n";
    }

    out << "\n";
}
