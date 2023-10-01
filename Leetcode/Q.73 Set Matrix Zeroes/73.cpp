/*//
//  In this question we need two unordered maps, representing row index and column index respectively.
//  First go throughout the matrix, when the element is a 0, consider its column and row index as a key and set the bool value in corresponding unordered map to true.
//  Then go throughout the matrix twice, if the column index or row index of one element, while as the key, has been set to true in two maps, we alter it to 0. 
//*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, bool> umapRow;
        unordered_map<int, bool> umapCol;
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        for (int i = 0; i < rowSize; ++i)
        {
            for (int j = 0; j < colSize; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    umapRow[i] = true;
                    umapCol[j] = true;
                }
            }
        }

        for (int i = 0; i < rowSize; ++i)
        {
            for (int j = 0; j < colSize; ++j)
            {
                if (umapRow[i] == true || umapCol[j] == true)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};