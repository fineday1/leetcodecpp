/**
 * Description:
 *   You are given an array prices where prices[i] is the price of a given stock on the i-th day.
 *   You want to maximize your profit by choosing a single day to buy one stock and
 *   choosing a different day in the future to sell that stock.
 *   Return the maximum profit you can achieve from this transaction.
 *   If you cannot achieve any profit, return 0.
 * 
 * Example:
 *   1) Input: prices = [7, 1, 5, 3, 6, 4]
 *      Output: 5
 *      
 *   2) Input: prices = [7, 6, 4, 3, 1]
 *      Output: 0
 * 
 * Thought process:
 *   Naive solution would mean using two nested loops to check every combination of two prices. This will be O(n^2).
 * 
 *                  [7, 1, 5, 3, 6, 4]
 *                   |  |  |  |  |  |
 *                   0  1  2  3  4  5
 * 
 *                  [1, 3, 4, 5, 6, 7]
 *                   |  |  |  |  |  |
 *                   1  3  5  2  4  0
 */

#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

class Solution
{
    public:
        /**
         * Naive solution
         */
        int maxProfitNaive(vector<int>& prices)
        {
            int max_profit = 0;

            for (size_t i = 0; i < prices.size(); ++i)
            {
                for (size_t j = i; j < prices.size(); ++j)
                {
                    int curr_profit = 0;
                    if (prices[i] < prices[j]) curr_profit = prices[j] - prices[i];
                    if (curr_profit > max_profit) max_profit = curr_profit;
                }
            }
            
            return max_profit;
        }

        /**
         * Optimized solution using Dynamic Programming
         */
        int maxProfit(vector<int>& prices)
        {
            int min_buy = numeric_limits<int>::max();
            int max_profit = 0;

            for (size_t i = 0; i < prices.size(); ++i)
            {
                if (prices[i] - min_buy > max_profit) max_profit = prices[i] - min_buy;
                if (prices[i] < min_buy) min_buy = prices[i];
            }

            // cout << "max_profit=" << max_profit << endl;
            return max_profit;
        }
};

int main()
{
    Solution s = Solution();

    vector<int> p1 = { 7, 1, 5, 3, 6, 4 };
    assert( s.maxProfit(p1) == 5 );
}