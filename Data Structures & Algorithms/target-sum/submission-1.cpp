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
        vector<vector<int>> dp(n+1,vector<int>(2001,-1));
        return f(n - 1, 0, arr, k,dp);
    }
};