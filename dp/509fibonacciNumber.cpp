/**
 * Description:
 *   The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
 *     F(0) = 0, F(1) = 1
 *     F(n) = F(n - 1) + F(n - 2), for n > 1.
 *   Given n, calculate F(n).
 * 
 * Examples:
 *   1) Input: n = 2
 *      Output: 1
 * 
 *   2) Input: n = 3
 *      Output: 2
 * 
 * Constraints:
 *   1) 0 <= n <= 30
 * 
 * Thought process:
 *   Naive implementation can use a simple recursion, where base case is n equals zero, in which we return zero
 *   and n equals one, in which case we return one. Else we return fib(n - 1) + fib(n - 2). This isn't very efficient
 *   since for fib(n) there are n^2 fib calls. We make a significant amount of  redundant calculations/calls,
 *   which can be solved by memorizing calculations we made prior. This leads to the bottom-up DP with memoization.
 * 
 *   This solution can be further improved by using an iterative solution that will be more memory efficient
 *   since it eliminates recursion and reduces the stack frame.
 */

#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class Solution
{
    public:
        /**
         * Naive recursive solution
         */
        // int solveNaive(int n)
        // {
        //     if (n == 0) return 0;
        //     if (n == 1) return 1;

        //     return solve(n - 2) + solve(n - 1);
        // }

        // int fibNaive(int n)
        // {
        //     if (n < 2) return n;
        //     return solve(n);
        // }

        /**
         * Bottom-up DP with memoization
         */
        int solve(int n, vector<int> &dp)
        {
            if (n == 0) return 0;
            if (n == 1) return 1;

            if (dp[n - 1] != 0) return dp[n - 1];

            dp[n - 1] = solve(n - 2, dp) + solve(n - 1, dp);
            return dp[n - 1];
        }

        int fib(int n)
        {
            if (n < 2) return n;

            vector<int> dp(n);

            return solve(n, dp);
        }

        /**
         * Iterative solution
         */
        int fibIter(int n)
        {   
            if (n < 2) return n;

            vector<int> dp(n + 1);
            dp[0] = 0;
            dp[1] = 1;

            for (int i = 2; i <= n; ++i)
            {
                dp[i] = dp[i - 2] + dp [i - 1];
            }

            return dp[n];
        }
};

int main()
{
    Solution s = Solution();

    assert( s.fibIter(2) == 1 );
    assert( s.fibIter(3) == 2 );
    assert( s.fibIter(7) == 13 );

    return 0;
}