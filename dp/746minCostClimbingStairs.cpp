/**
 * Description: 
 *   You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
 *   Once you pay the cost, you can either climb one or two steps.
 *   You can either start from the step with index 0, or the step with index 1.
 *   Return the minimum cost to reach the top of the staircase, which is the position
 *   just past the last step (index cost.length).
 * 
 * Examples:
 *   1) Input: cost = { 10, 15, 20 }
 *      Output: 15
 *      Explanation: Start at index 1, pay 15, take 2 steps.
 * 
 *   2) Input: cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 }
 *      Output: 6
 *      Explanation: Start at index 0, pay 1, climb to index 2, pay 1,
 *                   climb to index 4. pay 1, climb to index 6, pay 1,
 *                   climb to index 7, pay 1, climb to index 9, pay 1,
 *                   take one step to reach the top.
 * 
 * Thought process:
 *   Naive solution is to try every possible route. This can be represented by a binary tree:
 * 
 *                                              0                                   0
 *                                          /       \                             /   \
 *                                        1          100                        10     15
 *                                      /   \       /   \                      / \     / \
 *                                    1    100      1     1                  15  20   20  t
 *                                  /  \   /  \   /  \   /  \               / \  / \  / \ 
 *                                 1   1  1   1   1   1  1  100           20  t t  t  t  t 
 *                                             ...                       / \
 *                                                                      t   t
 *   
 *   In order to find the cheapest path, we have to track minimal cost, current cost, current index.
 *   The base case is current index is the target (the top), then we compare the current cost vs the minimal
 *   cost and return. We do two recursion calls one with current index + 1, and second one with current index + 2.
 * 
 *   To improve this solution we will use bottom-up DP with tabulation. We will store the lowest cost from
 *   the beginning to the i-th stair.
 */

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution
{
    public:
        /**
         * Naive recursive solution
         */
        // void solveNaive(vector<int> &cost, int currIdx, int currCost, int &minCost)
        // {
        //     if (currIdx + 2 >= int(cost.size()))
        //     {
        //         if (currCost < minCost)
        //         {
        //             minCost = currCost;
        //         }
        //         return;
        //     }

        //     solve(cost, currIdx + 1, currCost + cost[currIdx + 1], minCost);
        //     solve(cost, currIdx + 2, currCost + cost[currIdx + 2], minCost);
        // }

        // int minCostClimbingStairsNaive(vector<int>& cost)
        // {
        //     int minCost = numeric_limits<int>::max();

        //     solve(cost, -1, 0, minCost);

        //     return minCost;
        // }

        /**
         * Bottom-up DP with tabulation
         */
        int solve(vector<int> &cost, int currIdx, vector<int> &dp)
        {
            if (currIdx >= int(cost.size()))
                return min(dp[cost.size() - 1], dp[cost.size() - 2]);

            dp[currIdx] = cost[currIdx] + min(dp[currIdx - 1], dp[currIdx - 2]);

            return solve(cost, currIdx + 1, dp);
        }

        int minCostClimbingStairs(vector<int>& cost)
        {
            vector<int> dp(cost.size());
            dp[0] = cost[0];
            dp[1] = cost[1];
            
            return solve(cost, 2, dp);
        }
};

int main()
{
    Solution s = Solution();

    vector<int> c1 = { 10, 15, 20 };
    assert( s.minCostClimbingStairs(c1) == 15 );

    vector<int> c2 = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
    assert( s.minCostClimbingStairs(c2) == 6 );

    vector<int> c3 = { 0, 0, 0, 1 };
    assert( s.minCostClimbingStairs(c3) == 0 );

    return 0;
}