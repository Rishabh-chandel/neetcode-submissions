class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        vector<int> pre(n,1);
        vector<int> suf(n,1);
        for(int i=1;i<n;i++) {
            pre[i] = pre[i-1]*arr[i-1];
        }
        for(int i=n-2;i>=0;i--) {
            suf[i] = suf[i+1]*arr[i+1];
        }
        for(int i=0;i<n;i++) {
            ans[i] = pre[i]*suf[i];
        }
        return ans;
    }
};
