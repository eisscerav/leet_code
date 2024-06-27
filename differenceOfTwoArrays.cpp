/*
 * differenceOfTwoArrays.cpp
 *
 *  Created on: Jun 27, 2024
 *      Author: ffan
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

Example 1:
Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


void print_vector(std::string s, std::vector<int> v)
{
    std::cout << s << ": " ;
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void print_vector(std::string s, std::vector<std::vector<int> > v)
{
    std::cout << s << ": " << std::endl;
    for(std::vector<std::vector<int> >::iterator it_v = v.begin(); it_v != v.end(); it_v++) {
        for(std::vector<int>::iterator it = (*it_v).begin(); it != (*it_v).end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

class Solution {
public:
    std::vector<std::vector<int> > findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> v1;
        std::vector<int> v2;
        std::vector<int> intersect;
        std::vector<std::vector<int> > ret;

        for(std::vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++) {
            if(std::find(nums2.begin(), nums2.end(), *it) != nums2.end()) {
                /* nums2 contains it */
                intersect.push_back(*it);
            } else {
                /* nums2 does not contain it */
            }
        }
        std::cout << "intersection: " ;
        for(std::vector<int>::iterator it = intersect.begin(); it != intersect.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        for(std::vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++) {
            if(std::find(intersect.begin(), intersect.end(), *it) != intersect.end()) {
                /* nums2 contains it */
            } else {
                /* nums2 does not contain it */
                v1.push_back(*it);
            }
        }
        ret.push_back(v1);
        std::cout << std::endl;

        for(std::vector<int>::iterator it = nums2.begin(); it != nums2.end(); it++) {
            static int i = 0;
            if(std::find(intersect.begin(), intersect.end(), *it) != intersect.end()) {
                /* nums2 contains it */
            } else {
                /* nums2 does not contain it */
                v2.push_back(*it);
            }
            std::cout << i++;
        }
        ret.push_back(v2);
        std::cout << std::endl;

        print_vector("v1", v1);
        print_vector("v2", v2);
        print_vector("ret", ret);

        return ret;
    }
}; //solution

void test1()
{
    Solution my_solution;
    int a1[] = {2,3,5,1,4};
    int a2[] = {2,6,8,1,4};

    std::vector<int> v1(a1, a1 + sizeof(a1) / sizeof(int)); // @suppress("Invalid arguments")
    std::vector<int> v2(a2, a2 + sizeof(a2) / sizeof(int)); // @suppress("Invalid arguments")
    std::cout << "v1: " ;
    for(std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "v2: " ;
    for(std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    my_solution.findDifference(v1, v2);
}

int main()
{
    test1();
    return 0;
}

