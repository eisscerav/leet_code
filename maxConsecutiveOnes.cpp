/*
 * maxConsecutiveOnes.cpp
 *
 *  Created on: Jun 25, 2024
 *      Author: ffan
 */

// C++ code for the above approach
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Function to find maximum length of
// consecutive ones
int find_Max_Consecutive_Ones(int arr[], int n, int k)
{

    int start = 0, end = 0, zeros = 0, ones = 0;
    int ans = 0;
    while (end < n) {
        if (arr[end] == 1)
            ones++;
        else
            zeros++;

        // Compressing window in case
        // required
        while (zeros > k) {
            if (arr[start] == 1)
                ones--;
            else
                zeros--;
            start++;
        }

        // Taking maximum of all possible
        // answers
        ans = max(ans, ones);

        // Expanding window
        end++;
    }
    return ans;
}

// Driver code
int main()
{
//    nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
    int arr[] = { 1, 0, 1, 1, 0, 1, 0 };
    int K = 2;
    int N = sizeof(arr) / sizeof(int);

    // Function call
    cout << find_Max_Consecutive_Ones(arr, N, K);

    return 0;
}


