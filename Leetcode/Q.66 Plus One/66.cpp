/*//
//  The basic idea is that add 1 to the last number of this array, then check if it's 10, if so, add one to the previous num. Keep looping until the beginning.
//  Moreover, if the beginning number equals to 10 as well, we alter it to 0 and insert one digit "1" before it.
//*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::iterator it = digits.end() - 1;
        (*it) += 1;
        while (it != digits.begin())
        {
            if ((*it) >= 10)
            {
                *it = (*it) - 10;
                *(it - 1) += 1;
            }
            it--;
        }
        if (*it == 10)
        {
            *it = 0;
            digits.insert(it, 1);
        }
        return digits;
    }
};