
#include <cstring>
#include <unordered_map>
#include <iostream>
#include <ch1.h>

// Uses an unordered map to determine if the given string
// is unique or not.  O(n) time
bool Ch1::is_unique(const std::string &s)
{
    std::unordered_map<char, bool> char_map;

    for(long unsigned int i = 0; i < s.length(); ++i)
    {
        if(char_map.count(s[i]) > 0)
        {
            return false;
        }
        char_map[s[i]] = true;
    }

    return true;
}

// Doesn't use any extra memory for determining if the given
// string contains unique letters or not.  O(n^2) time.
bool Ch1::is_unique_in_place(const std::string &s)
{
    for(long unsigned int i = 0; i < s.length() - 1; ++i)
    {
        for(long unsigned int j = i+1; j < s.length(); ++j)
        {
            if(s[i] == s[j])
            {
                return false;
            }
        }
    }

    return true;
}

//will use an unordered map to determine if string is permutation
//O(n) time
bool Ch1::is_permutation(const std::string &s1, const std::string &s2)
{
    std::unordered_map<char, int> char_map;

    for(long unsigned int i = 0; i < s1.length(); ++i)
    {
        if(char_map.count(s1[i]) == 0)
        {
            char_map[s1[i]] = 1;
        }
        else
        {
            char_map[s1[i]] += 1;
        }
    }

    for(long unsigned int j = 0; j < s2.length(); ++j)
    {
        //if char doesn't exist in map then we know it doesn't exist
        //in s1 so it's not a permuation
        if(char_map.count(s2[j] == 0))
        {
            return false;
        }
        else
        {
            char_map[s2[j]] -= 1;
        }
    }

    //verify all counts of letters is 0, this means there is an exact match of letters and their
    //counts in s1 and s2
    for(std::unordered_map<char, int>::iterator iter = char_map.begin(); iter != char_map.end(); ++iter)
    {
        if(iter->second != 0)
        {
            return false;
        }
    }

    return true;
}

void Ch1::urlify(char s[], int buf_len)
{
    int num_spaces = 0;
    int cnt = 0;
    while(s[cnt] != 0)
    {
        if(s[cnt] == ' ')
        {
            ++num_spaces;
        }
        ++cnt;
    }

    if(num_spaces * 2 + cnt + 1 > buf_len)
        return;

    for(int i = cnt; i >= 0; --i)
    {
        if(s[i] == ' ')
        {
            --num_spaces;
            memcpy((s + i) + num_spaces * 2, "%20", 3);
        }
        else
        {
            s[i + num_spaces * 2] = s[i];
        }
    }
}
