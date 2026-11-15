/**
 * Description:
 *   For a string sequence, a string word is k-repeating if word concatenated k times is a substring of sequence.
 *   The word's maximum k-repeating value is the highest value k where word is k-repeating in sequence.
 *   If word is not a substring of sequence, word's maximum k-repeating value is 0.
 *   Given strings sequence and word, return the maximum k-repeating value of word in sequence.
 * 
 * Examples:
 *   1) Input: sequence = "ababc", word = "ab"
 *      Output: 2
 * 
 *   2) Input: sequence = "ababc", word = "ba
 *      Output: 1
 * 
 * Thought process:
 *   Iterate over sequence, if you find matching letter, move to the next letter in word and continue iteration,
 *   if you don't, reset to word[0]. If you match all letters in word increment the counter and reset
 *   position to word[0]. This does not cover cases such as the third assert though. What if we instead store
 *   number of matching letters at each index of the sequence string.
 *
 *   Let's instead use a dp table, where dp[i] is the maximum number of consecutive copies of word ending at i.
 *   When constructing dp[i] we check if a complete copy of word ends at index i. If it does,
 *   we set dp[i] = dp[i-m] + 1, where m is the length of word, if it does not, we set dp[i] = 0.
 */

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution
{
    public:
        int maxRepeating(string sequence, string word)
        {
            vector<int> dp(sequence.size(), 0);
            int m = word.size();
            int max = 0;

            for (int i = m - 1; i < static_cast<int>(sequence.size()); ++i)
            {
                if (sequence.substr(i - m + 1, m) == word) {
                    dp[i] = 1;

                    if (i >= m)
                        dp[i] = dp[i - m] + 1;

                    if (dp[i] > max)
                        max = dp[i];
                } else {
                    dp[i] = 0;
                }
            }

            return max;
        }
};

int main()
{
    Solution s = Solution();

    string seq1 = "ababc";
    string word1 = "ab";
    assert( s.maxRepeating(seq1, word1) == 2 );

    string seq2 = "ababc";
    string word2 = "ba";
    assert( s.maxRepeating(seq2, word2) == 1 );

    string seq3 = "aaabaaaabaaabaaaabaaaabaaaabaaaaba";
    string word3 = "aaaba";
    assert( s.maxRepeating(seq3, word3) == 5 );

    return 0;
}