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
 *   How can we make a decision based on the previous one? What if we store the minimum buy price and maximum sell
 *   price, and if we encounter a better price we update it? This guarantees finding the minimum and maximum, but not
 *   them being in the order of min_idx < max_idx. We need to also track the indices at which the extremes are.
 */
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

class Solution
{
    public:
        /**
         * Naive solution
         */
        int maxProfit(vector<int>& prices)
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
};

int main()
{
    Solution s = Solution();

    vector<int> p1 = { 7, 1, 5, 3, 6, 4 };
    assert( s.maxProfit(p1) == 5 );
}