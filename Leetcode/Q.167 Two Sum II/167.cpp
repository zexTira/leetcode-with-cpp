/*//
//  Is this question the array is sorted, so we can put a two-pointer in this array, at beginning  and end respectively, and move to the mid.
//  The bound can be defined as lpointer < rpointer, in this way if sum is bigger than target, we need to lower it by left move the r pointer, otherwise enlarge it by by right move the l pointer.
//  If we can find the sum of two num is exactly the target, return the indexs of these two num, otherwise return a null array.
//*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sum;
        for (int i = 0, j = numbers.size() - 1; i < j;)
        {
            sum = numbers[i] + numbers[j];
            if (sum == target)
            {
                return { i + 1, j + 1 };
            }
            else if (sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return {};
    }
};