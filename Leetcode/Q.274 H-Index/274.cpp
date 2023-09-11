/*//
//  You need to define a h value increasing from 0 to reach the correct point.
// for each H value, calculate how many elements are larger than H value, when the quantity is larger than H, just stop the loop.
// And the real H value will be H-1.
//*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h;
        int n = citations.size();
        int count = 0;
        for (h = 0;; h++)
        {
            for (int i = 0; i < n; i++)
            {
                if (citations[i] >= h)
                {
                    count++;
                }
            }
            if (count < h)
            {
                break;
            }
            count = 0;
        }
        return (h - 1);
    }
};