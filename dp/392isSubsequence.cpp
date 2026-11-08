/**
 * Description:
 *   Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
 *   
 *   A subsequence of a string is a new string that is formed from the original string by 
 *   deleting some (can be none) of the characters without disturbing the relative 
 *   positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
 * 
 * Examples:
 *   1) Input: s = "abc", t = "ahbgdc"
 *      Output: True
 *   2) Input: s = "axc", t = "ahbgdc"
 *      Output: False
 * 
 * Constraints:
 *   1) 0 <= s.length <= 100
 *   2) 0 <= t.length <= 10^4
 *   3) s and t consist only of lowercase English letters
 * 
 * Thought process:
 *   We can iterate over t, when we find the letter s[i], we move to the next letter (s[i+1]).
 *   This solution is at most O(t).
 */

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution
{
    public:
        bool isSubsequence(string s, string t)
        {
            size_t s_idx = 0;

            for (size_t i = 0; i < t.size() && s_idx < s.size(); ++i)
            {
                if (t[i] == s[s_idx]) 
                    ++s_idx;
            }

            if (s_idx == s.size()) return true;
            
            return false;
        }
};

int main()
{
    Solution s = Solution();

    assert( s.isSubsequence(string("abc"), string("ahbgdc")) == true );
    assert( s.isSubsequence(string("axc"), string("ahbgdc")) == false );

    return 0;
}