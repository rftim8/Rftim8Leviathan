#pragma once
#include "rft_global_cpp.hh"

struct Trie
{
    Trie *ch[26] = {};
    bool end = false;

    void insertTrie(const std::string &s, int p)
    {
        if (p < s.length())
        {
            int idx = s[p] - 'a';
            if (ch[idx] == nullptr)
                ch[idx] = new Trie();
            if (ch[idx]->end)
                return;

            ch[idx]->insertTrie(s, p + 1);
        }
        else
            end = true;
    }

    bool findTrie(const std::string &s, int p, std::string &ret)
    {
        if (p == s.length())
        {
            ret = s;
            return end;
        }

        int idx = s[p] - 'a';

        if (ch[idx] != nullptr)
        {
            if (ch[idx]->end)
            {
                ret = s.substr(0, p + 1);
                return true;
            }
            else
                return ch[idx]->findTrie(s, p + 1, ret);
        }
        else
        {
            ret = s;

            return false;
        }
    }
};
