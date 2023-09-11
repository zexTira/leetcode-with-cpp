///*
//  In this question nums2 represents the shorter array, while nums1 is the longer one.
//  We should finish this job by 3 pointers, and on a reversed order, from the end of the array to the beginning.
//  Keep comparing the two correspondent numbers pointed by two pointers, if one is bigger, place it into the end of the first array, then move the pointer towards left.
//  After reaching the beginning of the nums2, the loop process is over.
//  *Moreover, you can just simply merge two arrays and sort it in ascending order, while the time comlexity is higher.
//*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
    }
};