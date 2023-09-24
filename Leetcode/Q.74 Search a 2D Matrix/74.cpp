/*//
//  In this question we do binary search twice in row dimension and column dimension of the matrix respectively, and aussume that the matrix owns m cols and n rows, 
     time comlexity will be O(log(m))+ O(log(n))=O(log(m*n)), which meets the requirement of this question.
// First we do binary search on row dimension, except for the conventional procedure, after we locate which row target lies in, we need to check if the target is out of boundary, if so return false.
//  Then we do it again on col dimension, but first we need to check if numbers at two boundaty is the target, as it will not be checked during normal search.
//  In this way, every time when we reset three pointers, boundary still need to be checked.
//  When or before the search ends, if we have found the target, return true, else return false.
//*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowbeg = 0;
        int rowend = matrix.size() - 1;
        int rowmid = rowbeg + (rowend - rowbeg) / 2;

        while (rowbeg < rowend)
        {
            if (matrix[rowmid][0] > target)
            {
                rowend = rowmid - 1;
                rowmid = rowbeg + (rowend - rowbeg) / 2;
            }
            else if (matrix[rowmid][matrix[rowmid].size() - 1] < target)
            {
                rowbeg = rowmid + 1;
                rowmid = rowbeg + (rowend - rowbeg) / 2;
            }
            else
            {
                break;
            }
        }
        if (target < matrix[rowmid][0] ||
            target > matrix[rowmid][matrix[rowmid].size() - 1])
        {
            return false;
        }

        int colbeg = 0;
        int colend = matrix[rowmid].size() - 1;
        int colmid = colbeg + (colend - colbeg) / 2;

        if (matrix[rowmid][colbeg] == target || matrix[rowmid][colend] == target)
        {
            return true;
        }
        while (colbeg < colend)
        {
            if (matrix[rowmid][colbeg] == target || matrix[rowmid][colend] == target)
            {
                return true;
            }
            if (matrix[rowmid][colmid] > target)
            {
                colend = colmid - 1;
                colmid = colbeg + (colend - colbeg) / 2;
            }
            else if (matrix[rowmid][colmid] < target)
            {
                colbeg = colmid + 1;
                colmid = colbeg + (colend - colbeg) / 2;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};