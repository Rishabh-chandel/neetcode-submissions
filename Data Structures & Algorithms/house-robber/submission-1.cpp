class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++) {
            int take = arr[i];
            if(i-2 >= 0) take += dp[i-2];
            int nottake = 0;
            if(i-1 >= 0) nottake += dp[i-1];
            dp[i] = max(take,nottake);
        }
        return dp[n-1];
    }
};
