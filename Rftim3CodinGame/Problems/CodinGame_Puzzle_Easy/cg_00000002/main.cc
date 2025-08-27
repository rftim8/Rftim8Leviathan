#include "main.hh"

int main()
{
    speedup();
    system("cls");
    
    std::string problem_name = refactorProblemNumber(__FILE__);
    openCodinGameProblemIOFiles(problem_name);

    dataCollector();

    for (int i = 0; i < _n; i++)
    {
        cg_00000002_0(_v[i]);
        cg_00000002_0_test(i, cg_00000002_0(_v[i]), _v0[i]);
    }

    closeIOStreams();

    return 0;
}
