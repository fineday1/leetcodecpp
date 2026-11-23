/**
 * Description:
 *   Given a rod of length n, and a table of prices pi for i = 1, 2, ..., n.
 *   Determine the maximum revenue rn obtainable by cutting up the rod and
 *   selling the pieces.
 *
 * Examples:
 *   1) Input: n = 4, p = [1,5,8,9]
 *      Output: 10
 *      Explanation: two cuts into lengths 2 + 2
 *
 *   2) Input: n = 10, p = [1,5,8,9,10,17,17,20,24,30]
 *      Output: 30
 *      Explanation: no cuts
 *
 * Thought Process:
 *   Using bottom-up dynamic programming, storing an optimal solution to n = i in dp[i].
 *   Then dp[i] is constructed as dp[i] = 0 if i == 0, else dp[i] = max(dp[i], p[j] + r[i-j]), 
 *   where j = 1, ..., i.
 *
 * Extension 1:
 *   Find the maximum revenue rn, but you are also given a constant c that represents the cost
 *   of performing a cut of a rod.
 *
 * Extension 2:
 *   Return not only the maximum revenue rn, but also the lengths of the split rods.
 *
 * Source:
 *   Introduction to Algorithms by Cormen, Leiserson, Rivest, Stein
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

int rodCutting(int n, const vector<int> &prices)
{
    vector<int> dp(n + 1, numeric_limits<int>::min());
    dp[0] = 0;

    // Iterate over all possible lengths
    for (int i = 1; i <= n; ++i)
    {
        // Iterate over all ways to split rod of length i into rods of lengths i-j and j
        for (int j = 1; j <= i; ++j)
        {
            // Save optimal solution for length i as the existing optimal solution
            // for the remainder of the rod (length i-j) and the other half of the rod
            // of length j
            dp[i] = max(dp[i], prices[j-1] + dp[i-j]);
        }
    }

    return dp[n];
}

int rodCuttingExtended1(int n, const vector<int> &prices, int cost)
{
    vector<int> dp(n + 1, numeric_limits<int>::min());
    dp[0] = 0;

    // Iterate over all possible lengths
    for (int i = 1; i <= n; ++i)
    {
        // Iterate over all ways to split rod of length i into rods of lengths i-j and j
        for (int j = 1; j <= i; ++j)
        {
            // Save optimal solution for length i as the existing optimal solution
            // for the remainder of the rod (length i-j) and the other half of the rod
            // of length j
            dp[i] = max(dp[i], prices[j-1] + dp[i-j] - cost);
            if (i == j)
                dp[i] = max(dp[i], prices[j-1] + dp[i-j]);
        }
    }

    return dp[n];
}

pair<int, vector<int>> rodCuttingExtended2(int n, const vector<int> &prices)
{
    vector<int> dp(n + 1, numeric_limits<int>::min());
    vector<int> res(n + 1);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (dp[i] < prices[j-1] + dp[i-j])
            {
                dp[i] = prices[j-1] + dp[i-j];
                res[i] = j;     // Saves what the remainder of cutting rod of length i was
            }
        }
    }

    // Reconstruct cut lengths
    vector<int> cuts;
    int remainder = n;
    while (remainder > 0)
    {
        int firstPiece = res[remainder];
        cuts.push_back(firstPiece);
        remainder -= firstPiece;
    }

    return make_pair(dp[n], cuts);
}

int main()
{
    vector<int> prices1 = { 1, 5, 8, 9 };
    assert( rodCutting(4, prices1) == 10 );

    vector<int> prices2 = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
    assert( rodCutting(10, prices2) == 30 );

    // Extension 1
    assert( rodCuttingExtended1(4, prices1, 1) == 9 );
    vector<int> prices3 = { 1, 5, 8, 9, 10, 17, 17 };
    assert( rodCuttingExtended1(7, prices3, 2) == 17 );

    // Extension 2
    assert( rodCuttingExtended2(4, prices1) == make_pair( 10, vector<int>{ 2, 2 } ) );
    assert( rodCuttingExtended2(10, prices2) == make_pair( 30, vector<int>{ 10 } ) );

    return 0;
}