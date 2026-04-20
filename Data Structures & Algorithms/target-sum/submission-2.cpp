class Solution {
private:
    int f(int idx,int sum,vector<int>& arr,int k,vector<vector<int>>& dp) {
        if(idx < 0) {
            if(k == sum) return 1;
            return 0; 
        }
        if(dp[idx][sum+1000] != -1) return dp[idx][sum+1000];
        int add = f(idx-1,sum+arr[idx],arr,k,dp);
        int sub = f(idx-1,sum-arr[idx],arr,k,dp);
        return dp[idx][sum+1000] = add+sub;
    }
public:
    int findTargetSumWays(vector<int>& arr, int k) {
        int n = arr.size();
        int offset = 1000;
        vector<vector<int>> dp(n+1,vector<int>(2001,0));
        dp[0][offset] = 1;
        for(int idx=1;idx<=n;idx++) {
            for(int sum=-1000;sum<=1000;sum++) {
                dp[idx][sum + arr[idx-1] + offset] += dp[idx-1][sum + offset];
                dp[idx][sum - arr[idx-1] + offset] += dp[idx-1][sum + offset];
            }
        }
        if(k < -1000 || k > 1000) return 0;
        return dp[n][k + offset];
    }
};