/*
 * moveZeros.cpp
 *
 *  Created on: Jun 17, 2024
 *      Author: ffan
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int i = 0;
        int total_zero = 0;
        std::vector<int> position;
        for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            std::cout << "nums[" << i++ << "] = " << *it << ", ";
        }
        std::cout << std::endl;
        int len = nums.size();
        int tmp;
        for(int i = 0; i < len; i++) {
            tmp = nums[0];
            nums.erase(nums.begin());
            if(tmp !=  0) {
                nums.push_back(tmp);
            }
            else {
                total_zero++;
            }
        }
        for(int i = 0; i < total_zero; i++) {
            nums.push_back(0);
        }
        i = 0;
        for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            std::cout << "nums[" << i++ << "] = " << *it << ", ";
        }
        std::cout << std::endl;
    }
}; //solution

void test1()
{
    std::cout << "test1..." << std::endl;
    int nums[] = {2,1,5,0,0,6};
    std::vector<int> v(nums, nums+sizeof(nums)/sizeof(int));
    Solution my_solution;
    my_solution.moveZeroes(v);

    std::cout << "test2..." << std::endl;
    int nums1[] = {5,0,3,2,4};
    v = std::vector<int>(nums1, nums1+sizeof(nums1)/sizeof(int));
    my_solution.moveZeroes(v);

    std::cout << "test3..." << std::endl;
    int nums2[] = {0};
    v = std::vector<int>(nums2, nums2+sizeof(nums2)/sizeof(int));
    my_solution.moveZeroes(v);

    std::cout << "test4..." << std::endl;
    int nums3[] = {12, 0, 5, 3, 0, 0, 0, 19, 1};
    v = std::vector<int>(nums3, nums3+sizeof(nums3)/sizeof(int));
    my_solution.moveZeroes(v);
}

int main()
{
    test1();
    return 0;
}
