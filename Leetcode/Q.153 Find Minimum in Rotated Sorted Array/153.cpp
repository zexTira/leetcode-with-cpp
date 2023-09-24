/*//
// First we check if the size of two arrays are identical, if not directly return false.
//  Next we do conventional binary search, but here the target is the number located at the end position in each loop, to ensure that number at mid will be always smaller than that at end.
     Finally if we cannot find the number till the last loop, mid will be at the only potision, where is the smallest value.
//  And we need to check if the number at mid is the smallest number by comparing it to the previous one, in case we miss the result during the loop.
//*/

int findMin(vector<int>& nums) {
    if (nums.size() == 1)
    {
        return nums[0];
    }

    int beg = 0;
    int end = nums.size() - 1;
    int mid = beg + (end - beg) / 2;

    while (beg < end)
    {
        if (mid != 0)
        {
            if (nums[mid] < nums[mid - 1])
            {
                return nums[mid];
            }
        }
        if (nums[mid] < nums[end])
        {
            end = mid - 1;
            mid = beg + (end - beg) / 2;
        }
        else if (nums[mid] > nums[end])
        {
            beg = mid + 1;
            mid = beg + (end - beg) / 2;
        }
    }
    return nums[mid];
}
};