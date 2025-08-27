#include "main.hh"

int main()
{
    speedup();
    system("cls");
    
    std::string problem_name = refactorProblemNumber(__FILE__);
    openLeetCodeProblemIOFiles(problem_name);

    dataCollector();

    for (int i = 0; i < _n; i++)
    {
        lc_00000387_0(_v[i]);
        lc_00000387_0_test(i, lc_00000387_0(_v[i]), _v0[i]);
    }

    closeIOStreams();

    return 0;
}
