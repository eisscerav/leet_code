/*
There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.



Example 1:

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true]
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
 */
#include <iostream>
#include <vector>

class Solution {
private:
    std::vector<bool> result;
    std::vector<int> my_candies;
    int extraCandies;
    int max;
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
//        std::vector<bool> ret;
        this->extraCandies = extraCandies;
        my_candies = candies;
        max = my_candies[0];
        for (std::vector<int>::iterator it = my_candies.begin() ; it != my_candies.end(); ++it) {
            if(max < *it) max = *it;
        }
        for (std::vector<int>::iterator it = my_candies.begin() ; it != my_candies.end(); ++it) {
            int greatest_candies = *it + extraCandies;
            if(greatest_candies >= max) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }

    void printResult() {
        std::cout << "max" << " : " << max << std::endl;
        std::cout << "extraCandies" << " : " << extraCandies << std::endl;
        for (int i = 0 ; i < result.size(); ++i) {
            std::cout << my_candies[i] << " : " << result[i] << std::endl;
        }
    }
}; //Solution

void test1()
{
    Solution my_solution;
    int myints[] = {2,3,5,1,3};
    std::vector<int> candies(myints, myints + sizeof(myints) / sizeof(int)); // @suppress("Invalid arguments")
    int extraCandies = 3;
    my_solution.kidsWithCandies(candies, extraCandies);
    my_solution.printResult();
}

int main()
{
    test1();
    return 0;
}

