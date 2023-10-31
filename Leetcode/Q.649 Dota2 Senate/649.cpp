///*
//  We create two queues representing team Dire and team Radiant respectively.
// Going throughount the array, push the indices number of each R and D into Radiant queue and Dire queue in sequence.
// Then constantly compare the top element of the queue, pick the member with smaller index up as winner, repush it into its queue with index plus 1 to the current index(end of array), and pop both top elemnts.
// When a queue becomes empty, stop the loop and the team which the non-empty queue represents wins. 
//*/

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant;
        queue<int> dire;
        int count = 0;
        for (count = 0; count < senate.size(); ++count)
        {
            if (senate[count] == 'R')
            {
                radiant.push(count);
            }
            else
            {
                dire.push(count);
            }
        }

        while (!radiant.empty() && !dire.empty())
        {
            if (radiant.front() < dire.front())
            {
                dire.pop();
                radiant.pop();
                radiant.push(++count);
            }
            else
            {
                radiant.pop();
                dire.pop();
                dire.push(++count);
            }
        }

        if (radiant.empty())
        {
            return "Dire";
        }
        else
        {
            return "Radiant";
        }
    }
};