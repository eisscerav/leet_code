/*
 * reverseWords.cpp
 *
 *  Created on: Jun 13, 2024
 *      Author: ffan
 */
//151. Reverse Words in a String
/*
 Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 */
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>


bool bothSpaces(char lhs, char rhs) {
    return lhs == ' ' && rhs == ' ';
}

class Solution {
public:
    std::vector<std::string> split(const std::string& str, char delim) {
        std::vector<std::string> tokens;
        std::stringstream ss(str);
        std::string token;

        while (std::getline(ss, token, delim)) {
            tokens.push_back(token);
        }

        return tokens;
    }

    void print_vector(std::vector<std::string> v) {
        for(std::vector<std::string>::iterator it = v.begin() ; it != v.end(); ++it) {
            std::cout << *it << std::endl;
        }
    }

    void stringToVector(std::string s) {
        std::vector<std::string> v;
        std::string tmp_s;
        size_t len_s = s.size();
        for(int i = 0; i < len_s; ++i) {
            if (s[i] == ' ') {
                v.push_back(tmp_s);
                std::cout << tmp_s << std::endl;
                tmp_s.erase();
                std::cout << "after erase: " << tmp_s << std::endl;
            }
            else {
                tmp_s.push_back(s[i]);
                if(i == len_s - 1) {
                    v.push_back(tmp_s); // push_back last one
                }
            }
        }
        std::cout << "============stringToVector============" << std::endl;
        for(std::vector<std::string>::iterator it = v.begin() ; it != v.end(); ++it) {
            std::cout << *it << std::endl;
        }
    }

    std::string reverseWords(std::string s) {
        std::cout << "testing string: " << s << std::endl;
//        s.erase(std::unique(s.begin(), s.end(), bothSpaces), s.end());
        std::cout << "removing duplicate space: " << s << std::endl;

        size_t found = s.find_first_not_of(" ");
        size_t found_end = s.find_last_not_of(" ");
        std::cout << found << std::endl;
        std::cout << s[found] << std::endl;

        std::cout << found_end << std::endl;
        std::cout << s[found_end] << std::endl;
        std::string ret(s.begin()+found, s.begin()+found_end+1);
        std::cout << "size of ret: " << ret.size() << std::endl;
        ret.erase(std::unique(ret.begin(), ret.end(), bothSpaces), ret.end());
        std::cout << ret << std::endl;
//        this->stringToVector(ret);
        std::vector<std::string> tokens = split(ret, ' ');
        for(std::vector<std::string>::iterator it = tokens.begin() ; it != tokens.end(); ++it) {
            std::cout << "====tokens====" << std::endl;
            std::cout << *it << std::endl;
        }

        return s;
    }
}; //solution

void test1(std::string &s)
{
    Solution my_solution;
    my_solution.reverseWords(s);
}

int main(int argc, char **argv)
{
    std::string s = "   hello   world  ";
    if(argc == 2) s = argv[1];
    test1(s);
    return 0;
}


