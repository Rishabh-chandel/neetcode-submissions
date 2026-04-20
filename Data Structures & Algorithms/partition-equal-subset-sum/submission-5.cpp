class Solution {
private:    
    bool f(int idx,int sum,vector<int>& arr,vector<vector<int>>& dp) {
        if(sum == 0) return 1;
        if(idx < 0 || sum < 0) return 0;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int nottake = f(idx-1,sum,arr,dp);
        int take = f(idx-1,sum-arr[idx],arr,dp);
        return dp[idx][sum] = take || nottake;
    }
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sumi = accumulate(arr.begin(), arr.end(), 0);
        if(sumi%2) return 0;
        int k = sumi/2;
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        for(int i=0;i<n;i++) dp[i][0] = 1;
        dp[0][arr[0]] = 1;
        for(int idx=1;idx<n;idx++) {
            for(int sum=1;sum<=k;sum++) {
                int nottake = dp[idx-1][sum];
                int take = 0;
                if(arr[idx] <= sum) take = dp[idx-1][sum-arr[idx]];
                dp[idx][sum] = take || nottake;
            }
        }
        return dp[n-1][k];
    }
};
