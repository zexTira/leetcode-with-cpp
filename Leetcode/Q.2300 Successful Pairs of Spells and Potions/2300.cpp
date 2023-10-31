/*//
//  Just a conventional binary search way, but we need to sort potions array first, then find the position of ceiling int of the result of success divides each spell.
//  Use the lower_bound to find the last postion where element is smaller than that int, and the count would be size minus position index.
//  Push the result of each loop into ans and return.
//*/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        vector<int> ans;
        sort(potions.begin(), potions.end());

        for (int i : spells)
        {
            int pos = lower_bound(potions.begin(), potions.end(), ceil((double)success / i)) - potions.begin();
            ans.push_back(n - pos);
        }
        return ans;
    }
};