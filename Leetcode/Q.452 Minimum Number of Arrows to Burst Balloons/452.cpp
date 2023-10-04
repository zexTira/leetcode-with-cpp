/*//
//  In this question we need a multimap to store each interval.
//  Then we use two pointers to indicate boundaries, and two object indicating minimum right boundary and maximum left boundary. If overlap happens we add one to the count if overlap happens, 
      then to the next intervals until the end.
//*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        multimap<int, int> mp;
        for (auto it : points)
        {
            mp.insert({ it[0],it[1] });
        }
        auto a = mp.begin(); a++;
        int xmin = (mp.begin())->first, xmax = (mp.begin())->second, c = 1;
        for (a; a != mp.end(); a++)
        {
            if (a->first <= xmax)
            {
                xmax = min(a->second, xmax);
                xmin = max(a->first, xmin);
            }
            else
            {
                c++;
                xmax = a->second;
                xmin = a->first;
            }
        }
        return c;
    }
};