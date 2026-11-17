/**
 * Description:
 *   Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
 *   In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 * 
 *                      1
 *                   1     1
 *                 1    2    1
 *               1   3     3   1
 *             1   4    6    4   1
 * 
 * Example:
 *   1) Input: numRows = 3
 *      Output: [1,3,3,1]
 *
 *   2) Input: numRows = 0
 *      Output: [1]
 *
 *   3) Input: numRows = 1
 *      Output: [1,1]
 * 
 * Thought process:
 *   Store the most recent and the previous row of the Pascal triangle. Alternate to which one we write.
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution
{
   public:
       vector<int> getRow(int rowIndex)
       {
            vector<int> row1(rowIndex + 1);
            vector<int> row2(rowIndex + 1);
            row1[0] = 1;
            row2[0] = 1;

            if (rowIndex == 0)
                return row1;

            row1[1] = 1;
            row2[1] = 1;

            // true if row1 is the lower row, false if row2 is the lower row
            bool res = true;

            for (int i = 2; i < rowIndex + 1; ++i)
            {
                if (res)
                {
                    row1[0] = 1;
                    row1[i] = 1;
                }
                else
                {
                    row2[0] = 1;
                    row2[i] = 1;
                }

                for (int j = 1; j <= i; ++j)
                {
                    if (res)
                    {
                        row1[j] = row2[j-1] + row2[j];
                    } 
                    else
                    {
                        row2[j] = row1[j-1] + row1[j];
                    }
                }

                res = res ? false : true;
            }

            return res ? row2 : row1;
       }
};

int main()
{
   Solution s = Solution();

   assert ( s.getRow(3) == vector<int>( { 1, 3, 3, 1 } ) );
   assert ( s.getRow(0) == vector<int>( { 1 } ) );
   assert ( s.getRow(1) == vector<int>( { 1, 1 } ) );

   return 0;
}