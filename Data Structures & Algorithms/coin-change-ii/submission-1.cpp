class Solution {
private:
    int f(int idx,int sum,vector<int>& arr,vector<vector<int>>& dp) {
        if(idx == 0) {
            if(sum%arr[0] == 0) return 1;
            return 0;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int nottake = f(idx-1,sum,arr,dp);
        int take = 0;
        if(arr[idx] <= sum) take += f(idx,sum-arr[idx],arr,dp);
        return dp[idx][sum] = take+nottake;
    }
public:
    int change(int k, vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(k+1,0));
        for(int sum=0;sum<=k;sum++) {
            if(sum%arr[0] == 0) dp[0][sum] = 1;
        }
        for(int idx=1;idx<n;idx++) {
            for(int sum=0;sum<=k;sum++) {
                int nottake = dp[idx-1][sum];
                int take = 0;
                if(arr[idx] <= sum) take += dp[idx][sum-arr[idx]];
                dp[idx][sum] = take+nottake;
            }
        }
        return dp[n-1][k];
    }
};
