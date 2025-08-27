#include "rft_codingame.hh"

int main()
{
    speedup();
    std::system("cls");

    rft_codingame_csv cg_csv;
    cg_csv.competition_name = "CodinGame_Puzzle_Easy";
    cg_csv.rank = 0;
    cg_csv.rating = 0;
    cg_csv.problem_number = "cg_00000002";
    cg_csv.problem_title = "7segmentScanner";
    cg_csv.problem_description = R"(
Given an ASCII art representation of 7-segment display you need to convert it to a number.

Note: number should be converted as is, including leading zeroes.
Input
3 lines: 7-segment display image consisting only of vertical lines, underscores and spaces.
Length of every line is divisible by 3 (so trailing spaces are preserved).
Output
One line: The number. Leading zeros should be preserved.
Constraints
3 ≤ digit count ≤ 300)";
    cg_csv.problem_input = R"(1
4
 _     _  _     _  _  _  _  _
| |  | _| _||_||_ |_   ||_||_|
|_|  ||_  _|  | _||_|  ||_| _|
0123456789)";
    cg_csv.difficulty = 0;
    cg_csv.algorithms = {""};
    insertPGCodinGameFullProblem(cg_csv);

    closeIOStreams();

    return 0;
}