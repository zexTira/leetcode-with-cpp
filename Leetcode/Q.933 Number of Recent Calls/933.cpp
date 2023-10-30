/*//
//  In this question we just need to implement a queue, for each input ping we push it into the queue and update the current minimum ping by subtracting it by 3000.
//  Then we check the queue, pop all pings smaller than current minimum ping, and return the size of queue.
//*/

class RecentCounter {
private:
    queue<int> calls;
    int minTime;
public:
    RecentCounter() {
        minTime = 0;
    }

    int ping(int t) {
        calls.push(t);
        minTime = t - 3000;
        while (calls.front() < minTime)
        {
            calls.pop();
        }
        return calls.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */