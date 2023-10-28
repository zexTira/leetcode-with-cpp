/*//
//  In this question we implement a priority queue storing the sum of numbers from two vector and the position pair consisted of their indices.
//  First we push the first pair to the heap, and for next k-1 times, we push non-visited pair to the array and pop the minimum pair to the result using feature of heap.
//*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> res;
        set<pair<int, int>> visi;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> minHeap;
        minHeap.push({ nums1[0] + nums2[0], {0, 0} });
        visi.insert({ 0, 0 });

        while (k-- && !minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();
            int i = top.second.first;
            int j = top.second.second;

            res.push_back({ nums1[i], nums2[j] });

            if (i + 1 < m && visi.find({ i + 1, j }) == visi.end())
            {
                minHeap.push({ nums1[i + 1] + nums2[j], {i + 1, j} });
                visi.insert({ i + 1, j });
            }

            if (j + 1 < n && visi.find({ i, j + 1 }) == visi.end())
            {
                minHeap.push({ nums1[i] + nums2[j + 1], {i, j + 1} });
                visi.insert({ i, j + 1 });
            }
        }
        return res;
    }
};