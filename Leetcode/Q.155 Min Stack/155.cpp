/*//
// First we check if the size of two arrays are identical, if not directly return false.
//  Next we do conventional binary search, but here the target is the number located at the end position in each loop, to ensure that number at mid will be always smaller than that at end.
     Finally if we cannot find the number till the last loop, mid will be at the only potision, where is the smallest value.
//  And we need to check if the number at mid is the smallest number by comparing it to the previous one, in case we miss the result during the loop.
//*/

class MinStack {
private:
    stack <long long> st;
    long long minVal;
public:
    MinStack() {

    }

    void push(int val) {
        if (st.empty())
        {
            st.push(val);
            minVal = val;
        }
        else if (val < minVal)
        {
            st.push((long long)2 * val - minVal);
            minVal = val;
        }
        else
        {
            st.push(val);
        }
    }

    void pop() {
        long long popped = st.top();
        st.pop();
        if (popped < minVal)
        {
            minVal = 2 * minVal - popped;
        }
    }

    int top() {
        return (st.top() < minVal) ? minVal : st.top();
    }

    int getMin() {
        return minVal;
    }
};