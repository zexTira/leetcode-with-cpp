/*//
//  In this question we use number 2 and 3 to represent newly living/dead cells respectively, to meet the requirement of updating stimutaneously and avoid confusion with initially living/dead cells.
//  We first implement a function to get all living neighbors no matter thay are newly living or initially living with 8 conditions, detecting all elements at 4 corners, 4 boarders and normal positions.
//  After that we do our first update, check the number of neighbors of every element in the matrix, and have them died/lived as requirement, and remember to sigh these updated elements with 2 or 3.
//  Finally we modify all updated elements to their initial status, from 2 to 0 and 3 to 1, that's all works done. 
//*/

class Solution {
public:
    int getLiveNeighbours(vector<vector<int>>& curr, int i, int j, int m, int n) {
        int liveNeighbours = 0;
        if (i > 0)
        {
            if (curr[i - 1][j] == 1 || curr[i - 1][j] == 3)
            {
                liveNeighbours++;
            }
        }
        if (i < m - 1)
        {
            if (curr[i + 1][j] == 1 || curr[i + 1][j] == 3)
            {
                liveNeighbours++;
            }
        }
        if (j > 0)
        {
            if (curr[i][j - 1] == 1 || curr[i][j - 1] == 3)
            {
                liveNeighbours++;
            }
        }
        if (j < n - 1)
        {
            if (curr[i][j + 1] == 1 || curr[i][j + 1] == 3)
            {
                liveNeighbours++;
            }
        }
        if (i > 0 && j > 0)
        {
            if (curr[i - 1][j - 1] == 1 || curr[i - 1][j - 1] == 3)
            {
                liveNeighbours++;
            }
        }
        if (i > 0 && j < n - 1)
        {
            if (curr[i - 1][j + 1] == 1 || curr[i - 1][j + 1] == 3)
            {
                liveNeighbours++;
            }
        }
        if (i < m - 1 && j>0)
        {
            if (curr[i + 1][j - 1] == 1 || curr[i + 1][j - 1] == 3)
            {
                liveNeighbours++;
            }
        }
        if (i < m - 1 && j < n - 1)
        {
            if (curr[i + 1][j + 1] == 1 || curr[i + 1][j + 1] == 3)
            {
                liveNeighbours++;
            }
        }
        return liveNeighbours;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int ln = getLiveNeighbours(board, i, j, m, n);
                if (board[i][j] == 0)
                {
                    if (ln == 3)
                    {
                        board[i][j] = 2;
                    }
                }
                else if (board[i][j] == 1)
                {
                    if (ln < 2 || ln > 3)
                    {
                        board[i][j] = 3; 
                    }
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 2)
                {
                    board[i][j] = 1;
                }
                else if (board[i][j] == 3)
                {
                    board[i][j] = 0;
                }
            }
        }
    }
};