/**
 * Description:
 *   You are given two integers n and k.
 *   A positive integer x is called compatible if it satisfies both of the following conditions:
 *      abs(n - x) <= k
 *      (n & x) == 0
 *   Return the sum of all compatible integers x.
 *   Note:
 *   Here, & denotes the bitwise AND operator.
 *   The absolute difference between integers i and j is defined as abs(i - j).
 *
 * Examples:
 *   1) Input: n = 2, k = 3
 *      Output: 10
 *
 *   2) Input: n = 5, k = 1
 *      Output: 0
 *
 *
 * Thought process:
 *   It's true that if n > k, then n-k <= x <= n+k. If n <= k, then 0 <= x <= n+k. Thus we can determine the range
 *   of x's over which we need to iterate, for every possible x we perform a bitwise and, add it to the total sum
 *   if it returns true.
 *
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution
{
    public:
        int sumOfGoodIntegers(int n, int k)
        {
            int sum = 0;
            int lower_bound, upper_bound;

            if (n > k)
            {
                lower_bound = n - k;
                upper_bound = n + k;
            } else {
                lower_bound = 0;
                upper_bound = n + k;
            }

            for (int i = lower_bound; i <= upper_bound; ++i)
            {
                if ((n & i) == 0)
                    sum += i;
            }

            return sum;
        }
};

int main()
{
    Solution s = Solution();

    assert( s.sumOfGoodIntegers(2, 3) == 10 );
    assert( s.sumOfGoodIntegers(5, 1) == 0 );

    return 0;
}