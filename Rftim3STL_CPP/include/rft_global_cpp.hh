#pragma once
#define _USE_MATH_DEFINES
// Generic

// #pragma region bits/stdc++.h
// #include <algorithm>
// #include <bitset>
// #include <cmath>
// #include <codecvt>
// #include <ctime>
// #include <filesystem>
// #include <fstream>
// #include <iomanip>
// #include <iostream>
// #include <list>
// #include <mutex>
// #include <numeric>
// #include <optional>
// #include <queue>
// #include <sstream>
// #include <stack>
// #include <string>
// #include <string_view>
// #include <thread>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>
// #pragma endregion

#pragma region Libraries
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <thread>
#include <string.h>
#include <mutex>
#include <optional>
#include <bitset>
#include <list>
#include <string_view>
#include <codecvt>
// #include <climits>
#include <cassert>

#pragma region IO
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#pragma endregion

#pragma region Containers
#pragma region Adaptive
#include <queue>
#include <stack>
#pragma endregion

#pragma region Ordered
#pragma endregion

#pragma region Sequence
#include <vector>
#pragma endregion

#pragma region Unordered
#include <unordered_map>
#include <unordered_set>
#pragma endregion
#pragma endregion

#pragma region Math
#include <math.h>
#pragma endregion

#pragma region Time
#include <time.h>
#pragma endregion
#pragma endregion

#pragma region Rftim3
#pragma region MACROS
#pragma region UI
#define RFT_TITLE(title) (std::cout << "\n----------  " << title << "  ----------\n");
#define RFT_SEPARATOR (std::cout << "------------------------------\n\n");
#pragma endregion

#pragma region Functions
#define COMPARE(x, y) ((x) < (y) ? (y) : (x))
#define FAHR_TO_CELSIUS(x) 5 * (x - 32) / 9
#define CELSIUS_TO_FAHR(x) x * 9 / 5 + 32
#pragma endregion
#pragma endregion
#pragma endregion

// Speed IO
static void speedup()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

// Time measurements
static clock_t startTime;
static double getCurrentTime()
{
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
