/*//
//		Judge if a char occurs in this string, if so, record the length of substring, restore the bool array, move strat pointer to the position i at, until finishing loop.
//*/


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())
		{
			return 0;
		}
		int result = 0;
		int start = 0;
		std::vector<bool> chars_in_substring(256, false);
		for (int i = 0; i < s.size(); ++i)
		{
			while (chars_in_substring[s[i]])
			{
				chars_in_substring[s[start++]] = false;
			}
			chars_in_substring[s[i]] = true;
			result = std::max(result, i - start + 1);
		}
		return result;
	}
};