/**
 * Description:
 *   Given an integer array nums, find the subarray with the largest sum, and return its sum.
 *
 * Examples:
 *   1) Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 *      Output: 6
 *
 *   2) Input: nums = [1]
 *      Output: 1
 *
 *   2) Input: nums = [5,4,-1,7,8]
 *      Output: 23
 *
 * Thought Process:
 *   Let dp[i] be the largest sum of the subarray starting at j, ending at i, where 0<=j<=i.     
 *   We construct dp[i] as dp[i] = nums[0] if i == 0, or dp[i] = max(dp[i-1] + nums[i], nums[i]).
 *   We have to consider all dp states to find the subarray with the largest sum.
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
        int maxSubArray(vector<int>& nums)
        {
            int nums_size = nums.size();
            vector<int> dp(nums_size);
            dp[0] = nums[0];
            int largest = nums[0];

            for (int i = 1; i < nums_size; ++i)
            {
                dp[i] = max(dp[i-1] + nums[i], nums[i]);
                if (dp[i] > largest)
                    largest = dp[i];
            }

            return largest;
        }
};

int main()
{
    Solution s = Solution();

    vector<int> nums1 = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    assert( s.maxSubArray(nums1) == 6 );

    vector<int> nums2 = { 1 };
    assert( s.maxSubArray(nums2) == 1 );

    vector<int> nums3 = { 5, 4, -1, 7, 8 };
    assert( s.maxSubArray(nums3) == 23 );

    return 0;
}