/*//
//  The way to get this question done is that keep finding the minimal point of stock value, and looking for a point to get maximum propit.
//  Let me explain the Algorithm with an example.
//  Assume that s="ABCDEFGHIJKLMNO" , and numRows=4, its zigzag conversion would be like
    A           G            M
    B       F  H        L  N
    C   E      I    K       O
    D           J
// We can see that a zigzag loop is consisted by 6 chars, which is A-F, G-L..., and the way to calculate the loopnum is 2*numRows-2
//  Therefore, for every row, we need to do the modulus, in the firt row, the indexs of char are calculated by i%loopnum==0 or loopnum-0
//  In the second row, the indexs will be i%loopnum==1 or loopnum-1.... until we reach the last row. 
//  In this way, We push every char to a new string in order.
//  *Exceptionally, if numRows=1, we can just return s directly, as any changes won't happen after conversion.
//*/


class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1)
        {
            return s;
        }
        int loopnum = 2 * numRows - 2;
        string result;

        for (int j = 0; j < numRows; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (i % loopnum == j || i % loopnum == loopnum - j)
                {
                    result += s[i];
                }
            }
        }
        return result;
    }
};