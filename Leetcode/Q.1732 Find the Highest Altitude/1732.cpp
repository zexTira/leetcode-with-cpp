/*//
//  In this question we just need to define the current altitude, and add each element in gain array to it in sequence, and find the max one.
//*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int currAltitude = 0;
        for (int i = 0; i < gain.size(); ++i)
        {
            currAltitude += gain[i];
            maxAltitude = max(maxAltitude, currAltitude);
        }
        return maxAltitude;
    }
};