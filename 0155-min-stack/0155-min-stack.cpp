class MinStack {
public:
    stack<long long> st;
    long long min;
    MinStack() {
        min=LLONG_MAX;
    }
    
    void push(int val) {
        long long x=(long long)val;
        if(st.size()==0){
            st.push(x);
            min=x;
        }
        else if(x>=min)st.push(x);
        else{
            st.push(2*x-min);
            min=x;
        }
    }
    
    void pop() {
        if(st.top()<min){
            long long oldVal=2*min-st.top();
            min=oldVal;
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<min) return (int)min;
        else return (int)st.top();
    }
    
    int getMin() {
        return (int)min;
        
    }
};

/**
 How It Works?
Instead of using an extra stack, we encode the previous minimum value when pushing a new minimum.
If val is smaller than minVal, we push 2 * val - minVal onto the stack and update minVal.
When popping, if the top element is smaller than minVal, we retrieve the previous minimum using minVal = 2 * minVal - top().
This method ensures O(1) space complexity because it avoids an extra stack.
 */