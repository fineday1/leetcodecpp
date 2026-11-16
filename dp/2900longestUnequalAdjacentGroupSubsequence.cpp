/**
 * Description:
 *   You are given a string array words and a binary array groups both of length n.
 *   A subsequence of words is alternating if for any two consecutive strings in the sequence,
 *   their corresponding elements at the same indices in groups are different
 *   (that is, there cannot be consecutive 0 or 1). 
 *   Your task is to select the longest alternating subsequence from words. 
 *   Return the selected subsequence. If there are multiple answers, return any of them.
 *   Note: The elements in words are distinct.
 *
 * Examples:
 *   1) Input: words = ["e", "a", "b"], groups = [0,0,1]
 *      Output: ["e", "b"]
 *
 *   2) Input: words = ["a", "b", "c", "d"], groups = [1,0,1,1]
 *      Output: ["a", "b", "c"]
 *
 *
 * Thought process:
 *   What if we simply iterate over groups and check the previous groups value, if it differs we add the current
 *   word to the result array.
 *
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution
{
    public:
        vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups)
        {
            int words_cnt = static_cast<int>(words.size());
            vector<string> res;
            res.push_back(words[0]);

            if (words_cnt == 1)
                return res;

            for (int i = 1; i < words_cnt; ++i)
            {
                if (groups[i] != groups[i-1])
                    res.push_back(words[i]);
            }

            return res;
        }
    };

int main()
{
    Solution s = Solution();

    vector<string> w1 = { "e", "a", "b" };
    vector<int> g1 = { 0, 0, 1 };
    assert(( s.getLongestSubsequence(w1, g1) == vector<string>{ "e", "b" } ));

    vector<string> w2 = { "a", "b", "c", "d" };
    vector<int> g2 = { 1, 0, 1, 1 };
    assert(( s.getLongestSubsequence(w2, g2) == vector<string>{ "a", "b", "c" } ));

    return 0;
}