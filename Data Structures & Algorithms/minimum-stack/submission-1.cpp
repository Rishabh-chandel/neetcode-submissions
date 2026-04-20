class MinStack {
private:
    long long mini;
    stack<long long> st;
public:
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        long long longVal = static_cast<long long>(val);
        if (st.empty()) {
            mini = longVal;
            st.push(longVal);
        } 
        else {
            if (longVal > mini) {
                st.push(longVal);
            } else {
                st.push(2 * longVal - mini);
                mini = longVal;
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        long long dat = st.top();
        st.pop();
        if (dat < mini) {
            mini = 2 * mini - dat;
        }
    }
    
    int top() {
        long long dat = st.top();
        if (mini < dat) return static_cast<int>(dat);
        return static_cast<int>(mini); 
    }
    
    int getMin() {
        return static_cast<int>(mini);
    }
};
