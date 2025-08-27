#include "rft_tuple.hh"

static void sortVectorTuples(std::vector<std::tuple<int, int, float, std::string>> &v);

/**
 * Pair
 *
 *
 * OOP:
 * class
 * objects
 * abstraction
 * encapsulation
 * inheritance
 * polymorphism
 *
 * multi-threading (Linux POSIX threads):
 * process-based
 * thread-based
 *
 *
 */
void printRftTupleMain()
{
    std::vector<std::tuple<int, int, float, std::string>> v = {
        {0, 1, 12.5, "qwerwe"},
        {0, 1, 33.5, "qwerwe"},
        {0, 1, 5.5, "qwerwe"},
        {0, 1, 2.5, "qwerwe"}};

    std::get<2>(v[0]) = 8.5;
    std::cout << std::get<0>(v[0]) << " " << std::get<1>(v[0]) << " " << std::get<2>(v[0]) << " " << std::get<3>(v[0]) << "\n";
    std::cout << "\n";

    sortVectorTuples(v);
}

static void sortVectorTuples(std::vector<std::tuple<int, int, float, std::string>> &v)
{
    sort(
        v.begin(),
        v.end(),
        [](const std::tuple<int, int, float, std::string> &a,
           const std::tuple<int, int, float, std::string> &b) -> bool
        {
            return std::get<2>(a) < std::get<2>(b);
        });

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << std::get<0>(v[i]) << " " << std::get<1>(v[i]) << " " << std::get<2>(v[i]) << " " << std::get<3>(v[i]) << "\n";
    }
}