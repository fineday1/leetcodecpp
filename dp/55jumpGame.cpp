/**
 * Description:
 *   You are given an integer array nums. You are initially positioned at the array's first index,
 *   and each element in the array represents your maximum jump length at that position.
 *   Return true if you can reach the last index, or false otherwise.
 *
 * Examples:
 *   1) Input: nums = [2,3,1,1,4]
 *      Output: true
 *
 *   2) Input: nums = [3,2,1,0,4]
 *      Output: false
 *
 * Thought Process:
 *   Let dp[i] represent whether we can reach index i from the beginning of the nums array.
 *   We construct dp[i] in the following way:
 *
 *      dp[i] = true if i == 0, or dp[i] = true if we can reach i from index j,
 *      where 0<=j<=i and j + nums[j] >= i and dp[j] == true, else dp[i] = false
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
        bool canJump(vector<int>& nums)
        {
            int nums_size = static_cast<int>(nums.size());
            vector<int> dp(nums_size);
            
            if (nums[0] == 0 && nums_size != 1)
                return false;

            dp[0] = 1;

            for (int i = 1; i < nums_size; ++i)
            {
                for (int j = 0; j < i; ++j)
                {
                    if (j + nums[j] >= i && dp[j] == 1){
                        dp[i] = 1;
                        break;
                    }
                }

            }

            return dp[nums_size - 1] == 1 ? true : false;
        }

        bool greedyCanJump(vector<int> &nums)
        {
            int maxReach = 0;

            for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            {
                cout << "maxReach=" << maxReach << ", " << i << "+nums[" << i << "]=" << i+nums[i] << endl;
                if (maxReach < i)
                    return false;

                int currReach = i + nums[i];
                if (maxReach >= static_cast<int>(nums.size()))
                    return true;
                else if (currReach > maxReach)
                    maxReach = currReach;
            }

            return true;
        }
};

int main()
{
    Solution s = Solution();

    vector<int> nums1 = { 2, 3, 1, 1, 4 };
    assert( s.greedyCanJump(nums1) == true );

    vector<int> nums2 = { 3, 2, 1, 0, 4 };
    assert( s.greedyCanJump(nums2) == false );

    vector<int> nums3 = { 1, 0, 1, 0 };
    assert( s.greedyCanJump(nums3) == false );

    return 0;
}