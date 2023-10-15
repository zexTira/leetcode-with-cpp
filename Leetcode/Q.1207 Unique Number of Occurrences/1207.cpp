/*//
//  First, we define a hashmap to store the occurance time for each number.
//  Then we check if two values of diffrent two keys are identical.
//*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> umap;
        for (auto it = arr.cbegin(); it != arr.cend(); ++it)
        {
            ++umap[*it];
        }
        for (auto it1 = umap.cbegin(); it1 != umap.cend(); ++it1)
            for (auto it2 = it1; it2 != umap.cend(); ++it2)
            {
                if (it1 != it2 && it1->second == it2->second)
                {
                    return false;
                }
            }
        return true;

    }
};