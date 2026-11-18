/**
 * Description:
 *   You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.
 *   Each element nums[i] represents the maximum length of a forward jump from index i.
 *   In other words, if you are at index i, you can jump to any index (i + j) where:
 *      0 <= j <= nums[i] and
 *      i + j < n
 *   Return the minimum number of jumps to reach index n - 1.
 *   The test cases are generated such that you can reach index n - 1.
 *
 * Examples:
 *   1) Input: nums = [2,3,1,1,4]
 *      Output: 2
 *
 *   2) Input: nums = [2,3,0,1,4]
 *      Output: 2
 *
 * Thought Process:
 *   We can use a DP table dp, that will store the minimum number of jumps we need to take to reach index.
 *   That is dp[i] is the minimum number of jumps we need to take to reach index i. Let len be the length
 *   of a jump we are able to take from index i-1. Then:
 *  
 *      dp[i] = 0 if i == 0 or dp[i] = 1 + min(all previous indices that reach index i)
 *
 *
 *
 *
 *
 *
 *
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
        int jump(vector<int>& nums)
        {
            int nums_size = static_cast<int>(nums.size());
            vector<int> dp(nums_size);
            dp[0] = 0;

            for (int i = 1; i < nums_size; ++i)
            {
                dp[i] = numeric_limits<int>::max();
                for (int j = 0; j < i; ++j)
                {
                    // If we can reach i from j + nums[j] and
                    // dp[j] + 1 < min, then we set dp[i] = dp[j] + 1
                    if (j + nums[j] >= i)
                    {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }

            return dp[nums_size-1];
        }
};

int main()
{
    Solution s = Solution();

    vector<int> nums1 = { 2, 3, 1, 1, 4 };
    assert( s.jump(nums1) == 2 );

    vector<int> nums2 = { 2, 3, 0, 1, 4 };
    assert( s.jump(nums2) == 2);

    vector<int> nums3 = { 1, 2, 3 };
    assert( s.jump(nums3) == 2 );

    return 0;
}