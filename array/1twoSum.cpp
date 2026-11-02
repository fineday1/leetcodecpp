#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution 
{
    public:
        // vector<int> twoSum(vector<int>& nums, int target) 
        // {
        //     int nums_cnt = nums.size();
        //     int sum = nums[0];

        //     for (int i = 0; i < nums_cnt; ++i)
        //     {
        //         for (int j = 0; j < nums_cnt; ++j)
        //         {
        //             if (i == j) sum = nums[i];
        //             else sum = nums[i] + nums[j];
        //             if (sum == target && i != j) return { i, j };
        //         }
        //     }

        //     return {  };
        // }

        /**
         * Faster implementation takes O(n*log(n)) instead of O(n^2).
         * We iterate over nums and look for the remaining value using lower bound,
         * when we find the two numbers matching target, we iterate nums to find
         * the index of the second number (this does not raise time complexity).
         */
        vector<int> twoSum(vector<int>& nums, int target)
        {
            int nums_cnt = nums.size();
            
            vector<int> nums_sorted = nums;
            sort(nums_sorted.begin(), nums_sorted.end());

            int remainder = target - nums[0];

            for (int i = 0; i < nums_cnt; ++i)
            {
                remainder = target - nums[i];
                auto it = lower_bound(nums_sorted.begin(), nums_sorted.end(), remainder);
                if (it == nums_sorted.end()) continue;
                else {
                    for (int j = 0; j < nums_cnt; ++j)
                    {
                        if (nums[j] == remainder && i != j) return { i, j };
                    }
                }
            }

            return {  };
        }
};

int main()
{
    Solution s = Solution();

    vector<int> nums1 = { 3, 2, 4 };
    assert ( s.twoSum( nums1, 6 ) == vector<int>( { 1, 2 } ) );

    vector<int> nums2 = { 2, 7, 11, 15 };
    assert ( s.twoSum( nums2, 9 ) == vector<int>( { 0, 1 } ) );

    vector<int> nums3 = { 3, 3 };
    assert ( s.twoSum( nums3, 6 ) == vector<int>( { 0, 1 } ) );

    vector<int> nums4 = { 3, 2, 3 };
    assert ( s.twoSum( nums4, 6 ) == vector<int>( { 0, 2 } ) );

    vector<int> nums5 = { 0, 4, 3, 0 };
    assert ( s.twoSum( nums5, 0 ) == vector<int>( { 0, 3 } ) );
}