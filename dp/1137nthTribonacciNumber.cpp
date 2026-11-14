/**
 * Description:
 *   The Tribonacci sequence Tn is defined as follows: 
 *   T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 *   Given n, return the value of Tn.
 * 
 * Examples:
 *   1) Input: n = 4
 *      Output: 4
 * 
 *   2) Input = 25
 *      Output: 1389537
 * 
 * Thought process:
 *   Base case has to be n == 0/1/2. We are given the recurrence right away, so there should be no problem
 *   implementing an iterative bottom-up DP with tabulation immedietly.
 */

#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class Solution
{
    public:
        int tribonacci(int n)
        {
            if (n == 0)
                return 0;
            else if (n == 1)
                return 1;
            else if (n == 2)
                return 1;

            vector<int> dp(n + 1, 0);
            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 1;

            for (int i = 3; i <= n; ++i)
            {
                dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            }

            return dp[n];
        }
};

int main()
{
    Solution s = Solution();

    assert( s.tribonacci(4) == 4 );
    assert( s.tribonacci(25) == 1389537);

    return 0;
}