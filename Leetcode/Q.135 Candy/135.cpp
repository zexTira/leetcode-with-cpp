/*//
//  Greedy is a typical algorithm to solve this question.
//  For an element in this array, we need to consider both sides to get the final answer.
//  First, each element should get at least 1 candy, so we initialize a result array whose elements are all 1.
//  Next, we check the left side of each element, if the rating of its left neighbor is smaller than its, we add the sum of its left neighbor and 1 to current element, to ensure higher rating elemnts get more candies.
//  Then it's turn for the rught side. The way is almost the same as previous step, but after adjusting once we need to fix some elements to ensure the principal established in previous step. 
      so the candy num should be the bigger one of current num and the candy num for next element plus one.
//  Finally, calculate the accumulation of result array.
//*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        std::vector<int> candies(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int totalCandies = accumulate(candies.begin(), candies.end(), 0);

        return totalCandies;
    }
};