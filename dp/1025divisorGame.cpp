/**
 * Description:
 *   Alice and Bob take turns playing a game, with Alice starting first. Initially, 
 *   there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:
 *   Choosing any integer x with 0 < x < n and n % x == 0.
 *   Replacing the number n on the chalkboard with n - x.
 *   Also, if a player cannot make a move, they lose the game.
 *   Return true if and only if Alice wins the game, assuming both players play optimally.
 * 
 * Examples:
 *   1) Input: n = 2
 *      Output: True
 *   2) Input: n = 3
 *      Output: False
 * 
 * Constraints:
 *   1) 1 <= n <= 1000
 * 
 * Thought process:
 *   For naive solution, we try every x for every n - x, that satisfies n % x == 0. So for n = 6:
 * 
 *                                              6
 *                                           /  |  \
 *                                          5   4   3
 *                                        /    / \    \
 *                                       4    3   2    2
 *                                      / \   |   |    |
 *                                     3   2  2   1    1
 *                                    /    |  |
 *                                   2     1  1
 *                                   |
 *                                   1
 * 
 *   Where each vertex represents the chalkboard state.
 * 
 *   For n = 4, initially Alice can choose either 2 or 1, choosing 2 means Bob chooses 1 and wins, choosing 1 means
 *   Bob has to choose 1, which leaves 2 on the board, Alice then chooses 1 and wins. We know that for i = 1, Alice
 *   wins, for i = 2 we know that Bob wins, for i = 3 we have a single option of choosing x = 1, in which case
 *   i becomes 2, so Bob wins, for i = 4 we can either choose x = 1, or x = 2, we choose i - x such that Alice wins.
 *
 *   In general we construct dp[i] by
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution
{
    public:
        /**
         * Naive recursive solution
         * 
         * @return Returns true if Alice found a move that guarantees her victory,
         *         returns false if not.
         */
        bool solve(int curr, bool isAliceTurn)
        {
            // Base case, if the remainder is one, there are no more moves,
            // if it's Alice's turn she loses, if not Bob loses
            if (curr == 1 && isAliceTurn)
                return false;
            else if (curr == 1 && !isAliceTurn)
                return true;

            // Iterate over all possible x values that satisfy the condition
            for (int i = 1; i < curr; ++i)
            {
                if (curr % i == 0)
                {
                    bool res = solve(curr - i, !isAliceTurn);

                    if (res && isAliceTurn)
                        return true;                // Alice found a way to guarantee a victory
                    else if (!res && isAliceTurn)
                        continue;                   // Alice did not find a way to win, keep exploring
                    else if (res && !isAliceTurn)
                        continue;                   // Bob did not find a way to win, keep exploring
                    else if (!res && !isAliceTurn)
                        return false;               // Bob found a way to guarantee a victory
                }
            }

            // All possible ways exhausted, return true if it's Bob's turn, else return true (Alice wins)
            return !isAliceTurn;
        }

        bool divisorGame(int n)
        {
            return solve(n, true);
        }
};

int main()
{
    Solution s = Solution();

    assert( s.divisorGame(2) == true );
    assert( s.divisorGame(3) == false );
    assert( s.divisorGame(4) == true );
    assert( s.divisorGame(5) == false );

    return 0;
}