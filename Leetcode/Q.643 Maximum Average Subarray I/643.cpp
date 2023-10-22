///*
//  We use two pointers in this question.
//  First compute the sum of the first window, and slide the window and compute the sum by subtracting the first element of the window and adding the next element of the last element of the window.
//  Compare the sum for each window and return the average pf the max one.
//*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int begin = 0;
        int end = begin + k - 1;
        int n = nums.size();
        double maxSum = 0;
        for (int i = begin; i <= end; ++i)
        {
            maxSum += nums[i];
        }

        double sum = maxSum;
        while (end != n - 1)
        {
            sum -= nums[begin++];
            sum += nums[++end];
            maxSum = max(sum, maxSum);
        }
        return maxSum / k;
    }
};