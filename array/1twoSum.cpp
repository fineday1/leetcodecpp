#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class Solution 
{
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            int nums_cnt = nums.size();
            int sum = nums[0];

            for (int i = 0; i < nums_cnt; ++i)
            {
                for (int j = 0; j < nums_cnt; ++j)
                {
                    if (i == j) sum = nums[i];
                    else sum = nums[i] + nums[j];
                    if (sum == target && i != j) return { i, j };
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