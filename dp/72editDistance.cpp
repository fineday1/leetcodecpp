/**
 * Description:
 *   Given two strings word1 and word2, return the minimum number of operations
 *   required to convert word1 to word2. You have the following three operations permitted on a word:
 *   
 *      1) Insert a character
 *      2) Delete a character
 *      3) Replace a character
 *
 * Examples:
 *   1) Input: word1 = "horse", word2 = "ros"
 *      Output: 3
 *      Explanation: 
 *        horse -> rorse (replace 'h' with 'r')
 *        rorse -> rose (remove 'r')
 *        rose -> ros (remove 'e')
 *
 *   2) Input: word1 = "intention", word2 = "execution"
 *      Output: 5
 *      Explanation: 
 *        intention -> inention (remove 't')
 *        inention -> enention (replace 'i' with 'e')
 *        enention -> exention (replace 'n' with 'x')
 *        exention -> exection (replace 'n' with 'c')
 *        exection -> execution (insert 'u')
 *
 * Thought Process:
 *   The problem asks for minimum, so we when using DP, we are most likely going to store
 *   some mimimum for each letter or something like that.
 *
 *   What if we use dp[i] to store the minimum number of operations to convert the first i letters
 *   from word1 to match the first i letter of word2? We would construct dp[i] like:
 *
 *          dp[i] = dp[i-1] if word1[i] == word2[i], or dp[i] = dp[i-1] + 1 if word1[i] != word2[i]
 *
 *   We would also define the base case, i.e. dp[0] to be either 0 or 1 when word1[0] == word2[0] or
 *   does not respectively. One additional rule would be to prioritise removing the i-th element if
 *   the word1[i+1] == word2[i+1], which decreases the total number of operations. Lastly if word1 is
 *   shorter, then we insert the rest of the letters, if word1 is longer, we delete the rest of the letters.
 *   This however breaks for case like:
 *
 *          word1 = "aaabbb", word2 = "bbb", we perform twice replace -> "bbabbb", then one deletion ->
 *          -> "bbbbb", then two more deletions, resulting in 5 operations, while the minimum is 3 deletions
 *
 *   This hints at the "scope" of our dp[i] being too small. The proposed solution is also just O(n),
 *   which seems quite low for the given problem. What if we use 2D table dp[i][j], which represents
 *   minimum number of operations to convert the first i letters of word1 to the first j letters of word2.
 *   Then dp[i][j] is constructed as:
 *
 *          dp[i][j] = i if j == 0
 *                     j if i == 0
 *                     dp[i-1][j-1] if word1[i] == word2[j]
 *                     1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) if word1[i] != word2[j]
 *                                  ^           ^           ^
 *                                  |           |           |
 *           deletion removes last character    |           |
 *                                          insertion       |
 *                                                      replacement
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
        int minDistance(string word1, string word2)
        {
            int m = static_cast<int>(word1.size());
            int n = static_cast<int>(word2.size());
            vector<vector<int>> dp(m + 1, vector<int>(n + 1));

            // base case
            for (int i = 0; i < m + 1; ++i)
                // empty word2 requires i deletions
                dp[i][0] = i;
            for (int j = 0; j < n + 1; ++j)
                // empty word1 requires j insertions
                dp[0][j] = j;
            
            for (int i = 1; i < m + 1; ++i)
            {
                for (int j = 1; j < n + 1; ++j)
                {
                    // matching characters don't require an operation 
                    if (word1[i-1] == word2[j-1])
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    // choose the most optimal out of deletion, insertion and replacement
                    else
                    {
                        dp[i][j] = 1 + min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] });
                    }
                }
            }

            return dp[m][n];
        }
};

int main()
{
    Solution s = Solution();

    assert( s.minDistance(string("horse"), string("ros")) == 3 );
    
    assert( s.minDistance(string("intention"), string("execution")) == 5 );
    
    assert( s.minDistance(string(""), string("")) == 0 );

    return 0;
}