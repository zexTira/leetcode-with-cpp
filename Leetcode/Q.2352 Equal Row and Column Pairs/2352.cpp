/*//
//  In this question we define 2 hashmaps to save the eigen of each row and each column.
//  The eigen can be described as a string consisted of all elements in one row/column in sequence, with each element seperated by ','
//  We push each column and row into the column map and row map respectively, and count the number of occurance for each eigen.
//  Then we compare each eigen in two maps, if there is an eigen simultaneously occurs in two maps, we add result by the product of two times this eigen occurs in two maps.
//  Finaaly return the result.
//*/


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> col;
        unordered_map<string, int> row;

        string tempcol = "";
        string temprow = "";
        int n = grid.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                temprow += to_string(grid[i][j]);
                temprow += ",";
                tempcol += to_string(grid[j][i]);
                tempcol += ",";
            }
            row[temprow]++;
            temprow = "";
            col[tempcol]++;
            tempcol = "";
        }

        int result = 0;
        for (auto it = col.begin(); it != col.end(); ++it)
        {
            if (row.find(it->first) != row.end())
            {
                result += (col[it->first] * row[it->first]);
            }
        }
        return result;
    }
};