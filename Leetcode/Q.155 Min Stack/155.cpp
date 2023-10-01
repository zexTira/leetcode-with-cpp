/*//
//  In this question we implement a customized stack with almost the same operation as a conventional stack does, except that it is required to update the minimum value when pushing, popping or getting the top.
//  So in these 3 operations we need to do a trick, if current value is smaller than minimum value, we push 2*currVal- minVal into the stack instead of strightly push it, and update minVal by its initial value. 
      By doing this we can set a criterion which is the number be pushed into the stack can be always smaller than current minVal.
      (It's a math problem, which can be described as if currVal<minVal, then currVal-minVal<0, and 2*currVal-minVal<currVal, and we need to have the result type been long long in case overflowing) 
//  When we do popping, that criterion is necessary, we compare the top element and the minimum value, if the result meets the criterion, we pop it up and restore the second minimum value 
      by reversely calculate that expression.
//  And when we need the top element, just check if it is smaller than minimum Value, if so we return its value source minVal, otherwise return itself.
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
            st.push((long long)2 * val - minVal);   // topVal = 2 * currVal - prevval 
            minVal = val;       // minVal = currVal
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
            minVal = 2 * minVal - popped;   // preval= 2 * currVal - topVal
        }
    }

    int top() {
        return (st.top() < minVal) ? minVal : st.top();
    }

    int getMin() {
        return minVal;
    }
};