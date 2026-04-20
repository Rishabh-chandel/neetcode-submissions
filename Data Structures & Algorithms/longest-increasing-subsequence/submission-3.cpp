class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        int maxi = 1;
        vector<int> dp(n,1);
        for(int idx=0;idx<n;idx++) {
            for(int prev=0;prev<idx;prev++) {
                if(arr[prev] < arr[idx]) {
                    dp[idx] = max(dp[idx],1+dp[prev]);
                }
                maxi = max(maxi,dp[idx]);
            }
        }
        return maxi;
    }
};
