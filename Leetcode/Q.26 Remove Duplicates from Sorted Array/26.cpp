/*//
// We need a CharMap to solve this problem(Hash Table can as well), and another pointer to modify the array.
// The basic idea is that when a number appears for the first time, record it, and reput them in this array in order.
// If a number is found appearing twice or more, just neglect it, we just need non-repeated number in this array.
// And finally record the how many non repeated numbers.
// Be attention that negative number might appear in this question, so we need a [0,256] CharMap instead, in this way we first add 128 to each num and minus 128 after operation
    to keep the index of CharMap being a positive number.
//*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<bool> charMap(256, false);
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] += 128;
            if (!charMap[nums[i]])
            {
                charMap[nums[i]] = true;
                nums[count++] = nums[i] - 128;
            }
            else
            {
                continue;
            }
        }
        return count;
    }
};