/*
 * MergeStrings.cpp
 *
 *  Created on: Jun 6, 2024
 *      Author: ffan
 */
#include <string>
#include <iostream>


class Solution {
private:
    std::string result;
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        int len_1 = word1.size();
        int len_2 = word2.size();
        int loop = len_1;
        if (len_1 < len_2) loop = len_2;
        for(int i = 0; i < loop; i++) {
//            std::cout << "word" << "[" << i << "]" << " = " << word1[i] << std::endl;
            if (len_1 > i) result.push_back(word1[i]);
            if (len_2 > i) result.push_back(word2[i]);
        }
        return (result);
    }

    void show_result() {
        std::cout << "result: " << result << std::endl;
    }
};


void test1()
{
    std::cout << "test1..." <<std::endl;
    std::string s1("ijk");
    std::string s2("abcdxyz");
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    Solution my_sol;
    my_sol.mergeAlternately(s1, s2);
    my_sol.show_result();
}

void test2()
{
    std::cout << "test2..." <<std::endl;
    std::string s1("abc");
    std::string s2("efg");
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    Solution my_sol;
    my_sol.mergeAlternately(s1, s2);
    my_sol.show_result();
}

void test3()
{
    std::cout << "test3..." <<std::endl;
    std::string s1("abcxyz");
    std::string s2("efg");
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    Solution my_sol;
    my_sol.mergeAlternately(s1, s2);
    my_sol.show_result();
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}



