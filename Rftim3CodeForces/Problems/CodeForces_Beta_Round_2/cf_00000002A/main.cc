#include "main.hh"

int main()
{
    speedup();
    system("cls");
    
    std::string problem_name = refactorProblemNumber(__FILE__);
    openCodeForcesProblemIOFiles(problem_name);

    dataCollector();

    for (int i = 0; i < _n; i++)
    {
        cf_00000002A_0(_v[i]);
        cf_00000002A_0_test(i, cf_00000002A_0(_v[i]), _v0[i]);
    }

    closeIOStreams();

    return 0;
}
