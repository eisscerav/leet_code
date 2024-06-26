//https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75
/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.



Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
    std::string vowels;
//    std::string s;
public:
    bool isVowel(char c) {
        std::string vowels = "aeiou";
        if(vowels.find(c) != std::string::npos) {
            return true;
        }
        return false;
    }

//    void getVowels(std::string s) {
//        int len = s.size();
//        for(int i = 0; i < len; i++) {
//            if(isVowel(s[i])) vowels.push_back(s[i]);
//        }
//        std::reverse(vowels.begin(), vowels.end());
//        std::cout << vowels << std::endl;
//    }

    std::string reverseVowels(std::string s) {
        std::cout << s << std::endl;
        int len = s.size();
        for(int i = 0; i < len; i++) {
            if(isVowel(s[i])) vowels.push_back(s[i]);
        }
        std::reverse(vowels.begin(), vowels.end());
        std::cout << vowels << std::endl;
        int j = 0;
        for(int i = 0; i < len; i++) {
            if(isVowel(s[i])) s[i] = vowels[j++];
        }
        std::cout << s << std::endl;
        return vowels;
    }
}; //Solution

void test1(std::string &s)
{
    Solution my_solution;
    my_solution.reverseVowels(s);
}

int main(int argc, char **argv)
{
    std::string s = "leetcode";
    if(argc == 2) s = argv[1];
    test1(s);
    return 0;
}
