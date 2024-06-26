//https://leetcode.com/problems/greatest-common-divisor-of-strings/?envType=study-plan-v2&envId=leetcode-75
#include <string>
#include <iostream>

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        int len_1 = str1.size();
        int len_2 = str2.size();
//        std::string short_str = (len_1 > len_2) ?  str2 : str1;
        std::string sub1 = this->findGCD(str1);
        std::string sub2 = this->findGCD(str2);
        std::cout << "sub1: " << sub1 << std::endl;
        std::cout << "sub2: " << sub2 << std::endl;
        return str1;
    }

    std::string findGCD(std::string str) {
        size_t len = str.size();
        size_t quotient, residue;
        bool isGCD = true;
        for(size_t i = 2; i < len; i++) {  // i: numPerElement
            quotient = len / i;  // quotient: numbers of element
            residue = len % i;
            if(quotient > 1 && residue == 0) {
                std::string substr1 = std::string(str, 0, i);
                for(size_t j = 1; j < quotient; j++) {
                    std::string substr2 = std::string(str, j*i, i);
                    if(substr1 != substr2) {
                        isGCD = false;
                        break;
                    }
                }
                if(isGCD) return substr1;
                else {
                    isGCD = true;
                }
            }
            if(quotient < 2) return str;
        }
        return str;
    }
};

void test1()
{
    std::cout << "test1..." << std::endl;
    Solution my_solution;
    my_solution.gcdOfStrings("ABABC", "ABABCABABC");

}

void test2()
{
    std::cout << "test2..." << std::endl;
    Solution my_solution;
    my_solution.gcdOfStrings("ABABABABABAB", "ABAB");

}

void test3()
{
    std::cout << "test3..." << std::endl;
    Solution my_solution;
    my_solution.gcdOfStrings("ABCABC", "ABC");

}

void test4()
{
    std::cout << "test4..." << std::endl;
    Solution my_solution;
    my_solution.gcdOfStrings("abcdefghijk", "abcdefghijkabcdefghijkabcdefghijkabcdefghijk");

}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}

