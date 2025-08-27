#include "rft_projecteuler.hh"

int main()
{
    speedup();
    std::system("cls");

    rft_projecteuler_csv pe_csv;
    pe_csv.competition_name = "ProjectEuler";
    pe_csv.rank = 0;
    pe_csv.rating = 0;
    pe_csv.problem_number = "pe_00000001";
    pe_csv.problem_title = "MultiplesOf3Or5";
    pe_csv.problem_description = R"(
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000)";
    pe_csv.problem_input = R"(1
1
233168)";
    pe_csv.difficulty = 0;
    pe_csv.algorithms = {""};
    insertPGProjectEulerFullProblem(pe_csv);

    closeIOStreams();

    return 0;
}