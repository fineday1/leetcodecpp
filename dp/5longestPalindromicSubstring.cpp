/**
 * Description:
 *   Given a string s, return the longest palindromic substring in s.
 *  
 *   Note:
 *   A string is palindromic if it reads the same forward and backward.
 *
 * Examples:
 *   1) Input: s = "babad"
 *      Output: "bab" or "aba"
 *
 *   2) Input: s = "cbbd"
 *      Output: "bb"
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution
{
    public:
        string longestPalindrome(string s)
        {
            int s_size = static_cast<int>(s.size());
            vector<vector<int>> dp(s_size, vector<int>(s_size));

            int max_start = 0;
            int max_len = 0;

            for (int i = 0; i < s_size; ++i)
            {
                int len = i + 1;
                for (int j = 0; j < s_size - i; ++j)
                {
                    int start = j;
                    int end = j + len - 1;

                    if (len == 1)
                    {
                        dp[j][j] = 1;
                        if (len > max_len)
                        {
                            max_start = j;
                            max_len = len;
                        }
                        continue;
                    }
            
                    if (len == 2)
                    {
                        if (s[j] == s[j+1])
                        {
                            dp[j][j+1] = 1;
                            if (len > max_len)
                            {
                                max_start = j;
                                max_len = len;
                            }
                        }
                        continue;
                    }

                    if (s[start] == s[end] && dp[start+1][end-1] == 1)
                        dp[start][end] = 1;
                    
                    if (dp[start][end] == 1 && len > max_len)
                    {
                        max_start = start;
                        max_len = len;
                    }
                }
            }

            return s.substr(max_start, max_len);
        }
};

int main()
{
    Solution s = Solution();

    assert( s.longestPalindrome(string("babad")) == string("bab") );
    assert( s.longestPalindrome(string("cbbd")) == string("bb") );

    return 0;
}