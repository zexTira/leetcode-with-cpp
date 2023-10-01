/*//
//  In this question we use a brutal way to solve it.
//  The matrix is consisted of 4 sides so in each loop we need to consider going through on 4 directions.
//  For each direction, we push it into result vector in spiral sequence, and after the process ends on 1 direction, we need to update the beginning point for next direction.
//  When beginning point in one direction reaches the end of this direction, the loop ends, and we just need to return the result.
//*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowBeg = 0, colBeg;
        int rowEnd = matrix.size() - 1;
        int colEnd = matrix[0].size() - 1;
        vector<int>ans;

        while (true)
        {
            for (int j = colBeg; j <= colEnd; j++)
            {
                ans.push_back(matrix[rowBeg][j]);
            }
            if (++rowBeg > rowEnd)
            {
                break;
            }

            for (int i = rowBeg; i <= rowEnd; i++)
            {
                ans.push_back(matrix[i][colEnd]);
            }
            if (--colEnd < colBeg)
            {
                break;
            }

            for (int j = colEnd; j >= colBeg; j--)
            {
                ans.push_back(matrix[rowEnd][j]);
            }
            if (--rowEnd < rowBeg)
            {
                break;
            }

            for (int i = rowEnd; i >= rowBeg; i--)
            {
                ans.push_back(matrix[i][colBeg]);
            }
            if (++colBeg > colEnd) {
                break;
            }
        }
        return ans;
    }
};