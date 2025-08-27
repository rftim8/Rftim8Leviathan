#pragma once
#include "rft_global_cpp.hh"

// #pragma region Unicode

static std::size_t findUnicodeCharacter(const std::string &input, const std::wstring &target)
{
    // Convert input string to wstring
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring winput = converter.from_bytes(input);

    // Find the position of the target Unicode character
    size_t pos = winput.find(target);

    return pos;
}

static std::string replaceUnicodeCharacter(const std::string &input, const std::wstring &target, const std::wstring &replacement)
{
    // Convert input string to wstring
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring winput = converter.from_bytes(input);

    // Replace target with replacement
    size_t pos = 0;
    while ((pos = winput.find(target, pos)) != std::wstring::npos)
    {
        winput.replace(pos, target.length(), replacement);
        pos += replacement.length();
    }

    // Convert wstring back to string
    return converter.to_bytes(winput);
}

static std::string replaceUnicodeCharacterWithString(const std::string &input, const std::wstring &target, const std::string &replacement)
{
    // Convert input string to wstring
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring winput = converter.from_bytes(input);

    // Convert replacement string to wstring
    std::wstring wreplacement = converter.from_bytes(replacement);

    // Replace target with replacement
    size_t pos = 0;
    while ((pos = winput.find(target, pos)) != std::wstring::npos)
    {
        winput.replace(pos, target.length(), wreplacement);
        pos += wreplacement.length();
    }

    // Convert wstring back to string
    return converter.to_bytes(winput);
}

// #pragma endregion

static std::string replaceCharWithString(const std::string &input, char target, const std::string &replacement)
{
    std::string result = input;
    size_t pos = 0;

    // Find and replace all occurrences of the target character
    while ((pos = result.find(target, pos)) != std::string::npos)
    {
        result.replace(pos, 1, replacement);
        pos += replacement.length();
    }

    return result;
}

static std::string replaceStringWithString(const std::string &input, const std::string &target, const std::string &replacement)
{
    std::string result = input;
    size_t pos = 0;

    // Find and replace all occurrences of the target string
    while ((pos = result.find(target, pos)) != std::string::npos)
    {
        result.replace(pos, target.length(), replacement);
        pos += replacement.length();
    }

    return result;
}

static std::vector<std::wstring> getAllNonAlphaNumeric(std::string &input)
{
    std::vector<std::wstring> res = {};

    for (char c : input)
    {
        if (!std::isalnum(static_cast<unsigned char>(c)))
            std::cout << c;
    }

    return res;
}

static void print1DVectorInt(std::ofstream &out, std::vector<int> v)
{
    for (auto &&i : v)
    {
        out << i << " ";
    }
    out << "\n";
}

static std::vector<int> get1DVectorInt(std::string s)
{
    std::vector<int> res = {};

    if (s.size() > 0)
    {
        s.erase(remove(s.begin(), s.end(), '['), s.end());
        s.erase(remove(s.begin(), s.end(), ']'), s.end());

        std::stringstream ss(s);
        std::string t = "";

        while (getline(ss, t, ','))
        {
            res.push_back(stoi(t));
        }
    }

    return res;
}

static std::vector<std::optional<int>> get1DVectorOptInt(std::string s)
{
    std::vector<std::optional<int>> res = {};

    if (s.size() > 0)
    {
        s.erase(remove(s.begin(), s.end(), '['), s.end());
        s.erase(remove(s.begin(), s.end(), ']'), s.end());

        std::stringstream ss(s);
        std::string t = "";

        while (getline(ss, t, ','))
        {
            if (t != "")
            {
                if (t == "null")
                    res.push_back(std::nullopt);
                else
                    res.push_back(stoi(t));
            }
        }
    }

    return res;
}

static std::vector<std::string> get1DVectorString(std::string s)
{
    std::vector<std::string> res = {};

    if (s.size() > 0)
    {
        s.erase(remove(s.begin(), s.end(), '\"'), s.end());
        s.erase(remove(s.begin(), s.end(), '['), s.end());
        s.erase(remove(s.begin(), s.end(), ']'), s.end());

        std::stringstream ss(s);
        std::string t = "";

        while (getline(ss, t, ','))
        {
            res.push_back(t);
        }
    }

    return res;
}

static std::vector<std::vector<int>> get2DVectorInt(std::string s)
{
    std::vector<std::vector<int>> res = {};
    int l = 0, r = 0;
    std::string a = "";
    std::vector<std::string> vv = {};

    for (auto &&j : s)
    {
        if (j == '[')
            l++;
        else if (j == ']')
        {
            r++;
            if (l > r)
            {
                vv.push_back(a);
                a = "";
            }
        }
        else
            a += j;
    }

    for (auto &&j : vv)
    {
        std::vector<int> a = {};
        std::string t;
        std::stringstream ss(j);

        while (getline(ss, t, ','))
        {
            if (t != "")
            {
                a.push_back(stoi(t));
            }
        }

        res.push_back(a);
    }

    return res;
}

static std::vector<std::vector<std::optional<int>>> get2DVectorOptInt(std::string s)
{
    std::vector<std::vector<std::optional<int>>> res = {};
    int l = 0, r = 0;
    std::string a = "";
    std::vector<std::string> vv = {};

    for (auto &&j : s)
    {
        if (j == '[')
            l++;
        else if (j == ']')
        {
            r++;
            if (l > r)
            {
                vv.push_back(a);
                a = "";
            }
        }
        else
            a += j;
    }

    for (auto &&j : vv)
    {
        std::vector<std::optional<int>> a = {};
        std::string t;
        std::stringstream ss(j);

        while (getline(ss, t, ','))
        {
            if (t != "")
            {
                if (t == "null")
                    a.push_back(std::nullopt);
                else
                    a.push_back(stoi(t));
            }
        }

        res.push_back(a);
    }

    return res;
}

static std::vector<std::vector<std::string>> get2DVectorString(std::string s)
{
    std::vector<std::vector<std::string>> res = {};

    if (s.size() > 0)
    {
        s.erase(remove(s.begin(), s.end(), '\"'), s.end());

        int l = 0, r = 0;
        std::string a = "";
        std::vector<std::string> vv = {};

        for (auto &&j : s)
        {
            if (j == '[')
                l++;
            else if (j == ']')
            {
                r++;
                if (l > r)
                {
                    vv.push_back(a);
                    a = "";
                }
            }
            else
                a += j;
        }

        for (auto &&j : vv)
        {
            std::vector<std::string> a = {};
            std::string t;
            std::stringstream ss(j);

            while (getline(ss, t, ','))
            {
                if (t != "")
                    a.push_back(t);
            }

            res.push_back(a);
        }
    }

    return res;
}

// std::sort(lc_problem_names_original.begin(), lc_problem_names_original.end(),
//           [](const std::string &a, const std::string &b)
//           {
//               auto a_end = a.find(';');
//               auto b_end = b.find(';');
//               int a_sub = (a_end != std::string::npos) ? std::stoi(a.substr(0, a_end)) : std::stoi(a);
//               int b_sub = (b_end != std::string::npos) ? std::stoi(b.substr(0, b_end)) : std::stoi(b);
//               return a_sub < b_sub;
//           });
