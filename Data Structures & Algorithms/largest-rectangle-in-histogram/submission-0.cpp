class Solution {
private:  
    int n;
    vector<int> psef(vector<int>& arr) {
        vector<int> pse(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int> nsef(vector<int>& arr) {
        vector<int> nse(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
public:
    int largestRectangleArea(vector<int>& arr) {
        n = arr.size();
        vector<int> pse = psef(arr);
        vector<int> nse = nsef(arr);
        int ans = 0;
        for(int i=0;i<n;i++) {
            int p = pse[i] , n = nse[i]; 
            ans = max(ans,(arr[i]*(n-p-1)));
        }
        return ans;
    }
};
