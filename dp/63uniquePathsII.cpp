/**
 * Description:
 *   You are given an m x n integer array grid.
 *   There is a robot initially located at the top-left corner (i.e., grid[0][0]).
 *   The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
 *   The robot can only move either down or right at any point in time.
 *   An obstacle and space are marked as 1 or 0 respectively in grid.
 *   A path that the robot takes cannot include any square that is an obstacle.
 *   Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
 *   The testcases are generated so that the answer will be less than or equal to 2 * 109.
 *
 * Examples:
 *   1) Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 *      Output: 2
 *
 *   2) Input: obstacleGrid = [[0,1],[0,0]]
 *      Output: 1
 *
 * Thought Process:
 *   Same idea as for the problem 63. Unique Paths, we use DP to store the number of unique paths to
 *   coordinates x = j, y = 1 in a table dp[i][j] and construct dp[i][j] using the same recurrence.
 *   Only difference is that we first check if grid[i][j] is an obstacle, if it is, we set dp[i][j] = 0.
 *   We again use the padding trick to avoid out-of-bounds access.
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
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
        {
            int m = static_cast<int>(obstacleGrid.size());
            int n = static_cast<int>(obstacleGrid[0].size());
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
            dp[1][1] = 1;

            for (int i = 1; i < m + 1; ++i)
            {
                for (int j = 1; j < n + 1; ++j)
                {
                    if (obstacleGrid[i-1][j-1] == 1)
                    {
                        dp[i][j] = 0;
                        continue;
                    }

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

    vector<vector<int>> obstacleGrid1 = { { 0, 0, 0 },
                                          { 0, 1, 0 },
                                          { 0, 0, 0 } };
    assert( s.uniquePathsWithObstacles(obstacleGrid1) == 2 );

    vector<vector<int>> obstacleGrid2 = { { 0, 1 },
                                          { 0, 0 } };
    assert( s.uniquePathsWithObstacles(obstacleGrid2) == 1 );

    return 0;
}