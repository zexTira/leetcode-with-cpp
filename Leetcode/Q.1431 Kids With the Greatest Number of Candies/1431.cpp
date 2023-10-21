/*//
//  First, we find the maximum value in this array.
//  Then for rach element we add number of extra candies on it, if it's bigger than or equal to the max value, we push true into the array.
//  Else push false. Finally return the bool array.
//*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxCandies = 0;

        for (int i = 0; i < candies.size(); ++i)
        {
            maxCandies = max(candies[i], maxCandies);
        }
        for (int i = 0; i < candies.size(); ++i)
        {
            if (candies[i] + extraCandies >= maxCandies)
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }

        return result;
    }
};