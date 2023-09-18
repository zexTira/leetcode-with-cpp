/*//
//  For a square matrix, if we want to rotate the image by 90 degrees (clockwise), we can implement following algorithm
//  Firstly, swap the numbers on the both sides of axis which is from upperleft corner to bottomright corner
//  After that we just need to reverse the numbers in each row.
//*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rownum = matrix.size();
        for (int i = 0; i < rownum; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < rownum; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};