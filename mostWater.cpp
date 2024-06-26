/*
 * mostWater.cpp
 *
 *  Created on: Jun 24, 2024
 *      Author: ffan
 You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>


class Solution {
public:
    int maxArea(std::vector<int>& water) {
        int i = 0;
        for(std::vector<int>::iterator it = water.begin(); it != water.end(); it++) {
            std::cout << "water" << it-water.begin() << ": " << *it << "\t";
        }
        std::cout << std::endl;

        std::vector<int> result;
        int width = 1;
        int height;
        int lenth = water.size();
        int area = 0;
        for(; width < lenth; width++) {
            for(int i = 0; i + width < lenth; i++) {
                height = std::min(water[i], water[width+i]);
                area = height * width;
                result.push_back(area);
            }
        }
        int num_area = 0;
        for(std::vector<int>::iterator it = result.begin(); it != result.end(); it++) {
            std::cout << "area" <<num_area++ <<  ": " << *it << "\t";
            if(*it > area) area = *it;
            if(num_area % 8 == 0) std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "max area: " << area << std::endl;
        return area;
    }
}; //solution

void test1()
{
    std::srand(std::time(nullptr));
    Solution my_solution;
    int water[] = {1,8,6,2,5,4,8,3,7};
    std::vector<int> v(water, water+sizeof(water)/sizeof(int));
    std::vector<int> v1;
    for(int i = 0; i < rand()% (10-5) + 5; i++) {
        v1.push_back(rand()% (10-1) + 1);
    }
    my_solution.maxArea(v1);
}

int main()
{
    test1();
    return 0;
}

