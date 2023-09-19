/*//
//  Convert the uint to bitstream and then convert it to string, we just need to count how many '1's in this string.
//*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bi(n);
        string str = bi.to_string();
        uint count = 0;
        for (const auto i : str)
        {
            if (i == '1')
            {
                count++;
            }
        }
        return count;
    }
};