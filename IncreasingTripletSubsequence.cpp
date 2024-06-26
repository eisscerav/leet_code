/*
 * IncreasingTripletSubsequence.cpp
 *
 *  Created on: Jun 17, 2024
 *      Author: ffan
 *
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.
Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        bool ret = false;
        size_t len = nums.size();
        int start = 0;
        std::vector<int> tmp;
        for(; start + 2 < len; start++) {
            tmp = std::vector<int>(nums.begin()+start, nums.begin()+start+3);
            if(tmp[0] < tmp[1] && tmp[1] < tmp[2]) {
                ret = true;
                int i = 0;
                for(std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
                    std::cout << "tmp[" << i++ << "] = " << *it << std::endl;
                }
                return ret;
            }
        }
        std::cout << "no matching triplet increasing" << std::endl;
        return ret;
    }
}; // Solution

void test1()
{
    std::cout << "test1..." << std::endl;
    int nums[] = {2,1,5,0,4,6};
    std::vector<int> v(nums, nums+sizeof(nums)/sizeof(int));
    Solution my_solution;
    my_solution.increasingTriplet(v);

    std::cout << "test2..." << std::endl;
    int nums1[] = {5,4,3,2,1};
    v = std::vector<int>(nums1, nums1+sizeof(nums1)/sizeof(int));
    my_solution.increasingTriplet(v);

    std::cout << "test3..." << std::endl;
    int nums2[] = {1,2,3,4,5};
    v = std::vector<int>(nums2, nums2+sizeof(nums2)/sizeof(int));
    my_solution.increasingTriplet(v);
}


int main()
{
    test1();
    return 0;
}
