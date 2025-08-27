#include "main.hh"

int main()
{
    speedup();
    system("cls");
    
    std::string problem_name = refactorProblemNumber(__FILE__);
    openProjectEulerProblemIOFiles(problem_name);

    dataCollector();

    for (int i = 0; i < _n; i++)
    {
        pe_00000001_0(_v[i]);
        pe_00000001_0_test(i, pe_00000001_0(_v[i]), _v0[i]);
    }

    closeIOStreams();

    return 0;
}
