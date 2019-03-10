
#ifndef CH1_H
#define CH1_H

#include <string>

class Ch1
{
    public:
        bool is_unique(const std::string &s);
        bool is_unique_in_place(const std::string &s);
        bool is_permutation(const std::string &s1, const std::string &s2);
        void urlify(char s[], int buf_len);
        bool is_palindrome_permutation(const std::string &s);
        bool is_one_away(std::string s1, std::string s2);
        void string_compression(char* s);
        void rotate_matrix(int** matrix, int length);
    private:
};

#endif
