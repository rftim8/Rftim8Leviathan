#include "main.hh"

int main()
{
    speedup();
    system("cls");
    
    std::string problem_name = refactorProblemNumber(__FILE__);
    openAdventOfCodeProblemIOFiles(problem_name);

    dataCollector();

    for (int i = 0; i < _n; i++)
    {
        aoc_00000001Y18_0(_v[i]);
        aoc_00000001Y18_0_test(i, aoc_00000001Y18_0(_v[i]), _v0[i]);
    }

    closeIOStreams();

    return 0;
}
