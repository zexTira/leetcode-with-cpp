/*//
//  All we do is convert the uint to bitstream and then string, then just reverse the string and convert it back.
//*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bi(n);
        string str = bi.to_string();
        reverse(str.begin(), str.end());
        bitset<32> b2(str);
        return b2.to_ullong();
    }
};