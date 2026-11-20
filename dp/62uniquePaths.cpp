/**
 * Description:
 *   There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
 *   The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
 *   The robot can only move either down or right at any point in time.
 *   Given the two integers m and n, return the number of possible unique paths that the robot
 *   can take to reach the bottom-right corner.
 *   The test cases are generated so that the answer will be less than or equal to 2 * 109.
 *
 * Examples:
 *   1) Input: m = 3, n = 7
 *      Output: 28
 *
 *   2) Input: m = 3, n = 2
 *      Output: 3
 *
 * Thought Process:
 *   We can use dynamic programming to store the number of possible unique paths to each coordinate.
 *   Out dp table will be 2D, where dp[i][j] is the number of unique paths to coordinate x=j, y=i.
 *   We construct dp[i][j] in the following way:
 *
 *          dp[i][j] = 1 if i == 0 && j == 0 or dp[i][j] = dp[i][j-1] + dp[i-1][j]
 *
 *   There is one issue that remains, we can accidentally index out of bounds, we can solve this,
 *   by padding the left side and top with zeros. We return dp[m-1][n-1].
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
        int uniquePaths(int m, int n)
        {
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
            dp[1][1] = 1;

            for (int i = 1; i < m + 1; ++i)
            {
                for (int j = 1; j < n + 1; ++j)
                {
                    if (i == 1 && j == 1)
                        continue;

                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }

            return dp[m][n];
        }
};

int main()
{
    Solution s = Solution();

    assert( s.uniquePaths(3, 7) == 28 );

    assert( s.uniquePaths(3, 2) == 3 );

    return 0;
}