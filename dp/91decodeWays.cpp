/**
 * Description:
 *   You have intercepted a secret message encoded as a string of numbers.
 *   The message is decoded via the following mapping:
 *      "1" -> 'A'
 *      "2" -> 'B'
 *      ...
 *      "25" -> 'Y'
 *      "26" -> 'Z'
 *
 *   However, while decoding the message, you realize that there are many different ways you
 *   can decode the message because some codes are contained in other codes ("2" and "5" vs "25").
 *
 *   For example, "11106" can be decoded into:
 *      "AAJF" with the grouping (1, 1, 10, 6)
 *      "KJF" with the grouping (11, 10, 6)
 *      The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
 *
 *   Note: there may be strings that are impossible to decode.
 *   Given a string s containing only digits, return the number of ways to decode it.
 *   If the entire string cannot be decoded in any valid way, return 0.
 *
 *   The test cases are generated so that the answer fits in a 32-bit integer.
 *
 * Examples:
 *   1) Input: s = "12"
 *      Output: 2
 *
 *   2) Input: s = "226"
 *      Output: 3
 *
 *   3) Input: s = "06"
 *      Output: 0
 *
 * Thought Process:
 *   Let dp[i] represent the number of ways to decode the first i indices of the input string.
 *   Every valid grouping is either 1 or 2 integers, so when we're processing the i-th integere,
 *   the grouping can only be the integer and the (i+1)st or only the integer. For dynamic programming,
 *   it's better to define it as either the grouping of (i-1)st integer and the integer or only the integer.
 *
 *                  s = "121":      empty
 *                                 /     \
 *                                1      12
 *                              /   \      \
 *                             2    21      1 
 *                            /
 *                           1
 *
 *
 *
 */

#include <cassert>
#include <iostream>
#include <memory>
#include <limits>
#include <optional>
#include <algorithm>
#include <bitset>
#include <list>
#include <array>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <random>
#include <functional>

using namespace std;

class Solution
{
    public:
        int numDecodings(string s)
        {
            int s_size = static_cast<int>(s.size());
            vector<int> dp(s_size + 1);
            dp[0] = 1;      // empty string
            dp[1] = (s[0] == '0') ? 0 : 1;

            for (int i = 2; i <= s_size; ++i)
            {
                // Process grouping of single integer i
                if (s[i-1] != '0')
                    dp[i] += dp[i-1];
                
                // Process grouping of integers i and i-1
                int number = (s[i-2] - '0') * 10 + (s[i-1] - '0');
                if (number >= 10 && number <= 26)
                    dp[i] += dp[i-2];
            }

            return dp[s_size];
        }
};

int main()
{
    Solution s = Solution();

    assert( s.numDecodings(string("12")) == 2 );

    assert( s.numDecodings(string("226")) == 3 );

    assert( s.numDecodings(string("06")) == 0 );

    return 0;
}