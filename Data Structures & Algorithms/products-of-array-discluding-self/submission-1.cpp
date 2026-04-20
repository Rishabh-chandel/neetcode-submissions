class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,1);
        for(int i=1;i<n;i++) {
            ans[i] = ans[i-1]*arr[i-1];
        }
        int prod = 1;
        for(int i=n-1;i>=0;i--) {
            ans[i] = ans[i]*prod;
            prod = prod*arr[i];
        }
        return ans;
    }
};
