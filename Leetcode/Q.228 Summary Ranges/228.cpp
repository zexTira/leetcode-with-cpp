/*//
//  First if the array size is equal to 1, directly push the sole element into result array.
//  Next, we use two pointers to indicate an interval, and we need to check the bound of an interval by only one pointer of two, if the difference of two consecutive elements is bigger than 1, here the interval is.
//  When we find the interval, campare the position of two pointers, if the position is the same, which means that we have only one element between the intervals, just convert it to string and output;
// Otherwise there would be multiple nums between two intervals, we can easily find the beginning and end of this num array by two pointers and output them by the form with arrow.
//  Then we just need to reset the pointers to next position and start looping till the end.
//  Notice that we set the end position of nums array as an interval to output the last num segmentation
//*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        auto it1 = nums.begin();
        auto it2 = it1;
        bool isInterval = false;

        if (nums.size() == 1)
        {
            result.push_back(to_string(nums[0]));
            return result;
        }

        while (it1 != nums.end())
        {
            if ((it1 != nums.end() - 1) && (*(it1 + 1) == *it1 + 1))
            {
                it1++;
            }
            else
            {
                isInterval = true;
            }

            if (isInterval)
            {
                isInterval = false;
                if (it1 == it2)
                {
                    result.push_back(to_string(*it2));
                }
                else
                {
                    result.push_back(to_string(*it2) + "->" + to_string(*it1));
                }
                it1++;
                it2 = it1;
            }
        }
        return result;