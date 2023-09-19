/*//
//  First, we calculate the sum of each row and then push them into a new sum array;
//  Then, we record the value and their index, and sort in ascending order to sum array. Stimutaneously, we do exactly same swap operation to index array to keep corresponding relationship.
//  Finally ,we take the first k elements in index array as a result.
//*/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> sumArr;
        vector<int> indexArr;
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++)
        {
            sumArr.push_back(accumulate(mat[i].begin(), mat[i].end(), 0));
            indexArr.push_back(i);
        }

        int temp;
        for (int i = 0; i < sumArr.size(); i++)
        {
            for (int j = 0; j < sumArr.size() - 1 - i; j++)
            {
                if (sumArr[j] > sumArr[j + 1])
                {
                    temp = sumArr[j];
                    sumArr[j] = sumArr[j + 1];
                    sumArr[j + 1] = temp;
                    temp = indexArr[j];
                    indexArr[j] = indexArr[j + 1];
                    indexArr[j + 1] = temp;
                }
            }
        }

        indexArr.resize(k);
        return indexArr;
    }
};