/**
 * Description:
 *   Given an integer numRows, return the first numRows of Pascal's triangle.
 *   In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 * 
 *                      1
 *                   1     1
 *                 1    2    1
 *               1   3     3   1
 *             1   4    6    4   1
 * 
 * Example:
 *   1) Input: numRows = 5
 *      Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 *   2) Input: numRows = 1
 *      Output: [[1]]
 * 
 * Thought process:
 *   Rows one and two are sort of unique, so starting from row three each row is constructed as appending one
 *   to the start and to the end, and summing each neighboring pair from the previous row. Is it possible to
 *   optimize this solution since the rows are always symmetrical whether even or odd?
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution
{
   public:
       void printRow(const vector<int> &row)
       {
           cout << "[";
           for (size_t i = 0; i < row.size(); ++i)
           {
               if (i == row.size() - 1) cout << row[i];
               else cout << row[i] << ", ";
           }
           cout << "]\n";
       }
       
       void printRows(int numRows, const vector<vector<int>> &rows)
       {
           for (size_t i = 0; i < size_t(numRows); ++i)
           {
               printRow(rows[i]);
               cout << endl;
           }
           cout << endl;
       }

       /**
        * Iterative solution
        */
       vector<vector<int>> generate(int numRows)
       {
           vector<vector<int>> rows(numRows);
           for (int i = 0; i < numRows; ++i)
           {
               rows[i] = vector<int>(i + 1);
           }
           rows[0] = { 1 }; 
           if (numRows < 2) return rows;
           rows[1] = { 1, 1 };
           for (int i = 2; i < numRows; ++i)
           {
               rows[i][0] = 1;
               rows[i][i] = 1;
               
               for (int j = 0; j < i; ++j)
               {
                   int left = rows[i - 1][j];
                   int right = rows[i - 1][j + 1];
                   rows[i][j + 1] = left + right;
               }
           }
           return rows;
       }
};

int main()
{
   Solution s = Solution();
   assert ( s.generate(5) == vector<vector<int>>( { { 1 },
                                                    { 1, 1 }, 
                                                    { 1, 2, 1 },
                                                    { 1, 3, 3, 1 },
                                                    { 1, 4, 6, 4, 1 } } ) );
}