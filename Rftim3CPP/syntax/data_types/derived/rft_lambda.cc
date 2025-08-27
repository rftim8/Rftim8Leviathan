#include "rft_lambda.hh"

void printLambda()
{
    countOccurrencesInVector();
    SEPARATOR
    findGreaterElementInVector();
    SEPARATOR
    printFactorialFromVector();
    SEPARATOR
    removeDuplicateElements();
    SEPARATOR
    sortVectorLambda();
}

static void countOccurrencesInVector()
{
    std::vector<int> v = {1, 4, 3, 4, 5, 6};
    int count_4 = count_if(v.begin(), v.end(), [](int a)
                           { return a == 4; });

    std::cout << count_4 << "\n";
}

static void findGreaterElementInVector()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    std::vector<int>::iterator p = find_if(v.begin(), v.end(), [](int i)
                                           { return i > 4; });

    std::cout << *p << "\n";
}

static void printFactorialFromVector()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = std::accumulate(arr, arr + 10, 1, [](int i, int j)
                            { return i * j; });
    std::cout << x << "\n";
}

static void removeDuplicateElements()
{
    std::vector<int> v = {1, 23, 3, 4, 9, 5, 5, 23, 23, 1};
    sort(v.begin(), v.end());

    std::vector<int>::iterator p = unique(v.begin(), v.end(), [](int a, int b)
                                          { return a == b; });

    v.resize(distance(v.begin(), p));
    for (auto &&i : v)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

static void sortVectorLambda()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6};

    sort(v.begin(), v.end(), [](const int &a, const int &b) -> bool
         { return b > a; });

    for (auto &&i : v)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}
