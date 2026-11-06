/**
 * Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n),
 * ans[i] is the number of 1's in the binary representation of i.
 * 
 * Example:
 *   1) Input: n = 2
 *      Output: [0, 1, 1]
 * 
 *   2) Input: n = 5
 *      Output: [0, 1, 1, 2, 1, 2]
 * 
 * Constraints:
 *   1) 0 <= n <= 10^5
 *   2) Naive - O(n*log(n)), Optimal - O(n)
 * 
 * Thought process:
 *   Naive implementation is straight forward, we will iterate over n, for every n we will find the binary
 *   representation (we will only keep the number of ones though). We will use bit manipulation. 
 *   This will be constant, so together this naive implementation already achieves O(n).
 *   Can this be further optimized?
 * 
 *              n = 6:
 *              
 *                      0 = 0000 0000
 *                      1 = 0000 0001
 *                      2 = 0000 0010
 *                      3 = 0000 0011
 *                      4 = 0000 0100
 *                      5 = 0000 0101
 *                      6 = 0000 0110
 * 
 *  Upon observation it's aparent that the number of ones keeps resetting to 1,
 *  when a new power of two is encountered.
 *  e.g. log2(1) = 0 -> new power of two, set ones count to 1
 *       log2(2) = 1 -> new power of two, ones count stays the same
 *       log2(3) = 1.58 -> same power of two (floored), ones count increases to 2
 *       log2(4) = 2 -> new power of two, ones count resets to 1
 *       log2(6) = 2.58 -> same power of two (floored), CANNOT simply increment count  
 * 
 */

#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
    public:
        /**
         * Naive solution (O(n*log(n)))
         */
        vector<int> countBitsNaive(int n)
        {
            vector<int> res(n + 1, 0);

            for (int i = 0; i <= n; ++i)
            {
                for (int j = 31; j >= 0; --j)
                {
                    if (i & (1 << j)) res[i]++;
                }
            }

            return res;
        }

        /**
         * Experimental solution, does not work correctly
         */
        vector<int> countBits(int n)
        {
            // Define first 17 powers of 2
            unordered_map<int, int> powers =
            {
                { 1,      0 },
                { 2,      1 },
                { 4,      2 },
                { 8,      3 },
                { 16,     4 },
                { 32,     5 },
                { 64,     6 },
                { 128,    7 },
                { 256,    8 },
                { 512,    9 },
                { 1024,  10 },
                { 2048,  11 },
                { 4096,  12 },
                { 8192,  13 },
                { 16384, 14 },
                { 32768, 15 },
                { 65536, 16 }
            };

            vector<int> res(n + 1, 0);
            int cnt = 0;

            for (int i = 1; i <= n; ++i)
            {
                if (powers.contains(i))
                {
                    cnt = 1;
                } else {
                    cnt++;
                }
                res[i] = cnt;
            }

            return res;
        }
};

int main()
{
    Solution s = Solution();

    assert ( s.countBits(2) == vector<int>( { 0, 1, 1 } ) );
    assert ( s.countBits(5) == vector<int>( { 0, 1, 1, 2, 1, 2 } ) );
    assert ( s.countBits(8) == vector<int>( { 0, 1, 1, 2, 1, 2, 2, 3, 1 } ) );
}