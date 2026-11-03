/**
 * Description:
 *   You are climbing a staircase. It takes n steps to reach the top.
 *   Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
 * Examples:
 *   1) Input: n = 2
 *      Output: 2
 *      Explanation: There are two ways to climb to the top. 
 *                      1. 1 step + 1 step
 *                      2. 2 steps
 *  2) Input: n = 3
 *     Output: 3
 *     Explanation: There are three ways to climb to the top.
 *                     1. 1 step + 1 step + 1 step
 *                     2. 1 step + 2 steps
 *                     3. 2 steps + 1 step
 * 
 * Though process:
 *   Each possible way of climbing to the top is a sequence of either taking one step or taking two steps.
 *   This can be represented using a binary tree:
 * 
 *                          0
 *                        /   \
 *                       /     \
 *                      1       2
 *                    /  \     /  \
 *                   2    3   3    4
 *                  / \  / \ / \  / \
 *                 3  4 4  5 4  5 5  6
 *    
 *   Let's say n = 3, it's apparent that the branch terminates when the value exceeds n.
 *   If the value in the current node equals n, we increase the total count and return since
 *   that branch cannot have any more valid ways. If we step into a node with value greater
 *   than n, we return without increasing the total count. This is the naive recursive solution.
 * 
 *   
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution
{
    public:
        /**
         * Naive recursive solution
         */
        // void solve(int n, int curr, int &cnt)
        // {
        //     if (curr == n)
        //     {
        //         cnt++;
        //         return;
        //     }

        //     if (curr > n) return;

        //     solve(n, curr + 1, cnt);
        //     solve(n, curr + 2, cnt);
        // }

        // int climbStairs(int n)
        // {
        //     int cnt = 0;
        //     solve(n, 0, cnt);

        //     return cnt;
        // }

        /**
         * Dynamic programming solution
         */
        int solve(int n, int curr, vector<int> &dp)
        {
            if (curr > n) return 0;

            if (curr == n)
            {
                return 1;
            }

            if (dp[curr] != 0) return dp[curr];

            dp[curr] = solve(n, curr + 1, dp) + solve(n, curr + 2, dp);

            return dp[curr];
        }

        int climbStairs(int n)
        {
            vector<int> dp(n, 0); 
            int cnt = solve(n, 0, dp);

            return cnt;
        }
};

int main()
{
    Solution s = Solution();

    assert(s.climbStairs(1) == 1);
    assert(s.climbStairs(2) == 2);
    assert(s.climbStairs(3) == 3);
    assert(s.climbStairs(4) == 5);
    assert(s.climbStairs(5) == 8);
}