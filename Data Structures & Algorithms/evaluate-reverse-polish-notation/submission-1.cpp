class Solution {
public:
    int evalRPN(vector<string>& arr) {
        int ans = 0;
        stack<int> st;
        for(auto ch : arr) {
            if(ch == "+") {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                int num = num2+num1;
                st.push(num);
                continue;
            }
            else if(ch == "-") {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                int num = num2-num1;
                st.push(num);
                continue;
            }
            else if(ch == "*") {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                int num = num1*num2;
                st.push(num);
                continue;
            }
            else if(ch == "/"){
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                int num = num2/num1;
                st.push(num);
                continue;
            }
            int num = stoi(ch);
            st.push(num);
        }
        return st.top();
    }
};
